#include "lib/bmc/bmc_concurrency.h"

char bmc_concur_pass::ID = 0;

bmc_concur_pass::bmc_concur_pass( options& o_, solver_context& ctx_, bmc& b_)
  : bmc_pass(o_,ctx_,b_), translate_specs(), llvm::FunctionPass(ID)
{}



bmc_concur_pass::~bmc_concur_pass() {}


llvm::StringRef bmc_concur_pass::getPassName() const {
  return "Constructs BMC formula for a concurrent program";
}


bool bmc_concur_pass::runOnFunction( llvm::Function &f ) {
//bool EntryFnFound = false;
  std::string fname = demangle(f.getName().str());
 // if (o.check_spec) {
  unsigned j = 0;
  for (;j < bmc_obj.threads.size(); j++) {
    thread_name = bmc_obj.threads.at(j).name;
    EntryFn = bmc_obj.threads.at(j).entry_function;
    if (fname != EntryFn) continue;
  }
  if( j == bmc_obj.threads.size() ) return false;

//		  EntryFnFound = true;
//		}
//    	}
//  }
//  else {
//	if (fname != o.funcName) {
//	   return false;
//    	}
//	else { EntryFnFound = true; }
//  }

//  if (EntryFnFound) {

  // collect all the declared arrays in the function
  populate_array_name_map(&f);

  bmc_fun *bmc_fun_ptr = new bmc_fun(o, ary_to_int, bmc_obj.m_model); // local
  assert(bmc_fun_ptr);
  bmc_ds_ptr = bmc_fun_ptr;                 // set the pointer in base class
  auto pair = std::make_pair( &f, bmc_fun_ptr);
  bmc_obj.get_func_formula_map().insert( pair );

  collect_loop_backedges(this, bmc_fun_ptr->loop_ignore_edges,
                         bmc_fun_ptr->rev_loop_ignore_edges);
  bmc_fun_ptr->bb_vec.clear();
  computeTopologicalOrder(f, bmc_fun_ptr->rev_loop_ignore_edges,
                          bmc_fun_ptr->bb_vec, bmc_fun_ptr->block_to_id);
  bmc_fun_ptr->eb = &f.getEntryBlock();
  bmc_fun_ptr->setup_prevs_non_repeating();


  bmc_ds_ptr->init_array_model( o.ar_model );

  bmc_ds_ptr->thread_id = bmc_obj.threads.at(j).thread_num;

  translateParams(f);
  //translate pre condition here <<---
  //bmc_obj.m_model.print();

  translatePrecond(bmc_obj, bmc_ds_ptr, o.solver_ctx);

  for (unsigned l = 0; l < bmc_obj.threads.at(j).period; l++) {
    do_bmc();

    unsigned bidx = 0;
    for( const bb* src : bmc_ds_ptr->bb_vec ) {
      for( auto it = src->begin(), e = src->end(); it != e; ++it) {
        auto I = &(*it);
        //I->print( llvm::outs() );     std::cout << "\n";
        if (llvm::isa<llvm::ReturnInst>(I)) {
          translatePostcond(bmc_obj, bmc_ds_ptr, o.solver_ctx, bidx);
        }
      }
      bidx++;
    }
  }
 //  }
 // }
  //do_bmc(); // todo: why? delete if not needed.
  //translate post condition here
  if( o.verbosity > 10 ) {
    // Print collected events events here
  }
  // Add code for stiching the events, when both are processes
  return false;
}


void bmc_concur_pass::getAnalysisUsage(llvm::AnalysisUsage &au) const {
  au.setPreservesAll();
  au.addRequired<llvm::LoopInfoWrapperPass>();
}


/* void bmc_concur_pass::translatePrecond( bmc& b ) {
  std::vector<std::string> glb_names;
  for (unsigned k = 0; k < b.threads.size(); k++) { 
   for (unsigned i = 0; i < b.threads.at(k).pres.size(); i++) {
  //for(unsigned i = 0; i < b.precond.size(); i++) {
    //if (i -> first == thread_name) {
    expr e = b.threads.at(k).pres.at(i);
    //expr e = b.precond.at(i);
    //std::cout << "Precond is " << to_string(e) << "\n";
    std::string orig_precond = to_string(e);
    glb_names = read_variables(orig_precond);
    //std::cout << "size is " << glb_names.size(); 
    for (unsigned j = 0; j < glb_names.size(); j++) {
      //std::cout << "glb_name1 is " << glb_names.at(j) << "\n";
      std::string var_name = glb_names.at(j);
      for( auto glb_idx_pair : bmc_obj.m_model.ind_in_mem_state ) {
        auto g = glb_idx_pair.first;
        auto idx = glb_idx_pair.second;
        const std::string gvar = (std::string)(g->getName());
        //std::cout << "glb_name2 is " << gvar << "\n";
        if (gvar == var_name) {
          //std::cout << "glb_name is " << gvar << " Index is " << idx << "\n";
          std::vector<state_obj>& mem_st = bmc_obj.m_model.store_state_map[0].mem_state_vec;
          //std::cout << "Init name is ";
          //mem_st[idx].print(); std::cout << "\n";
          var_name = '@'+ var_name;
          const size_t oldSize = var_name.length();
          std::string init_name = to_string(mem_st[idx].e);
          if (find(precond_var_names.begin(), precond_var_names.end(), init_name) == precond_var_names.end()) {
          precond_var_names.push_back(init_name);
          if (mem_st[idx].t.type.is_fpa()) {
            precond_declarations.push_back(o.solver_ctx.fpa_const(init_name.c_str(),8,24));
            std::string init_name1 = init_name + ".";
            precond_var_names.push_back(init_name1);
            precond_declarations.push_back(o.solver_ctx.fpa_const(init_name1.c_str(),8,24));
          }
          if (mem_st[idx].t.type.is_bv()) {
            precond_declarations.push_back(o.solver_ctx.bv_const(init_name.c_str(),16));
            std::string init_name1 = init_name + ".";
            precond_var_names.push_back(init_name1);
            precond_declarations.push_back(o.solver_ctx.bv_const(init_name1.c_str(),16));
          }
	 }
          const size_t newSize = init_name.length();
          for( size_t pos = 0; ; pos += newSize ) {
            // Locate the substring to replace
            pos = orig_precond.find( var_name, pos );
            if( oldSize == newSize ) {
              // if they're same size, use std::string::replace
              orig_precond.replace( pos, oldSize, init_name );
              break;
            } else {
              // if not same size, replace by erasing and inserting
              orig_precond.erase( pos, oldSize );
              orig_precond.insert( pos, init_name );
              //std::cout << "New precond is " << orig_precond << "\n";
              break;
            }
          }
          break;
        }
      }	    
    }
    expr e1 = parseFormula(o.solver_ctx, orig_precond, precond_var_names, precond_declarations);
    //std::cout << "Modified precond is " << e1 << "\n";
    //b.precond.at(i) = e1;
    bmc_ds_ptr->add_pre_cond( e1, spec_reason_t::ASSUME );
   //}
  }
 }
  glb_names.clear();
  precond_var_names.clear();
  precond_declarations.clear();
}


void bmc_concur_pass::translatePostcond( bmc& b, unsigned bidx ) {
  // ary_to_int[llvmValue] -> get an index

  std::vector<std::string> glb_names;
 for (unsigned k = 0; k < b.threads.size(); k++) { 
  for (unsigned i = 0; i < b.threads.at(k).posts.size(); i++) {
  //for(unsigned i = 0; i < b.prop.size(); i++) {
    //if (i -> first == thread_name) {
    expr e = b.threads.at(k).posts.at(i);
    //expr e = b.prop.at(i);
    //std::cout << "Postcond is " << to_string(e) << " Block num is " << bidx << "\n";
    std::string orig_postcond = to_string(e);
    glb_names = read_variables(orig_postcond);
    //std::cout << "size is " << glb_names.size(); 
    for (unsigned j = 0; j < glb_names.size(); j++) {
      //std::cout << "glb_name1 is " << glb_names.at(j) << "\n";
      std::string init_name; 
      std::string var_name = glb_names.at(j);
      std::string var_name1 = '@'+ var_name;
      const size_t oldSize = var_name1.length();
      for( auto glb_idx_pair : bmc_obj.m_model.ind_in_mem_state ) {
        auto g = glb_idx_pair.first;
        auto idx = glb_idx_pair.second;
        const std::string gvar = (std::string)(g->getName());
        //std::cout << "glb_name2 is " << gvar << "\n";
        if (gvar == var_name) {
          //std::cout << "glb_name is " << gvar << " Index is " << idx << "\n";
          //auto it = bmc_obj.m_model.store_state_map.end();
          //it--;
          //auto key1 = it->first;
          std::vector<state_obj>& mem_st = bmc_obj.m_model.store_state_map[bidx].mem_state_vec;
          //std::cout << "Init name is ";
          //mem_st[idx].print(); std::cout << " key is " << key1 << "\n";
          var_name = '@'+ var_name;
          //oldSize = var_name.length();
          init_name = to_string(mem_st[idx].e);
          //std::cout << "Init name is " << init_name << "\n";
	 if (find(postcond_var_names.begin(), postcond_var_names.end(), init_name) == postcond_var_names.end()) {
          postcond_var_names.push_back(init_name);
          if (mem_st[idx].t.type.is_fpa()) {
            postcond_declarations.push_back(o.solver_ctx.fpa_const(init_name.c_str(),8,24));
            std::string init_name1 = init_name + ".";
            postcond_var_names.push_back(init_name1);
            postcond_declarations.push_back(o.solver_ctx.fpa_const(init_name1.c_str(),8,24));
          }
          if (mem_st[idx].t.type.is_bv()) {
            postcond_declarations.push_back(o.solver_ctx.bv_const(init_name.c_str(),16));
            std::string init_name1 = init_name + ".";
            postcond_var_names.push_back(init_name1);
            postcond_declarations.push_back(o.solver_ctx.bv_const(init_name1.c_str(),16));
          }
	 }
          const size_t newSize = init_name.length();
          for( size_t pos = 0; ; pos += newSize ) {
            // Locate the substring to replace
            pos = orig_postcond.find( var_name, pos );
            if( oldSize == newSize ) {
              // if they're same size, use std::string::replace
              orig_postcond.replace( pos, oldSize, init_name );
              break;
            } else {
              // if not same size, replace by erasing and inserting
              orig_postcond.erase( pos, oldSize );
              orig_postcond.insert( pos, init_name );
              //std::cout << "New postcond is " << orig_postcond << "\n";
              break;
            }
          }
          break;
        }
      }

     for(unsigned m=0; m < bmc_ds_ptr->ar_model_full.ar_names.size(); m++) {
        auto a_var = bmc_ds_ptr->ar_model_full.ar_names.at(m);
        //std::cout << "Array name is " << a_var <<  " Var name is " << var_name <<"\n";
         if (a_var == var_name) {
          //std::cout << "Array_name is " << a_var << " Index is " << m << "\n";
	  unsigned e_size = bmc_ds_ptr->ar_model_full.exit_ary_map.size(); 
	  //std::cout << "Exit_ary_map size is " << e_size << "\n";
	  auto& s_names = bmc_ds_ptr->ar_model_full.exit_ary_map[e_size-1].get_name_vec(); // get the last state
  	  unsigned ar_size = s_names.size();
	  //std::cout << "Name vec size is " << ar_size << "\n";
	  for( unsigned k=0; k < ar_size; k++ ) {
    	//std::cout << "Array in map is " << to_string(s_names.at(k)) << "\n";		
         }
                    
          var_name = '@'+ var_name;
          //oldSize = var_name.length();
          init_name = to_string(s_names.at(m));
          //std::cout << "Init name is " << init_name << "\n";
	  sort s = bmc_ds_ptr->ar_model_full.ar_sorts.at(m);
	  //std::cout << "Sort1 is " << s << "\n";
	  if (find(postcond_var_names.begin(), postcond_var_names.end(), init_name) == postcond_var_names.end()) {
            postcond_var_names.push_back(init_name);
            postcond_declarations.push_back(o.solver_ctx.constant( init_name.c_str(), s ));
            std::string init_name1 = init_name + ".";
            postcond_var_names.push_back(init_name1);
            postcond_declarations.push_back(o.solver_ctx.constant(init_name1.c_str(),s));
	 }
          const size_t newSize = init_name.length();
          for( size_t pos = 0; ; pos += newSize ) {
            // Locate the substring to replace
            pos = orig_postcond.find( var_name, pos );
            if( oldSize == newSize ) {
              // if they're same size, use std::string::replace
              orig_postcond.replace( pos, oldSize, init_name );
              break;
            } else {
              // if not same size, replace by erasing and inserting
              orig_postcond.erase( pos, oldSize );
              orig_postcond.insert( pos, init_name );
              //std::cout << "New postcond is " << orig_postcond << "\n";
              break;
            }
          } 
          break; 
        } 
      }
     }
    expr e1 = parseFormula(o.solver_ctx, orig_postcond, postcond_var_names, postcond_declarations);
    //std::cout << "Modified postcond is " << to_string(e1) << "\n";
    //b.prop.at(i) = e1;
    expr path_bit = bmc_ds_ptr->get_path_bit(bidx);
    bmc_ds_ptr->add_spec( !path_bit || e1, spec_reason_t::SPEC_FILE );
    glb_names.clear();
    postcond_var_names.clear();
    postcond_declarations.clear();
   //}
  }
 }
}



std::vector<std::string> bmc_concur_pass::read_variables( std::string word1 ) {
   //std::cout << "Word1 is " << word1 << "\n";
   global_vars.clear();
   std::string word = " ";
   int i,j,k,n = 0;
   bool global_found = false;
   for(i = 0; word1[i] != '\0'; i++)
    {
        if (word1[i] == '@')
        {
	    //std::cout << "i is " << i << "\n";
            global_found = true;
        }
	if (global_found) {
	  k = 0; n = i+1;
	  for (j = i; word1[j] != ' '; j++) {
	     //std::cout << " k is " << k << "\n";
 	     //word[k] = word1[j];
     	     k++;
	     if (word1[j] == ')') {
		k--;
		break; }
          }
	 i = j;
	 word = word1.substr(n, k-1);
	 global_vars.push_back(word);
	 //std::cout << " word is " << word << " k is " << k << "\n";
	 global_found = false;
	 word = " ";
	 k = 0;
        }
    }
   return global_vars;
} */



// -- run do_bmc for all the threads.

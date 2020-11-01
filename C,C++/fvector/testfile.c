
// #########################################################
// === File #14 of 15 : testfile.c =========================
// ------------------- C++ code : BEGIN --------------------

// ==============================================================
//
//  Copyright (c) 1999, 2001 by Alex Vinokur.  This work and all works
//  derived from it may be copied and modified without any
//  restrictions other than that a copy of this copyright notice
//  must be included in any copy of this work or any derived work.
//
// ==============================================================
// #########################################################
// ## mailto:alexvn@bigfoot.com, mailto:alexv@hitechclub.com
// ## http://up.to/alexv, http://go.to/alexv_math
// #########################################################
// ==============================================================


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : testfile.c
//
//  DESCRIPTION :
//         Definition of test class	
//         Implementation of test functions
//	   --------------------------------------------------
//         - BBB
//         - vect_test1_show ()
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################



//===================
#include "testfile.h"
//===================

//================================================
DEF_TRACE_H(testfile)
DEF_TRACE_C(testfile)
#define LOCATION_IN_testfilec DEF_ARGS_C(testfile)
//================================================

//======================================
//================ CLASS ===============
//================= BBB ================
//======================================
class BBB
{
  public :
    BBB () {}
    ~BBB () {}
    ClassVeryFlexibleVector<int> tc_v1_from_class;
    ClassVeryFlexibleVector<int, LOCATION_IN_testfilec> tc_v2_from_class;
};

//===================================
void vect_test1_show ()
{
ClassVeryFlexibleVector<int>	tc_v1_simple;
ClassVeryFlexibleVector<int, LOCATION_IN_testfilec> tc_v2_simple;

BBB     bbb;
CCC     ccc;

  tc_v1_simple.hardAssign (ClassVeryFlexibleVector<int> (-29, LOCATION));
  tc_v2_simple.hardAssign (ClassVeryFlexibleVector<int> (9, 11, 250, LOCATION));
  
  bbb.tc_v1_from_class.hardAssign (ClassVeryFlexibleVector<int> (100, LOCATION));
  bbb.tc_v2_from_class.hardAssign (ClassVeryFlexibleVector<int> (-3, 7, 227, LOCATION));

  ccc.th_v1_from_class.hardAssign (ClassVeryFlexibleVector<int> (90, LOCATION));
  ccc.th_v2_from_class.hardAssign (ClassVeryFlexibleVector<int> (11, 19, 527, LOCATION));

  SHOW_THIS_VECTOR (tc_v1_simple, "Before update");
  SHOW_THIS_VECTOR (tc_v2_simple, "Before update");

  SHOW_THIS_VECTOR (bbb.tc_v1_from_class, "Before update");
  SHOW_THIS_VECTOR (bbb.tc_v2_from_class, "Before update");

  SHOW_THIS_VECTOR (ccc.th_v1_from_class, "Before update");
  SHOW_THIS_VECTOR (ccc.th_v2_from_class, "Before update");

}

//################################################################
//#                          END OF FILE                         # 
//################################################################

// ------------------- C++ code : END ----------------------
// === File #14 of 15 : testfile.c =========================

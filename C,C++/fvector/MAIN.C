
// #########################################################
// === File #15 of 15 : main.c =============================
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
//  FILE     : main.c
//
//  DESCRIPTION :
//	   --------------------------------------------------
//         Definition of test class	
//         Implementation of test functions
//	   --------------------------------------------------
//         - AAA
//         - vect_test2_valid ()
//         - vect_test3_invalid ()
//         - matr_test1_show ()
//         - matr_test2_valid ()
//         - matr_test3_invalid ()
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################

//===================
#include "fx_vect2.h"
#include "fx_matr2.h"
#include "testfile.h"
//===================

//========================================
DEF_TRACE_C(main)
#define LOCATION_IN_mainc DEF_ARGS_C(main)
//========================================

//======================================
//================ CLASS ===============
//================= AAA ================
//======================================
class AAA
{
  public :
    AAA () {}
    ~AAA () {}
    ClassVeryFlexibleVector<int> mc_v1_from_class;
    ClassVeryFlexibleVector<int, LOCATION_IN_mainc> mc_v2_from_class;
    ClassVeryFlexibleVector<int, LOCATION_IN_mainc> mc_v3_from_class;
    ClassVeryFlexibleVector<int, LOCATION_IN_mainc> mc_v4_from_class;
};

//===================================
ClassVeryFlexibleVector<int, LOCATION_IN_mainc>	mc_v1_simple;
ClassVeryFlexibleVector<int>			mc_v2_simple;

ClassFlexibleMatrix<int>	mc_m1_simple;
ClassFlexibleMatrix<int>	mc_m2_simple (-5, 123, LOCATION);
ClassFlexibleMatrix<int>	mc_m3_simple (-17, -11, -2, 0, 567, LOCATION);

AAA     aaa;

//===================================
void vect_test2_valid ()
{
ClassVeryFlexibleVector<int>	mc_v3_simple (12, LOCATION);
ClassVeryFlexibleVector<int>	mc_v4_simple (-3, 2, 27, LOCATION);
ClassVeryFlexibleVector<int, LOCATION_IN_mainc>	mc_v5_simple;
ClassVeryFlexibleVector<int>	mc_v6_simple;


  mc_v5_simple.hardAssign (ClassVeryFlexibleVector<int> (-75, LOCATION));
  mc_v6_simple.hardAssign (ClassVeryFlexibleVector<int> (15, 19, 350, LOCATION));
  
  aaa.mc_v3_from_class.hardAssign (ClassVeryFlexibleVector<int> (100, LOCATION));
  aaa.mc_v4_from_class.hardAssign (ClassVeryFlexibleVector<int> (-203, -200, 927, LOCATION));

  // ------ mc_v1_simple ------
  SHOW_THIS_VECTOR (mc_v1_simple, "Before update");

  mc_v1_simple.push_back (307);
  SHOW_THIS_VECTOR (mc_v1_simple, "After update#1");

  // ------ mc_v2_simple ------
  SHOW_THIS_VECTOR (mc_v2_simple, "Before update");

  mc_v2_simple.push_back (315);
  SHOW_THIS_VECTOR (mc_v2_simple, "After update#1");

  mc_v2_simple.push_back (316);
  mc_v2_simple.push_back (317);
  SHOW_THIS_VECTOR (mc_v2_simple, "After update#2");

  mc_v2_simple [1] = 310;
  SHOW_THIS_VECTOR (mc_v2_simple, "After update#3");

  // ------ mc_v3_simple ------
  SHOW_THIS_VECTOR (mc_v3_simple, "Before update");

  mc_v3_simple.push_back (321);
  mc_v3_simple.push_back (323);
  mc_v3_simple.push_back (325);
  mc_v3_simple.push_back (327);
  SHOW_THIS_VECTOR (mc_v3_simple, "After update#1");

  mc_v3_simple [12] = 322;
  mc_v3_simple [15] = 324;
  SHOW_THIS_VECTOR (mc_v3_simple, "After update#2");

  // ------ mc_v4_simple ------
  SHOW_THIS_VECTOR (mc_v4_simple, "Before update");

  mc_v4_simple[-3] = 331;
  mc_v4_simple[-2] = 332;
  mc_v4_simple[-1] = 333;
  mc_v4_simple[0] = 334;
  mc_v4_simple[1] = 335;
  mc_v4_simple[2] = 336;
  SHOW_THIS_VECTOR (mc_v4_simple, "After update#1");

  mc_v4_simple.pop_first ();
  SHOW_THIS_VECTOR (mc_v4_simple, "After update#2");

  mc_v4_simple.pop_back ();
  SHOW_THIS_VECTOR (mc_v4_simple, "After update#3");

  // ------ mc_v5_simple ------
  SHOW_THIS_VECTOR (mc_v5_simple, "Before update");

  // ------ mc_v6_simple ------
  SHOW_THIS_VECTOR (mc_v6_simple, "Before update");


  // ------ aaa.mc_v1_from_class ------
  SHOW_THIS_VECTOR (aaa.mc_v1_from_class, "Before update");

  aaa.mc_v1_from_class.push_back (905);
  SHOW_THIS_VECTOR (aaa.mc_v1_from_class, "After update#1");


  // ------ aaa.mc_v2_from_class ------
  SHOW_THIS_VECTOR (aaa.mc_v2_from_class, "Before update");

  aaa.mc_v2_from_class.push_back (915);
  SHOW_THIS_VECTOR (aaa.mc_v2_from_class, "After update#1");

  aaa.mc_v2_from_class.push_back (916);
  aaa.mc_v2_from_class.push_back (917);
  SHOW_THIS_VECTOR (aaa.mc_v2_from_class, "After update#1");

  aaa.mc_v2_from_class [1] = 910;
  SHOW_THIS_VECTOR (aaa.mc_v2_from_class, "After update#2");

  // ------ aaa.mc_v3_from_class ------
  SHOW_THIS_VECTOR (aaa.mc_v3_from_class, "Before update");

  aaa.mc_v3_from_class.push_back (921);
  aaa.mc_v3_from_class.push_back (923);
  aaa.mc_v3_from_class.push_back (925);
  aaa.mc_v3_from_class.push_back (927);
  SHOW_THIS_VECTOR (aaa.mc_v3_from_class, "After update#1");

  aaa.mc_v3_from_class [101] = 922;
  aaa.mc_v3_from_class [102] = 924;
  SHOW_THIS_VECTOR (aaa.mc_v3_from_class, "After update#2");

  // ------ aaa.mc_v4_from_class ------
  SHOW_THIS_VECTOR (aaa.mc_v4_from_class, "Before update");

  aaa.mc_v4_from_class[-203] = 931;
  aaa.mc_v4_from_class[-202] = 932;
  aaa.mc_v4_from_class[-201] = 933;
  aaa.mc_v4_from_class[-200] = 934;
  SHOW_THIS_VECTOR (aaa.mc_v4_from_class, "After update#1");

  aaa.mc_v4_from_class.pop_first ();
  SHOW_THIS_VECTOR (aaa.mc_v4_from_class, "After update#2");

  aaa.mc_v4_from_class.pop_back ();
  SHOW_THIS_VECTOR (aaa.mc_v4_from_class, "After update#3");

}

//===================================
void vect_test3_invalid ()
{

  mc_v1_simple [-10] = 1001;
  mc_v1_simple [20] = 1002;

  mc_v2_simple [-11] = 1003;
  mc_v2_simple [21] = 1004;

  aaa.mc_v1_from_class [-12] = 1005;
  aaa.mc_v1_from_class [22] = 1006;

  aaa.mc_v2_from_class [-13] = 1007;
  aaa.mc_v2_from_class [23] = 1008;

}

//===================================
void matr_test1_show ()
{

  mc_m1_simple.hardAssign (ClassFlexibleMatrix<int> (10, 14, -3, 1, -987, LOCATION));
  mc_m2_simple.hardAssign (ClassFlexibleMatrix<int> (-7, -4, 12, 13, 531, LOCATION));

  SHOW_THIS_MATRIX (mc_m1_simple, "Before update");
  SHOW_THIS_MATRIX (mc_m2_simple, "Before update");
  SHOW_THIS_MATRIX (mc_m3_simple, "Before update");

}


//===================================
void matr_test2_valid ()
{
  mc_m2_simple [-5][12] = 101;
  SHOW_THIS_MATRIX (mc_m2_simple, "After update");
}

//===================================
void matr_test3_invalid ()
{
  mc_m3_simple.hardAssign (ClassFlexibleMatrix<int> (-9, -4, 12, 13, 555, LOCATION));
  mc_m2_simple [50][345] = 202;
}


//===================================
int main ()
{
  vect_test1_show ();
  vect_test2_valid ();
  vect_test3_invalid ();

  matr_test1_show ();
  matr_test2_valid ();
  matr_test3_invalid ();

  return 0;
}


//################################################################
//#                          END OF FILE                         # 
//################################################################

// ------------------- C++ code : END ----------------------
// === File #15 of 15 : main.c =============================


// #########################################################
// === File #8 of 15 : testfile.h ==========================
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


///////////////////////////////////////

#ifndef TESTFILE_H
#define TESTFILE_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : testfile.h
//
//  DESCRIPTION :
//         Definition of test class
//	   --------------------------------------------------
//         - CCC
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################



//===================
#include "fx_vect2.h"
#include "fx_matr2.h"
//===================

//================================================
DECL_TRACE_H(testfile)
#define LOCATION_IN_testfileh DEF_ARGS_H(testfile)
//================================================

//===============
void vect_test1_show (void);
//===============

//======================================
//================ CLASS ===============
//================= CCC ================
//======================================
class CCC
{
  public :
    CCC () {}
    ~CCC () {}
    ClassVeryFlexibleVector<int> th_v1_from_class;
    ClassVeryFlexibleVector<int, LOCATION_IN_testfileh> th_v2_from_class;
};



//################################################################

#endif

//################################################################
//#                          END OF FILE                         # 
//################################################################

// ------------------- C++ code : END ----------------------
// === File #8 of 15 : testfile.h ==========================

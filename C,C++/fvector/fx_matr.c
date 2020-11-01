
// #########################################################
// === File #13 of 15 : fx_matr.c ==========================
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
//  FILE     : fx_matr.c
//
//  DESCRIPTION :
//	   --------------------------------------------------
//         Implementation of flexible matrix (non-template) class
//	   --------------------------------------------------
//         - ClassBasicMatrix
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################

//===============================================
#include "fx_matr2.h"
//===============================================


//#################################################
unsigned long ClassBasicMatrix::countBasicMatrixConstructors_s (0);
unsigned long ClassBasicMatrix::countBasicMatrixDestructors_s (0);



///////////////////////////////////////////////////////////////////////////////
//#############################################################################
//########### PART : ClassBasicMatrix methods ###################################
//#############################################################################
///////////////////////////////////////////////////////////////////////////////



//####################################################################
// Constructor-0
ClassBasicMatrix::ClassBasicMatrix ()
{
  countBasicMatrixConstructors_s++;
} // ClassBasicMatrix::ClassBasicMatrix () 



//####################################################################
// Destructor
ClassBasicMatrix::~ClassBasicMatrix ()
{
  countBasicMatrixDestructors_s++;
} // ClassBasicMatrix::~ClassBasicMatrix () 




//####################################################################
// static
string ClassBasicMatrix :: gstrBasicMatrixAccount_S (string  msg_i)
{
string		ret_stringValue;
strstream       tmp_strstream;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :"; 
  }

  tmp_strstream << gstrAboutAccount (getTypeName<ClassBasicMatrix> (), countBasicMatrixConstructors_s, countBasicMatrixDestructors_s);

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // int ClassBasicMatrix :: gstrBasicMatrixAccount_S (...)


//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #13 of 15 : fx_matr.c ==========================

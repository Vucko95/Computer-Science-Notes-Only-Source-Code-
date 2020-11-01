
// #########################################################
// === File #12 of 15 : fx_vect.c ==========================
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
//  FILE     : fx_vect.c
//
//  DESCRIPTION :
//         Implementation of flexible vector non-template class
//	   ----------------------------------------------------
//         - ClassBasicVector
//	   ----------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//===============================================
#include "fx_vect2.h"
//===============================================


//#################################################
unsigned long ClassBasicVector::countBasicVectorConstructors_s (0);
unsigned long ClassBasicVector::countBasicVectorDestructors_s (0);


//////////////////////////////////////////////////////////////////////
//####################################################################
//########### PART : ClassBasicVector methods ########################
//####################################################################
//////////////////////////////////////////////////////////////////////



//####################################################################
// Constructor-0
ClassBasicVector::ClassBasicVector ()
{
  countBasicVectorConstructors_s++;
} // ClassBasicVector::ClassBasicVector () 



//####################################################################
// Destructor
ClassBasicVector::~ClassBasicVector ()
{
  countBasicVectorDestructors_s++;
} // ClassBasicVector::~ClassBasicVector () 




//####################################################################
// static
string ClassBasicVector :: gstrBasicVectorAccount_S (string  msg_i)
{
string		ret_stringValue;
strstream       tmp_strstream;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :"; 
  }

  tmp_strstream << gstrAboutAccount (getTypeName<ClassBasicVector> (), countBasicVectorConstructors_s, countBasicVectorDestructors_s);

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // int ClassBasicVector :: gstrBasicVectorAccount_S (...)


//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #12 of 15 : fx_vect.c ==========================

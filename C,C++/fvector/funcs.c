// #########################################################
// === File #10 of 15 : func.c =============================
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
//  FILE     : func.c
//
//  DESCRIPTION :
//         Implementation of auxiliary (non-template) functions
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//=====================
#include "funcs.h"
//=====================


//=================================================
static const char*	STR_ACCOUNT_CNS = "ACCOUNT";
//=================================================

//######################################
//############# FUNCTIONS ##############
//######################################

//======================================
string	gstrAboutAccount (
		const string& theObjectType_i, 
		long countConstructors_i, 
		long countDestructors_i
		)
//======================================
{
string		ret_stringValue;
strstream       tmp_strstream;

	tmp_strstream << STR_ACCOUNT_CNS
		      << " -> ";

	//--------------------------------
	tmp_strstream.width (20);
	tmp_strstream.fill (' ');
	tmp_strstream.setf (ios::left, ios::adjustfield);

	tmp_strstream << theObjectType_i.c_str () 
		      << " : ";

	//--------------------------------
	tmp_strstream.setf (ios::right, ios::adjustfield);

	//--------------------------------
	tmp_strstream.setf (ios::showpos);
	tmp_strstream.width (12);
	tmp_strstream << countConstructors_i; 

	tmp_strstream.unsetf (ios::showpos);
	tmp_strstream.width (12);
	tmp_strstream << (-countDestructors_i); 

	tmp_strstream << " = "; 
	tmp_strstream.width (10);
	tmp_strstream << (countConstructors_i - countDestructors_i); 

	//--------------------------------
	tmp_strstream << ends;
	ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

	//--------------------------------
	return ret_stringValue;

} // string gstrAboutAccount () 


//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #10 of 15 : func.c =============================

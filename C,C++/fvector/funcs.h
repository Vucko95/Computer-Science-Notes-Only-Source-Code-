// #########################################################
// === File #2 of 15 : func.h ==============================
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

#ifndef FUNCS_H
#define FUNCS_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : func.h
//
//  DESCRIPTION :
//         Declaration of auxiliary (non-template) functions
//         Implementation of auxiliary template functions
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//===============
#include "defs.h"
//===============


//######################################
//######### FUNCTION PROTOTYPES ########
//######################################
string	gstrAboutAccount (
		const string&	theObjectType_i, 
		long		countConstructors_i, 
		long		countDestructors_i
		);



//######################################
//######### TEMPLATE FUNCTIONS #########
//######################################
static const char* 	all_digits_CNS		= "0123456789";
static const char* 	stringTypeName_CNS	= "string";
static const char* 	intTypeName_CNS		= "int";
static const char* 	charTypeName_CNS	= "char";


//======================================
template <typename T>
bool getWellKnownTypeName (const T& t_i, string& theTypeName_o)
//======================================
{
bool ret_boolValue = false;
	//------------------------------
	theTypeName_o = string ();

	//------------------------------
	if (typeid(t_i) == typeid (string))
	{
		ret_boolValue = true;
		theTypeName_o = stringTypeName_CNS;
	}

	//------------------------------
	if (typeid(t_i) == typeid (int))
	{
		ret_boolValue = true;
		theTypeName_o = intTypeName_CNS;
	}

	//------------------------------
	if (typeid(t_i) == typeid (char))
	{
		ret_boolValue = true;
		theTypeName_o = charTypeName_CNS;
	}

	//-------------------
	return ret_boolValue;
	//-------------------

} // bool getWellKnownTypeName (const T& t_i, string& theTypeName_o)


//======================================
template <typename T>
bool getWellKnownTypeName (string& theTypeName_o)
//======================================
{
bool ret_boolValue = false;
	//------------------------------
	theTypeName_o = string ();

	//------------------------------
	if (typeid(T) == typeid (string))
	{
		ret_boolValue = true;
		theTypeName_o = stringTypeName_CNS;
	}

	//------------------------------
	if (typeid(T) == typeid (int))
	{
		ret_boolValue = true;
		theTypeName_o = intTypeName_CNS;
	}

	//------------------------------
	if (typeid(T) == typeid (char))
	{
		ret_boolValue = true;
		theTypeName_o = charTypeName_CNS;
	}

	//-------------------
	return ret_boolValue;
	//-------------------

} // bool getWellKnownTypeName (string& theTypeName_o)



//======================================
// NOTE! Don't use function getTypeName<T>() 
//       to build this function getTypeName(t)
template <typename T>
string getTypeName (const T& t_i)
//======================================
{
string	ret_stringValue;
	//------------------------------
	if (!(getWellKnownTypeName (t_i, ret_stringValue))) 
	{
		ret_stringValue = typeid(t_i).name ();
		ret_stringValue = ret_stringValue.substr (ret_stringValue.find_first_not_of (all_digits_CNS));
	}
	//------------------------------

	return ret_stringValue;
};

//======================================
// NOTE! Don't use function getTypeName (t) 
//         to build this function getTypeName<T>()
template <typename T>
string getTypeName ()
//======================================
{
string	ret_stringValue;
	//------------------------------
	if (!(getWellKnownTypeName<T> (ret_stringValue))) 
	{
		ret_stringValue = typeid(T).name ();
		ret_stringValue = ret_stringValue.substr (ret_stringValue.find_first_not_of (all_digits_CNS));
	}
	//------------------------------
	return ret_stringValue;
};


//################################################################

#endif

//################################################################
//#                          END OF FILE                         # 
//################################################################



// ------------------- C++ code : END ----------------------
// === File #2 of 15 : func.h ==============================

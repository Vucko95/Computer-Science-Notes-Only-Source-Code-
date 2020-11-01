
// #########################################################
// === File #1 of 15 : defs.h ==============================
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

#ifndef DEFS_H
#define DEFS_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : defs.h
//
//  DESCRIPTION :
//         Macro definition
//         Declaration of extern variables
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//=====================
#include <stdio.h>
#include <errno.h>
#include <assert.h>

#include <string>
#include <vector>
#include <strstream>
#include <typeinfo>
#include <iomanip.h>
//=====================

//=========================
#define FROM_WHERE		\
		"["		\
		<< __FILE__	\
		<< ", #"	\
		<< __LINE__	\
		<< "] ---> "


#define BUG_MESSAGE(x)		cout 	\
		<< "\t###################################"	\
		<< endl	 		\
		<< "\t   "		\
		<< FROM_WHERE		\
		<< "BUG#"		\
		<< (++bugs_counter)	\
		<< endl	 		\
		<< "\t###################################"	\
		<< "" x

//=========================
#define ASSERT(x)		assert (x)
//=========================

#define DECLARATION_IN_SOURCE	__LINE__, theFILE_Indicator, theDATE_Indicator, theTIME_Indicator

#define		MAXSIZE_FILE_NAME_CNS	256
#define		NotIndicated_CNS	"NotIndicated"
#define		eqline1_CNS		"======================================================================= "

//---------------------------------
extern unsigned long	show_counter;
extern unsigned long	bugs_counter;

//---------------------------------
extern char 	theNotIndicatedFILE_Indicator [];
extern char 	theNotIndicatedDATE_Indicator [];
extern char 	theNotIndicatedTIME_Indicator [];
//---------------------------------

//######################################
//############### DEFINES ##############
//######## INSTESD OF FUNCTIONS ########
//######################################

#define	MAX_VALUE(x,y)	((x) > (y) ? (x) : (y))
#define	MIN_VALUE(x,y)	((x) < (y) ? (x) : (y))

#define GET_BELOW_ENUM(ename)	UNDEF_##ename
#define GET_ABOVE_ENUM(ename)	LAST_##ename
#define GET_MIN_ENUM(ename)	(GET_BELOW_ENUM(ename) + 1)
#define GET_MAX_ENUM(ename)	(GET_ABOVE_ENUM(ename) - 1)
#define GET_ENUM_SIZE(ename)	(GET_MAX_ENUM(ename) - GET_MIN_ENUM(ename) + 1)
#define GET_ENUM_INTERNAL_INDEX(ename, externalIndex)	(externalIndex - GET_MIN_ENUM(ename))

#define SHOW_VECTOR(msg)	showVector(__FILE__, __LINE__, msg)

#define SHOW_THIS_VECTOR(x, y)	\
	x.showVector(__FILE__, __LINE__, "-- Vector "#x" -> "##y)

#define SHOW_THIS_MATRIX(x, y)	\
	x.showMatrix(__FILE__, __LINE__, "-- Matrix "#x" -> "##y)

//######################################
//############### DEFINES ##############
//############### MACROS  ##############
//######################################

//--------------------------------------
#define	DECL_EXT_VARS_H(x)  		\
	extern char x##h_FILE[];	\
	extern char x##h_DATE[];	\
	extern char x##h_TIME[];


//--------------------------------------
#define	DEF_EXT_VARS_H(x)  		\
	char x##h_FILE[MAXSIZE_FILE_NAME_CNS];	\
	char x##h_DATE[MAXSIZE_FILE_NAME_CNS];	\
	char x##h_TIME[MAXSIZE_FILE_NAME_CNS];

//--------------------------------------
#define	DEF_VARS_C(x)  		\
	char x##c_FILE[] = __FILE__;	\
	char x##c_DATE[] = __DATE__;	\
	char x##c_TIME[] = __TIME__;


//--------------------------------------
#define DECL_INDICATOR_H(x)	\
	class x##Indicator	\
	{			\
		public :	\
			x##Indicator ()		\
			{			\
				strcpy (x##h_FILE, __FILE__);	\
				strcpy (x##h_DATE, __DATE__);	\
				strcpy (x##h_TIME, __TIME__);	\
			}	\
	};


//--------------------------------------
#define DEF_INDICATOR_H(x)		\
	static x##Indicator	dummy;

//--------------------------------------
#define	DECL_TRACE_H(x)	       		\
		DECL_EXT_VARS_H(x)	\
		DECL_INDICATOR_H(x)

//--------------------------------------
#define	DEF_TRACE_H(x)	 		\
		DEF_EXT_VARS_H(x)	\
		DEF_INDICATOR_H(x)

//--------------------------------------
#define	DEF_TRACE_C(x)	 		\
		DEF_VARS_C(x)

//--------------------------------------
#define	DEF_ARGS_H(x)    	\
		__LINE__,	\
		x##h_FILE,	\
		x##h_DATE,	\
		x##h_TIME

//--------------------------------------
#define	DEF_ARGS_C(x)    	\
		__LINE__,	\
		x##c_FILE,	\
		x##c_DATE,	\
		x##c_TIME

//################################################################

#endif	

//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #1 of 15 : defs.h ==============================


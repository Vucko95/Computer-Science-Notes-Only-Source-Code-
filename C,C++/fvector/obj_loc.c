
// #########################################################
// === File #11 of 15 : obj_loc.c ==========================
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
//  FILE     : obj_loc.c
//
//  DESCRIPTION :
//         Implementation of auxiliary class
//	   --------------------------------------------------
//         - ObjectLocation
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//==================
#include "obj_loc.h"
//==================


//##############################################
//=================== static ===================

unsigned long ObjectLocation::countObjectLocationConstructors_s (0);
unsigned long ObjectLocation::countObjectLocationDestructors_s (0);



//======================================
string ObjectLocation::gstrObjectLocationShow (string msg_i) const
//======================================
{
string          ret_stringValue;
strstream 	tmp_strstream;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :" 
                  << endl;
  }


  //======================================================
  //================= borning Description ================
  //======================================================
  tmp_strstream << endl
                << "\t"
                << "==========================================";

  for (int theIndex = GET_MIN_ENUM (ObjectBorningKind); theIndex <= GET_MAX_ENUM (ObjectBorningKind); theIndex++)
  {
    tmp_strstream << endl
                  << "\t"
                  << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"
                  << endl
	
                  << endl
                  << "\t"
                  << gstrShortObjectBorningKindName_G ((ObjectBorningKind)theIndex)
                  << " : "
	
                  << endl
                  << "\t\t"
                  << "SourceFileName "
                  << "\t\t: "
                  << getSpecificPrimaryIdentification ((ObjectBorningKind)theIndex).theSourceFileName_
	
                  << endl
                  << "\t\t"
                  << "SourceFileLineNo "
                  << "\t: "
                  << getSpecificPrimaryIdentification ((ObjectBorningKind)theIndex).theSourceFileLineNo_
	
                  << endl
                  << "\t\t"
                  << "Compilation "
                  << "\t"
                  << "\t: "
                  << getSpecificPrimaryIdentification ((ObjectBorningKind)theIndex).theSourceFileCompilationDate_
                  << "  "
                  << getSpecificPrimaryIdentification ((ObjectBorningKind)theIndex).theSourceFileCompilationTime_
	
                  << endl
                  << "\t"
                  << "\t"
                  << "--------------"
                  << endl;
  } // for (int theIndex = GET_MIN_ENUM (ObjectBorningKind)


  //======================================================
  //================= assign Description ================
  //======================================================
int	realAssignNo;

  for (int theAssignNo = 0; theAssignNo < theMatrixSecondaryIdentification_.size (); theAssignNo++)
  {
    realAssignNo = theAssignNo + 1;

    tmp_strstream << endl
                  << "\t"
                  << "==========================================";

    for (int theIndex = GET_MIN_ENUM (ObjectBorningKind); theIndex <= GET_MAX_ENUM (ObjectBorningKind); theIndex++)
    {
      tmp_strstream << endl
                    << "\t"
                    << "=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*=*"
                    << endl
		
                    << endl
                    << "\t"
                    << gstrShortObjectBorningKindName_G ((ObjectBorningKind)theIndex, 0)
                    << " (Assing#"
                    << realAssignNo
                    << ")"
                    << " : "
		
                    << endl;

      tmp_strstream << "" 
                    << "\t\t"
                    << "SourceFileName "
                    << "\t\t: "
                    << getSpecificSecondaryIdentification (theAssignNo, (ObjectBorningKind)theIndex).theSourceFileName_
		
                    << endl;

      tmp_strstream << "" 
                    << "\t\t"
                    << "SourceFileLineNo "
                    << "\t: "
                    << getSpecificSecondaryIdentification (theAssignNo, (ObjectBorningKind)theIndex).theSourceFileLineNo_
		
                    << endl;

      tmp_strstream << "" 
                    << "\t\t"
                    << "Compilation "
                    << "\t"
                    << "\t: "
                    << getSpecificSecondaryIdentification (theAssignNo, (ObjectBorningKind)theIndex).theSourceFileCompilationDate_
                    << "  "
                    << getSpecificSecondaryIdentification (theAssignNo, (ObjectBorningKind)theIndex).theSourceFileCompilationTime_
		
                    << endl
                    << "\t"
                    << "\t"
                    << "--------------"
                    << endl;
    } // for (int theIndex = GET_MIN_ENUM (ObjectBorningKind)
  } // for (int theAssignNo = 0; theAssignNo < theMatrixS

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // string ObjectLocation::gstrObjectLocationShow 



//======================================
// static
string ObjectLocation :: gstrObjectLocationAccount_S (string  msg_i)
//======================================
{
string		ret_stringValue;
strstream       tmp_strstream;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :"; 
  }

  tmp_strstream << gstrAboutAccount (getTypeName<ObjectLocation> (), countObjectLocationConstructors_s, countObjectLocationDestructors_s);

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // int ObjectLocation :: gstrObjectLocationAccount_S (...)





//////////////////////////////////////////////////////
//####################################################
//################## PART Functions ##################
//####################################################
//////////////////////////////////////////////////////




//======================================
string gstrObjectBorningKindName_G (
		ObjectBorningKind theObjectBorningKind_i, 
		int width_i
		)
//======================================
{
string			ret_stringValue;
static vector<string>	names;
static int 		maxWordLen = 0;

  if (names.empty ())
  {
    string	tmp_string;
    for (int index = 0; index < LAST_ObjectBorningKind; index++)
    {
      //tmp_string = "UNDEFINED_ObjectBorningKind_Name#" + IntToDecStr (index);
      tmp_string = "UNDEFINED_ObjectBorningKind_Name#_???";
      names.push_back (tmp_string);
    } // for (int index = 0; index < LAST_ObjectBorningKind; index++)

    ASSERT (UNDEF_ObjectBorningKind >= 0);
    names [UNDEF_ObjectBorningKind] = "";
    names [DeclarationInitKind] = "DeclarationInitKind";
    names [CreationInitKind] = "CreationInitKind";

    for (int theIndex = UNDEF_ObjectBorningKind; theIndex < LAST_ObjectBorningKind; theIndex++)
    {
      maxWordLen = MAX_VALUE (maxWordLen, names[theIndex].size ());
    }
  } // if (names.empty ())

  if (width_i < 0)
  {
    width_i = maxWordLen;
  }


  ASSERT (theObjectBorningKind_i > UNDEF_ObjectBorningKind);
  ASSERT (theObjectBorningKind_i < LAST_ObjectBorningKind);

  ret_stringValue = names [theObjectBorningKind_i];

const int maxplusValue = names.size ();
  for (int theIndex = maxplusValue; theIndex <= width_i; theIndex++)
  {
    ret_stringValue += ' ';
  }

  return ret_stringValue;

} // int gstrObjectBorningKindName_G (...)




//======================================
string gstrShortObjectBorningKindName_G (
		ObjectBorningKind theObjectBorningKind_i, 
		int width_i
		)
//======================================
{
string			ret_stringValue;
static vector<string>	names;
static int 		maxWordLen = 0;

  if (names.empty ())
  {
    string	tmp_string;
    for (int index = 0; index < LAST_ObjectBorningKind; index++)
    {
      //tmp_string = "ShortUNDEFINED_ObjectBorningKind_Name#" + IntToDecStr (index);
      tmp_string = "ShortUNDEFINED_ObjectBorningKind_Name#_???";
      names.push_back (tmp_string);
    } // for (int index = 0; index < LAST_ObjectBorningKind; index++)

    ASSERT (UNDEF_ObjectBorningKind >= 0);
    names [UNDEF_ObjectBorningKind] = "";
    names [DeclarationInitKind] = "Declaration";
    names [CreationInitKind] = "Creation";

    for (int theIndex = UNDEF_ObjectBorningKind; theIndex < LAST_ObjectBorningKind; theIndex++)
    {
      maxWordLen = MAX_VALUE (maxWordLen, names[theIndex].size ());
    }
  } // if (names.empty ())

  if (width_i < 0)
  {
    width_i = maxWordLen;
  }

  ASSERT (theObjectBorningKind_i > UNDEF_ObjectBorningKind);
  ASSERT (theObjectBorningKind_i < LAST_ObjectBorningKind);

  ret_stringValue = names [theObjectBorningKind_i];

const int maxplusValue = names.size ();
  for (int theIndex = maxplusValue; theIndex <= width_i; theIndex++)
  {
    ret_stringValue += ' ';
  }

  return ret_stringValue;

} // int gstrShortObjectBorningKindName_G (...)



//################################################################
//#                          END OF FILE                         # 
//################################################################

// ------------------- C++ code : END ----------------------
// === File #11 of 15 : obj_loc.c ==========================

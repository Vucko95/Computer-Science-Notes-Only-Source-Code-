
// #########################################################
// === File #3 of 15 : obj_loc.h ===========================
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

#ifndef OBJ_LOC_H
#define OBJ_LOC_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : obj_loc.h
//
//  DESCRIPTION :
//         Definition and implementation of auxiliary classes
//	   --------------------------------------------------
//         - ObjectIdentification
//         - ObjectLocation
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//================
#include "funcs.h"
//================

//------------------------------------------------------------
#define LOCATION	__FILE__, __LINE__, __DATE__, __TIME__
//------------------------------------------------------------

//----------------------------------------
static const char*	None_CNS = "None";
//----------------------------------------

//====================
enum ObjectBorningKind
//====================
{
	UNDEF_ObjectBorningKind,
	DeclarationInitKind,
	CreationInitKind,
	LAST_ObjectBorningKind
};
string 		gstrObjectBorningKindName_G (
			ObjectBorningKind theObjectBorningKind_i, 
			int width_i = -1
			);
string 		gstrShortObjectBorningKindName_G (
			ObjectBorningKind theObjectBorningKind_i, 
			int width_i = -1
			);


//===================
class ObjectLocation;
//===================

//========================
class ObjectIdentification
//========================
{
friend ObjectLocation;

  public :
    string	theSourceFileName_;
    int		theSourceFileLineNo_;
    string	theSourceFileCompilationDate_;
    string	theSourceFileCompilationTime_;

    // Constructor-0
    ObjectIdentification () {}

    // Constructor-1
    ObjectIdentification (
	const string&	theSourceFileName_i,
	int		theSourceFileLineNo_i,
	const string&	theSourceFileCompilationDate_i,
	const string&	theSourceFileCompilationTime_i
	)
    {
      setIdentification (theSourceFileName_i, theSourceFileLineNo_i, theSourceFileCompilationDate_i, theSourceFileCompilationTime_i);
    }

    // Destructor
    ~ObjectIdentification () {}

    void setIdentification (
	const string&	theSourceFileName_i,
	int		theSourceFileLineNo_i,
	const string&	theSourceFileCompilationDate_i,
	const string&	theSourceFileCompilationTime_i
	)
    {
      theSourceFileName_		= theSourceFileName_i;
      theSourceFileLineNo_		= theSourceFileLineNo_i;
      theSourceFileCompilationDate_	= theSourceFileCompilationDate_i;
      theSourceFileCompilationTime_	= theSourceFileCompilationTime_i;
    }

};

//==================
class ObjectLocation
//==================
{
  protected:
    static unsigned long	countObjectLocationConstructors_s;
    static unsigned long	countObjectLocationDestructors_s;

    vector<ObjectIdentification>		theVectorPrimaryIdentification_;
    vector < vector<ObjectIdentification> >	theMatrixSecondaryIdentification_;

    vector<ObjectIdentification>	getVectorPrimaryIdentification () const
    {
      return theVectorPrimaryIdentification_;
    }

    ObjectIdentification	getSpecificPrimaryIdentification (
					ObjectBorningKind externalIndex_i
					) const
    {
      ASSERT (externalIndex_i >= GET_MIN_ENUM (ObjectBorningKind));
      ASSERT (externalIndex_i <= GET_MAX_ENUM (ObjectBorningKind));

      int internalIndex = GET_ENUM_INTERNAL_INDEX (ObjectBorningKind, externalIndex_i);
      ASSERT (internalIndex >= 0);
      ASSERT (internalIndex < GET_ENUM_SIZE (ObjectBorningKind));

      return theVectorPrimaryIdentification_ [internalIndex];
    }

    ObjectIdentification	getSpecificSecondaryIdentification (
					int		  theAssingNo_i,
					ObjectBorningKind externalIndex_i
					) const
    {
      ASSERT (externalIndex_i >= GET_MIN_ENUM (ObjectBorningKind));
      ASSERT (externalIndex_i <= GET_MAX_ENUM (ObjectBorningKind));

      int internalIndex = GET_ENUM_INTERNAL_INDEX (ObjectBorningKind, externalIndex_i);
      ASSERT (internalIndex >= 0);
      ASSERT (internalIndex < GET_ENUM_SIZE (ObjectBorningKind));

      ASSERT (theAssingNo_i >= 0);
      ASSERT (theAssingNo_i < theMatrixSecondaryIdentification_.size ());

      return theMatrixSecondaryIdentification_ [theAssingNo_i] [internalIndex];
    }

    void		setSpecificPrimaryIdentification (
				ObjectBorningKind		externalIndex_i, 
				const ObjectIdentification&	theInstance_i
				)
    {
      ASSERT (externalIndex_i >= GET_MIN_ENUM (ObjectBorningKind));
      ASSERT (externalIndex_i <= GET_MAX_ENUM (ObjectBorningKind));

      int internalIndex = GET_ENUM_INTERNAL_INDEX (ObjectBorningKind, externalIndex_i);
      ASSERT (internalIndex >= 0);
      ASSERT (internalIndex < GET_ENUM_SIZE (ObjectBorningKind));

      theVectorPrimaryIdentification_ [internalIndex] = theInstance_i;
    }

    void		addSpecificSecondaryIdentification (
				ObjectBorningKind		externalIndex_i, 
				const ObjectIdentification&	theInstance_i
					)
    {
      ASSERT (externalIndex_i >= GET_MIN_ENUM (ObjectBorningKind));
      ASSERT (externalIndex_i <= GET_MAX_ENUM (ObjectBorningKind));

      int internalIndex = GET_ENUM_INTERNAL_INDEX (ObjectBorningKind, externalIndex_i);
      ASSERT (internalIndex >= 0);
      ASSERT (internalIndex < GET_ENUM_SIZE (ObjectBorningKind));

      theVectorPrimaryIdentification_ [internalIndex] = theInstance_i;
    }


    void		addAllSecondaryIdentifications (
				const ObjectIdentification&	theInstance_i
				)
    {
      for (int theIndex = GET_MIN_ENUM (ObjectBorningKind); 
               theIndex <= GET_MAX_ENUM (ObjectBorningKind); 
               theIndex++)
      {
        addSpecificSecondaryIdentification (
		(ObjectBorningKind) theIndex,
		theInstance_i
		);
      }
    } 


    void		addAllSecondaryIdentifications (
				const ObjectLocation&	theInstance_i
				)
    {
      theMatrixSecondaryIdentification_.push_back (theInstance_i.getVectorPrimaryIdentification ());
    } 


  public:
    // Constructor-0
    ObjectLocation ()
    {
      countObjectLocationConstructors_s++;
      theVectorPrimaryIdentification_ = vector<ObjectIdentification> (
						GET_ENUM_SIZE (ObjectBorningKind), 
						ObjectIdentification (
							None_CNS, 
							0, 
							None_CNS,
							None_CNS
							));

    } // Constructor-0

    // Constructor-1
    ObjectLocation (
		const string 	fileName_i, 
		const int	lineNo_i, 
		const string	compilationDate_i, 
		const string	compilationTime_i
		)
    {
      countObjectLocationConstructors_s++;
      theVectorPrimaryIdentification_ = vector<ObjectIdentification> (
						GET_ENUM_SIZE (ObjectBorningKind), 
						ObjectIdentification (
							None_CNS, 
							0, 
							None_CNS,
							None_CNS
							));
      theVectorPrimaryIdentification_ [GET_ENUM_INTERNAL_INDEX (ObjectBorningKind, CreationInitKind)].setIdentification (
							fileName_i, 
							lineNo_i, 
							compilationDate_i, 
							compilationTime_i
							);

    }


    // Copy Constructor
    ObjectLocation (const ObjectLocation& theCopyInstance_i)
    {
      countObjectLocationConstructors_s++;
      *this = *(&theCopyInstance_i);
    }

    ~ObjectLocation ()
    {
      countObjectLocationDestructors_s++;
    }

    string 		gstrObjectLocationShow (string msg_i = "") const;
    static string	gstrObjectLocationAccount_S (string msg_i = "");
};


//################################################################

#endif

//################################################################
//#                          END OF FILE                         # 
//################################################################

// ------------------- C++ code : END ----------------------
// === File #3 of 15 : obj_loc.h ===========================

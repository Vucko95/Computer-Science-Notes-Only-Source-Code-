
// #########################################################
// === File #4 of 15 : fx_vect.h ===========================
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

#ifndef FX_VECT_H
#define FX_VECT_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : fx_vect.h
//
//  DESCRIPTION :
//         Definition of flexible vector classes
//	   --------------------------------------------------
//         - ClassBasicVector
//         - ClassFlexibleVector
//         - ClassVeryFlexibleVector
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//==================
#include "obj_loc.h"
//==================


//########################################################
#define GET_velem(v, x) v##.at(x, LOCATION)


//########################################################
//#################### ClassBasicVector ##################
//######################## Declaration ###################
//########################################################
class ClassBasicVector
{
  protected:
    ClassBasicVector ();
    virtual ~ClassBasicVector ();
    static unsigned long	countBasicVectorConstructors_s;
    static unsigned long	countBasicVectorDestructors_s;

  public:
    static string	gstrBasicVectorAccount_S (string msg_i = "");
};

//########################################################
//################## ClassFlexibleVector #################
//######################## Declaration ###################
//########################################################
template <class	T> 
class ClassFlexibleVector : public ObjectLocation, public ClassBasicVector
{
  protected:
    //--- Data ---
    ClassFlexibleVector< ClassFlexibleVector<T> >*	thePtrAboveVector_;
    int		theAboveOrdinalNumber_;

    int		minIndex_;
    vector<T>	basicUsualVector_;	
    T		dummy_element_;	

    //--- Methods ---
    int		getInternalIndex (int externalIndex_i) const;
    string	getErrorMsgAboutVectorIndexOutOfRange (
			int		externalIndex_i, 
			const string&	theFuncName_i,
			const string 	fileName_i = "", 
			const int	lineNo_i = 0, 
			const string	compilationDate_i = "", 
			const string	compilationTime_i = ""
			) const;

  public:
    // Constructor-0
    ClassFlexibleVector (); 

    // Constructor-1
    ClassFlexibleVector (
	int 		minIndex_i, 
	const string 	fileName_i, 
	const int	lineNo_i, 
	const string	compilationDate_i, 
	const string	compilationTime_i
	);

    // Constructor-2
    ClassFlexibleVector (
	int 		minIndex_i, 
	int		maxIndex_i, 
	const T&	value_i, 
	const string 	fileName_i, 
	const int	lineNo_i, 
	const string	compilationDate_i, 
	const string	compilationTime_i
	);

   // Copy Constructor
   ClassFlexibleVector (const ClassFlexibleVector& ClassFlexibleVectorInstance_i);

   // Destructor
   ~ClassFlexibleVector ();

   int     		Get_minIndex () const {return minIndex_;}
   int     		Get_maxIndex () const {return minIndex_ + basicUsualVector_.size () - 1;}
   bool			empty () const {return basicUsualVector_.empty ();}
   bool			indexBelongsToVectorRange (int externalIndex_i) const;
   int			size () const {return basicUsualVector_.size ();}
   void			push_back (const T& element_i);
   bool			pop_first ();
   bool			pop_back ();
   bool			pop_element (int externalIndex_i);

   ClassFlexibleVector 	slice (const int& minIndexSlice_i, const int& maxIndexSlice_i);
   ClassFlexibleVector&	operator= (const ClassFlexibleVector& instance_i);
   ClassFlexibleVector&	softAssign (const ClassFlexibleVector& instance_i);
   ClassFlexibleVector&	hardAssign (const ClassFlexibleVector& instance_i);

   T&			operator[] (int externalIndex_i);
   T			operator[] (int externalIndex_i) const;
   T&			at (
				int externalIndex_i,
   				const string 	fileName_i, 
   				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				);
   T			at (
				int externalIndex_i,
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				) const;

   string		gstrVElementShow (
				int	externalIndex_i,
				string	printFormat_i = "",
				int	width_i = 0
				) const;

   string		gstrVectorShow (
				char*	file_name_i, 
				int	line_no_i, 
				string	msg_i = "", 
				string	printFormat_i = "", 
				int	width_i = 0
				) const;

   void			showVector (
				char*	file_name_i, 
				int	line_no_i, 
				string	msg_i = "", 
				string	printFormat_i = "", 
				int	width_i = 0
				) const;

   string		gstrVectorList () const;

   ostream&		osprint (ostream &os) const 
   {
     os << gstrVectorShow ("This is printed by osprint"); 
     return (os);
   } 

   void			setPtrAboveVector (ClassFlexibleVector< ClassFlexibleVector<T> >* thePtrAboveVector_i)
   {
     thePtrAboveVector_ = thePtrAboveVector_i;
   }

   void			setAboveOrdinalNumber (int theAboveOrdinalNumber_i);
   int			getAboveOrdinalNumber () const;

};



//########################################################
//################ ClassVeryFlexibleVector ###############
//######################## Declaration ###################
//########################################################
template <class	T, 
	  int	this_LINE = -1, 
	  char*	this_FILE = theNotIndicatedFILE_Indicator,
	  char*	this_DATE = theNotIndicatedFILE_Indicator,
	  char*	this_TIME = theNotIndicatedFILE_Indicator
	  >
class ClassVeryFlexibleVector : public ClassFlexibleVector<T>
{
  public :
    // Constructor-0
    ClassVeryFlexibleVector (); 

    // Constructor-1
    ClassVeryFlexibleVector (
    	int 		minIndex_i, 
	const string 	fileName_i, 
        const int	lineNo_i, 
	const string	compilationDate_i, 
	const string	compilationTime_i
	);

  // Constructor-2
  ClassVeryFlexibleVector (
	int 		minIndex_i, 
	int		maxIndex_i, 
	const T&	value_i, 
	const string 	fileName_i, 
	const int	lineNo_i, 
	const string	compilationDate_i, 
	const string	compilationTime_i
	);

  // Copy Constructor
  ClassVeryFlexibleVector (const ClassVeryFlexibleVector& ClassVeryFlexibleVectorInstance_i);

  // Destructor
  ~ClassVeryFlexibleVector ();
};

//################################################################

#endif


//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #4 of 15 : fx_vect.h ===========================

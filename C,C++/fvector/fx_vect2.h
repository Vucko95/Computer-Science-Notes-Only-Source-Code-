
// #########################################################
// === File #5 of 15 : fx_vect2.h ==========================
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

#ifndef FX_VECT2_H
#define FX_VECT2_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : fx_vect2.h
//
//  DESCRIPTION :
//         Implementation of flexible vector template classes
//	   --------------------------------------------------
//         - ClassFlexibleVector
//         - ClassVeryFlexibleVector
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//===============================================
#include "fx_vect.h"
//===============================================


///////////////////////////////////////////////////////////////
//#############################################################
//#############################################################
///////////////////////////////////////////////////////////////

#define	BUG_Vector_MESSAGE(x)	BUG_MESSAGE (x)


//########################################################
//################### ClassFlexibleVector ################
//######################## Methods #######################
//########################################################

//==================
template <class	T>
inline ostream &
operator<< (ostream &os, const ClassFlexibleVector<T>& value_i)
//==================
{
  return ( value_i.osprint(os) );
}


//==================
// Constructor-0
template <class	T>
inline ClassFlexibleVector<T> :: ClassFlexibleVector() : 
					ObjectLocation (), 
					ClassBasicVector (), 
					minIndex_ (0)
//==================
{
  thePtrAboveVector_ = NULL;
  theAboveOrdinalNumber_ = INT_MIN;
} // ClassFlexibleVector :: ClassFlexibleVector()


//==================
// Constructor-1
template <class	T>
inline ClassFlexibleVector<T> :: ClassFlexibleVector(
					int 		minIndex_i, 
					const string 	fileName_i, 
					const int	lineNo_i, 
					const string	compilationDate_i, 
					const string	compilationTime_i
					) :
					  ObjectLocation (
						fileName_i, 
						lineNo_i, 
						compilationDate_i, 
						compilationTime_i), 
					  ClassBasicVector (), 
					  minIndex_ (minIndex_i)
//==================
{
  thePtrAboveVector_ = NULL;
  theAboveOrdinalNumber_ = INT_MIN;

  basicUsualVector_ = vector<T> ();
} // ClassFlexibleVector :: ClassFlexibleVector()



//==================
// Constructor-2
template <class	T>
inline ClassFlexibleVector<T> :: ClassFlexibleVector(
					int 		minIndex_i, 
					int		maxIndex_i, 
					const T&	value_i, 
					const string 	fileName_i, 
					const int	lineNo_i, 
					const string	compilationDate_i, 
					const string	compilationTime_i
					) :
					  ObjectLocation (
						fileName_i, 
						lineNo_i, 
						compilationDate_i, 
						compilationTime_i), 
					  ClassBasicVector (), 
					  minIndex_ (minIndex_i)
//==================
{
  thePtrAboveVector_ = NULL;
  theAboveOrdinalNumber_ = INT_MIN;

  if (!(minIndex_i <= maxIndex_i))
  {
    cerr << "Invalid vector range : [" 
	 << minIndex_i 
	 << "," 
	 << maxIndex_i << "]" 
	 << endl; 
    cerr << eqline1_CNS << endl;
    cerr << gstrObjectLocationShow () << endl;

    return;
    ASSERT (0);	// Currently unused
  }

  basicUsualVector_ = vector<T> (maxIndex_i - minIndex_i + 1, value_i); 
} // ClassFlexibleVector :: ClassFlexibleVector()


//==================
// Copy Constructor
template <class	T>
ClassFlexibleVector<T> :: ClassFlexibleVector(const ClassFlexibleVector& theCopyInstance_i) : 
				ClassBasicVector ()
//==================
{
  (*this).hardAssign (theCopyInstance_i);
} // ClassFlexibleVector :: ClassFlexibleVector()



//==================
// Destructor
template <class	T>
ClassFlexibleVector<T> :: ~ClassFlexibleVector() 
//==================
{
} // ClassFlexibleVector :: ~ClassFlexibleVector()


//==================
template <class	T>
bool ClassFlexibleVector<T> 
	:: indexBelongsToVectorRange (int externalIndex_i) const 
//==================
{
  return ((externalIndex_i >= Get_minIndex ()) && (externalIndex_i <= Get_maxIndex()));
} // bool ClassFlexibleVector<T> :: indexBelongsToVectorRange (int externalIndex_i) const 

//==================
template <class	T>
int ClassFlexibleVector<T> 
	:: getInternalIndex (int externalIndex_i) const 
//==================
{
  return (externalIndex_i - minIndex_);
} // int ClassFlexibleVector<T> :: getInternalIndex (int externalIndex_i) const 



//==================
template <class	T>
void ClassFlexibleVector<T> :: push_back (const T& element_i) 
//==================
{
  basicUsualVector_.push_back (element_i);
} // void ClassFlexibleVector<T> :: push_back (const T& element_i) 



//==================
template <class	T>
bool ClassFlexibleVector<T> 
	:: pop_first () 
//==================
{
  if (empty ()) return false;

  ASSERT (size () > 0);
  basicUsualVector_.erase (basicUsualVector_.begin());

  return true;
} // bool ClassFlexibleVector<T> :: pop_first (const T& element_i) 



//==================
template <class	T>
bool ClassFlexibleVector<T> 
	:: pop_back () 
//==================
{
  if (empty ()) return false;

  ASSERT (size () > 0);
  basicUsualVector_.pop_back ();

  return true;
} // bool ClassFlexibleVector<T> :: pop_back (const T& element_i) 


//==================
template <class	T>
bool ClassFlexibleVector<T> 
	:: pop_element (int externalIndex_i) 
//==================
{
int	theIndex;

  ASSERT (indexBelongsToVectorRange (externalIndex_i));

  if (empty ()) return false;

  ASSERT (size () > 0);
  basicUsualVector_.erase (basicUsualVector_.begin() + getInternalIndex (externalIndex_i));

  return true;
} // bool ClassFlexibleVector<T> :: pop_element (const T& element_i) 


//==================
template <class	T>
ClassFlexibleVector<T>& ClassFlexibleVector<T>::softAssign (const ClassFlexibleVector<T>& instance_i) 
//==================
{
  *this = instance_i;
  return *this;
} // ClassFlexibleVector<T>& ClassFlexibleVector<T> :: softAssign ... 


//==================
template <class	T>
ClassFlexibleVector<T>& ClassFlexibleVector<T> :: hardAssign (const ClassFlexibleVector<T>& instance_i) 
//==================
{
  *this = instance_i;
  minIndex_ = instance_i.minIndex_;
  return *this;
} // ClassFlexibleVector<T>& ClassFlexibleVector<T> :: hardAssign ... 



//==================
template <class	T>
inline ClassFlexibleVector<T>& ClassFlexibleVector<T> 
	:: operator= (const ClassFlexibleVector& instance_i) 
//==================
{
  if (!empty ())
  {
    if (size () != ((ClassFlexibleVector&)instance_i).size ()) 
    {
      cerr << endl << eqline1_CNS  << endl;
      cerr << "Operator= : Vectors' Sizes are not idendical : " 
           << endl 
           << "\tFirst vector holds " 
           << size () 
           << " elements; " 
           << " range is [" 
           << Get_minIndex () 
           << " : " 
           << Get_maxIndex () 
           << "]," 
           << endl 
           << "\tSecond vector holds " 
           << ((ClassFlexibleVector&)instance_i).size () 
           << " elements; " 
           << "range is [" 
           << ((ClassFlexibleVector&)instance_i).Get_minIndex () 
           << " : " 
           << ((ClassFlexibleVector&)instance_i).Get_maxIndex () 
           << "]" 
           << endl;
      cerr << eqline1_CNS << endl;

      cerr << endl 
           << "First vector : " 
           << gstrObjectLocationShow () 
           << endl;

      cerr << endl
           << "Second vector : " 
           << ((ClassFlexibleVector&)instance_i).gstrObjectLocationShow () 
           << endl;
	
       return *this;
       ASSERT (0);	// Currently unused

    } // if (size () != instance_i.size ())
  } // if (!empty ())

  //---------------------------------------
  // Not must be !!! minIndex_ = instance_i.minIndex_ ;
  basicUsualVector_ = instance_i.basicUsualVector_ ;
  //---------------------------------------

  (*this).addAllSecondaryIdentifications (instance_i);

  return *this;
} // ClassFlexibleVector<T>& ClassFlexibleVector<T>::operator= (const ClassFlexibleVector& instance_i)



//==================
template <class	T>
string ClassFlexibleVector<T> 
	::getErrorMsgAboutVectorIndexOutOfRange (
		int		externalIndex_i, 
		const string&	theFuncName_i,
		const string 	fileName_i = "", 
		const int	lineNo_i = 0, 
		const string	compilationDate_i = "", 
		const string	compilationTime_i = ""
		) const
//==================
{
string          ret_stringValue;
strstream       tmp_strstream;

  tmp_strstream << ""
                << endl 
		<< eqline1_CNS 
		<< endl
		<< "### "
		<< theFuncName_i
		<< endl;

const string theVectorOrMatrix = (getAboveOrdinalNumber () == INT_MIN) ? "Vector Element" : "Matrix Column"; 
  tmp_strstream << ""
                //<< "Vector Element (or Matrix Column) index " 
		<< theVectorOrMatrix 
		<< " index " 
		<< externalIndex_i 
                << " out of range [" 
		<< Get_minIndex () 
		<< ", " 
		<< Get_maxIndex ()
		<< "]"; 

  if (empty ())
  {
    tmp_strstream << "  (Range is Empty)"; 
  }

  tmp_strstream << endl;

  if (!(getAboveOrdinalNumber () == INT_MIN))
  {
    tmp_strstream << ""
		  << "CONCLUSION : "		
		  << "MatrixElement " 
		  << "[Row#"
		  << getAboveOrdinalNumber ()
		  << "]"
		  << " "
		  << "[Column#"
		  << externalIndex_i 
		  << "]"
		  << "  Not Existing !!!"
		  << endl;
  }
	

  tmp_strstream << eqline1_CNS 
		<< endl;


  tmp_strstream << gstrObjectLocationShow () << endl;


  if (!fileName_i.empty ())
  {
    tmp_strstream << endl;
    tmp_strstream << "\t#################################################" <<  endl;
    tmp_strstream << "\t###=========== Index Out Of Range ============###" <<  endl;
    tmp_strstream << "\t#################################################" <<  endl;
    tmp_strstream << "\t### See : " << fileName_i << ", line#" << lineNo_i << endl;
    tmp_strstream << "\t###     : (Compilation - " << compilationDate_i << ",   " << compilationTime_i << ")" << endl;
    tmp_strstream << "\t#################################################" <<  endl;
    tmp_strstream << endl;
  }

  tmp_strstream << eqline1_CNS 
	        << endl
	        << endl
	        << endl
	        << endl;


  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;
} // string ClassFlexibleVector<T>::getErrorMsgAboutVectorIndexOutOfRange



//==================
template <class	T>
T& ClassFlexibleVector<T> 
	::operator[] (int externalIndex_i)
//==================
{
  if (!(indexBelongsToVectorRange (externalIndex_i)))
  {
    BUG_Vector_MESSAGE (<< getErrorMsgAboutVectorIndexOutOfRange (externalIndex_i, __PRETTY_FUNCTION__));
    return dummy_element_;
  }

  return basicUsualVector_ [externalIndex_i - minIndex_];
} // T& ClassFlexibleVector<T>::operator[]



//==================
template <class	T>
T ClassFlexibleVector<T> 
	::operator[] (int externalIndex_i) const
//==================
{
  if (!(indexBelongsToVectorRange (externalIndex_i)))
  {
    BUG_Vector_MESSAGE (<< getErrorMsgAboutVectorIndexOutOfRange (externalIndex_i, __PRETTY_FUNCTION__));
    return dummy_element_;
  }

  return basicUsualVector_ [externalIndex_i - minIndex_];
} // T ClassFlexibleVector<T>::operator[] 







//==================
template <class	T>
T& ClassFlexibleVector<T> 
	::at (int 		externalIndex_i,
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				)
//==================
{
  if (!(indexBelongsToVectorRange (externalIndex_i)))
  {
    BUG_Vector_MESSAGE (<< getErrorMsgAboutVectorIndexOutOfRange (externalIndex_i, __PRETTY_FUNCTION__, fileName_i, lineNo_i, compilationDate_i, compilationTime_i));
    return dummy_element_;
  }

  return basicUsualVector_ [externalIndex_i - minIndex_];
} // T& ClassFlexibleVector<T>::at



//==================
template <class	T>
T ClassFlexibleVector<T> 
	::at (int externalIndex_i,
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				) const
//==================
{
  if (!(indexBelongsToVectorRange (externalIndex_i)))
  {
    BUG_Vector_MESSAGE (<< getErrorMsgAboutVectorIndexOutOfRange (externalIndex_i, __PRETTY_FUNCTION__, fileName_i, lineNo_i, compilationDate_i, compilationTime_i));
    return dummy_element_;
  }

  return basicUsualVector_ [externalIndex_i - minIndex_];
} // T ClassFlexibleVector<T>::at 



//==================
template <class	T>
string ClassFlexibleVector<T> 
	::gstrVElementShow (
			int	externalIndex_i,
			string	printFormat_i,
			int	width_i
			) const
//==================
{
string          ret_stringValue;
strstream 	tmp_strstream;

  tmp_strstream << "VectorElement [" 
                << externalIndex_i << "] = ";

  do 
  {
    //-----------------------------------
    if (printFormat_i == "dec")
    {
      tmp_strstream << dec;
      break;
    }

    //-----------------------------------
    if (printFormat_i == "hex")
    {
      tmp_strstream << hex;
      break;
    }
    //-----------------------------------
    break;

  } while (0);


  if (width_i > 0)
  {
    tmp_strstream << setw (width_i);
  }

  tmp_strstream << (*this) [externalIndex_i];


  do 
  {
    //-----------------------------------
    if (printFormat_i == "dec")
    {
      tmp_strstream << "  (dec)";
      break;
    }

    //-----------------------------------
    if (printFormat_i == "hex")
    {
      tmp_strstream << "  (hex)";
      tmp_strstream << dec;
      break;
    }

    //-----------------------------------
    break;

  } while (0);


  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);
  return ret_stringValue;

} // string ClassFlexibleVector<T>::gstrVElementShow





//==================
template <class	T>
string ClassFlexibleVector<T>::gstrVectorList () const
//==================
{
string          ret_stringValue;
strstream 	tmp_strstream;


  if (!empty ())
  {
    for (int index = Get_minIndex (); index <= Get_maxIndex (); index++)
    {
      if (index > Get_minIndex ())
      {
        tmp_strstream << ", ";
      }
      tmp_strstream << (*this) [index]; 
    }
  }
  else
  {
    tmp_strstream << " <Empty> ";
  }

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);
  return ret_stringValue;

} // string ClassFlexibleVector<T>::gstrVectorList





//==================
template <class	T>
string ClassFlexibleVector<T> 
	::gstrVectorShow (
		char*	file_name_i, 
		int	line_no_i, 
		string	msg_i, 
		string	printFormat_i, 
		int	width_i
		) const
//==================
{
string          ret_stringValue;
strstream 	tmp_strstream;


  tmp_strstream << endl 
                << "############################################################" 
                << endl 
                << "#################### ShowVector : Begin ####################"
                << endl 
                << "#################### [show#"
                << (++show_counter)
                << "] ("
                << file_name_i
                << ", #"
                << line_no_i
                << ")"
                << endl 
                << "############################################################" 
                << endl 
                << endl;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :" 
                  << endl;
  }

  if (basicUsualVector_.empty ())
  {
    ASSERT (Get_minIndex () > Get_maxIndex ());
    tmp_strstream << "\tVector is Empty; MinIndex = " 
                  << Get_minIndex () 
                  << endl;
  }
  else
  {
    ASSERT (Get_minIndex () <= Get_maxIndex ());
    tmp_strstream << "\tVector range is [" 
                  << Get_minIndex () 
                  << " : " 
                  << Get_maxIndex () << "]" 
                  << "; Total elements = "
                  << Get_maxIndex () - Get_minIndex () + 1
                  << endl;
  }
	
  tmp_strstream << gstrObjectLocationShow () << endl;
	
  for (int index = Get_minIndex (); index <= Get_maxIndex (); index++)
  {
    tmp_strstream << gstrVElementShow (index, printFormat_i, width_i) 
                  << endl;
  }

  tmp_strstream << endl 
                << "##################### ShowVector : End #####################"
                << endl 
                << endl;

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);
  return ret_stringValue;

} // string ClassFlexibleVector<T>::gstrVectorShow




//==================
template <class	T>
void ClassFlexibleVector<T> 
	:: showVector(
		char*	file_name_i, 
		int	line_no_i, 
		string	msg_i, 
		string	printFormat_i, 
		int	width_i
		) const

//==================
{
  cout << gstrVectorShow (
		file_name_i,
		line_no_i, 
		msg_i, 
		printFormat_i, 
		width_i
		) 
       << endl;
} // void ClassFlexibleVector<T> :: showVector(string msg_i, string printFormat_i, int width_i)




//==================
template <class	T>
ClassFlexibleVector<T> ClassFlexibleVector<T> 
	::slice (
		const int& minIndexSlice_i, 
		const int& maxIndexSlice_i 
		)
//==================
{

  if (!(minIndexSlice_i <= maxIndexSlice_i))
  {
    cerr << eqline1_CNS << endl;
    cerr << "Illegal Vector' Slice range : " 
         << endl 
         << "\trange of slice is [" 
         << minIndexSlice_i 
         << "-" 
         << maxIndexSlice_i 
         << "]" 
         << endl;
    cerr << eqline1_CNS << endl;

    cerr << gstrObjectLocationShow () << endl;

    return;
    ASSERT (0);	// Currently unused

  } // if ((minIndexSlice_i < Get_minIndex ()) || (maxIndexSlice_i > Get_maxIndex ()))


  if ((minIndexSlice_i < Get_minIndex ()) || (maxIndexSlice_i > Get_maxIndex ()))
  {
    cerr << eqline1_CNS << endl;
    cerr << "Vector' Slice out of range : " 
         << endl 
         << "\trange of slice is [" 
         << minIndexSlice_i 
         << "-" 
         << maxIndexSlice_i 
         << "]," 
         << endl 
         << "\trange of vector is [" 
         << Get_minIndex () 
         << "-" 
         << Get_maxIndex () 
         << "]" 
         << endl;
    cerr << eqline1_CNS << endl;

    cerr << gstrObjectLocationShow () << endl;

    return;
    ASSERT (0);	// Currently unused

  } // if ((minIndexSlice_i < Get_minIndex ()) || (maxIndexSlice_i > Get_maxIndex ()))

ClassFlexibleVector<T>	ret_ClassFlexibleVectorObject (minIndexSlice_i, LOCATION);
  for (int index = minIndexSlice_i; index <= maxIndexSlice_i; index++)
  {
    ret_ClassFlexibleVectorObject.push_back ((*this) [index]);
  }

  return ret_ClassFlexibleVectorObject;
} // ClassFlexibleVector<T> ClassFlexibleVector<T>::slice




//==================
template <class	T>
void ClassFlexibleVector<T> 
	:: setAboveOrdinalNumber(int theAboveOrdinalNumber_i)
//==================
{
  theAboveOrdinalNumber_ = theAboveOrdinalNumber_i;
} // void ClassFlexibleVector<T> :: setAboveOrdinalNumber(int theAboveOrdinalNumber_i) 



//==================
template <class	T>
int ClassFlexibleVector<T> 
	:: getAboveOrdinalNumber() const
//==================
{
  return theAboveOrdinalNumber_;
} // int ClassFlexibleVector<T> :: getAboveOrdinalNumber() 



//########################################################
//################# ClassVeryFlexibleVector ##############
//######################## Methods #######################
//########################################################

//==================
// Constructor-0
template <class	T, int this_LINE, char* this_FILE, char* this_DATE, char* this_TIME>
inline ClassVeryFlexibleVector<T, this_LINE, this_FILE, this_DATE, this_TIME>::ClassVeryFlexibleVector() : ClassFlexibleVector<T> () 
//==================
{
  (*this).setSpecificPrimaryIdentification (
		DeclarationInitKind, 
		ObjectIdentification (
			this_FILE, 
			this_LINE, 
			this_DATE, 
			this_TIME
			));
} // ClassVeryFlexibleVector :: ClassVeryFlexibleVector()


//==================
// Constructor-1
template <class	T, int this_LINE, char* this_FILE, char* this_DATE, char* this_TIME>
inline ClassVeryFlexibleVector<T, this_LINE, this_FILE, this_DATE, this_TIME>::ClassVeryFlexibleVector(
				int 		minIndex_i, 
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				) :
				  ClassFlexibleVector<T> (
					minIndex_i,
					fileName_i,
					lineNo_i,
					compilationDate_i,
					compilationTime_i
					)

//==================
{
  (*this).setSpecificPrimaryIdentification (
		DeclarationInitKind, 
		ObjectIdentification (
			this_FILE, 
			this_LINE, 
			this_DATE, 
			this_TIME
			));
} // ClassVeryFlexibleVector :: ClassVeryFlexibleVector()




//==================
// Constructor-2
template <class	T, int this_LINE, char* this_FILE, char* this_DATE, char* this_TIME>
inline ClassVeryFlexibleVector<T, this_LINE, this_FILE, this_DATE, this_TIME>::ClassVeryFlexibleVector(
				int 		minIndex_i, 
				int		maxIndex_i, 
				const T&	value_i, 
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				) :
				  ClassFlexibleVector<T> (
					minIndex_i,
					maxIndex_i,
					value_i,
					fileName_i,
					lineNo_i,
					compilationDate_i,
					compilationTime_i
					)

//==================
{
  (*this).setSpecificPrimaryIdentification (
		DeclarationInitKind, 
		ObjectIdentification (
			this_FILE, 
			this_LINE, 
			this_DATE, 
			this_TIME
			));
} // ClassVeryFlexibleVector :: ClassVeryFlexibleVector()





//==================
// Copy Constructor
template <class	T, int this_LINE, char* this_FILE, char* this_DATE, char* this_TIME>
ClassVeryFlexibleVector<T, this_LINE, this_FILE, this_DATE, this_TIME> :: ClassVeryFlexibleVector(const ClassVeryFlexibleVector& theCopyInstance_i) 
//==================
{
  (*this).hardAssign (theCopyInstance_i);
} // ClassVeryFlexibleVector :: ClassVeryFlexibleVector()



//==================
// Destructor
template <class	T, int this_LINE, char* this_FILE, char* this_DATE, char* this_TIME>
ClassVeryFlexibleVector<T, this_LINE, this_FILE, this_DATE, this_TIME> :: ~ClassVeryFlexibleVector() 
//==================
{
} // ClassVeryFlexibleVector :: ~ClassVeryFlexibleVector()



//################################################################

#endif


//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #5 of 15 : fx_vect2.h ==========================

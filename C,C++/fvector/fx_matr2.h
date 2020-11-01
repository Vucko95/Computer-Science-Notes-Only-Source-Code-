
// #########################################################
// === File #7 of 15 : fx_matr2.h ==========================
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

#ifndef FX_MATR2_H
#define FX_MATR2_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : fx_matr2.h
//
//  DESCRIPTION :
//         Implementation of flexible matrix template class
//	   --------------------------------------------------
//         - ClassFlexibleMatrix
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################


//===============================================
#include "fx_matr.h"
#include "fx_vect2.h"
//===============================================


///////////////////////////////////////////////////////////////
//#############################################################
//#############################################################
///////////////////////////////////////////////////////////////

//#############################################################
#define	BUG_Matrix_MESSAGE(x)	BUG_MESSAGE (x)


//########################################################
//################### ClassFlexibleNatrix ################
//######################## Methods #######################
//########################################################

//==================
// Constructor-0
template <class T>
ClassFlexibleMatrix<T> :: ClassFlexibleMatrix() : 
				ClassBasicMatrix (),
				rowsVector_ (), 
				emptyRow_ ()
{
  for (int rowIndex = rowsVector_.Get_minIndex (); 
           rowIndex <= rowsVector_.Get_maxIndex (); 
           rowIndex++)
  {
    rowsVector_ [rowIndex].setAboveOrdinalNumber (rowIndex);
    rowsVector_ [rowIndex].setPtrAboveVector (&rowsVector_);
  }
} // ClassFlexibleMatrix :: ClassFlexibleMatrix()



//==================
// Constructor-1
template <class T>
ClassFlexibleMatrix<T> :: ClassFlexibleMatrix(
			int 		minRowIndex_i, 
			int 		minColumnIndex_i, 
			const string 	fileName_i, 
			const int	lineNo_i, 
			const string	compilationDate_i, 
			const string	compilationTime_i
			) :
				ClassBasicMatrix (),
				rowsVector_ (
						minRowIndex_i, 
						fileName_i,
						lineNo_i,
						compilationDate_i,
						compilationTime_i
						),
				emptyRow_ (
						minColumnIndex_i, 
						fileName_i,
						lineNo_i,
						compilationDate_i,
						compilationTime_i
						)
//==================
{
  for (int rowIndex = rowsVector_.Get_minIndex (); 
           rowIndex <= rowsVector_.Get_maxIndex (); 
           rowIndex++)
  {
    rowsVector_ [rowIndex].setAboveOrdinalNumber (rowIndex);
    rowsVector_ [rowIndex].setPtrAboveVector (&rowsVector_);
  }
} // ClassFlexibleMatrix :: ClassFlexibleMatrix()




//==================
// Constructor-2
template <class T>
ClassFlexibleMatrix<T> :: ClassFlexibleMatrix(
			int 		minRowIndex_i, 
			int		maxRowIndex_i, 
			int 		minColumnIndex_i, 
			int		maxColumnIndex_i, 
			const T&	value_i, 
			const string 	fileName_i, 
			const int	lineNo_i, 
			const string	compilationDate_i, 
			const string	compilationTime_i
			) :
				ClassBasicMatrix (),
				rowsVector_ (
						minRowIndex_i, 
						maxRowIndex_i, 
						ClassFlexibleVector<T> (
							minColumnIndex_i, 
							maxColumnIndex_i, 
							value_i,
							fileName_i,
							lineNo_i,
							compilationDate_i,
							compilationTime_i
							),
						fileName_i,
						lineNo_i,
						compilationDate_i,
						compilationTime_i
						)
//==================
{
  for (int rowIndex = rowsVector_.Get_minIndex (); 
           rowIndex <= rowsVector_.Get_maxIndex (); 
           rowIndex++)
  {
    rowsVector_ [rowIndex].setAboveOrdinalNumber (rowIndex);
    rowsVector_ [rowIndex].setPtrAboveVector (&rowsVector_);
  }

} // ClassFlexibleMatrix :: ClassFlexibleMatrix()




//==================
// Copy Constructor-0
template <class T>
ClassFlexibleMatrix<T> :: ClassFlexibleMatrix(const ClassFlexibleMatrix& theCopyInstance_i) : 
				ClassBasicMatrix ()
//==================
{
  (*this).hardAssign (theCopyInstance_i);
} // ClassFlexibleMatrix :: ClassFlexibleMatrix()




//==================
template <class T>
ClassFlexibleMatrix<T> :: ~ClassFlexibleMatrix()
//==================
{
} // ClassFlexibleMatrix :: ~ClassFlexibleMatrix()




//==================
template <class T>
string ClassFlexibleMatrix<T>::gstrVectorShowMatrix (string msg_i) const
{
string          ret_stringValue;
strstream 	tmp_strstream;

  tmp_strstream << endl << "############### VectorShowMatrix : Begin ########################" << endl << endl;

  if (!msg_i.empty ())
  {
    tmp_strstream << "\t" 
                  << msg_i 
                  << " :" 
                  << endl;
  }


  tmp_strstream << rowsVector_.gstrObjectLocationShow () << endl;

  tmp_strstream << rowsVector_.gstrVectorShow ("This is Vector of Rows"); 


  tmp_strstream << endl << "############### VectorShowMatrix : End ##########################" << endl << endl;

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // string ClassFlexibleMatrix<T>::gstrVectorShowMatrix


//==================
template <class T>
string ClassFlexibleMatrix<T>::gstrMElemenShow (
							int	externalRowIndex_i, 
							int	externalColumnIndex_i,
							string	printFormat_i,
							int	width_i
							) const
//==================
{
string          ret_stringValue;
strstream 	tmp_strstream;

  tmp_strstream << "MatrixElement [" 
                << externalRowIndex_i 
                << "] [" 
                << externalColumnIndex_i
                << "] = "; 

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

  tmp_strstream << (*this) [externalRowIndex_i] [externalColumnIndex_i];

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

} // string ClassFlexibleMatrix<T>::gstrMElemenShow


//==================
template <class T>
string ClassFlexibleMatrix<T>::gstrMatrixShow (
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
                << "#################### ShowMatrix : Begin ####################"
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

  if (isRectangular ())
  {
    tmp_strstream << "\tMatrix is Rectangular"; 
  }
  else
  {
    tmp_strstream << "\tMatrix is Not Rectangular";
  }
  tmp_strstream << endl; 

  if (empty ())
  {
    tmp_strstream << "\tMatrix is Empty"; 
    if (absolutelyEmpty ())
    {
      tmp_strstream << " (Absolutely Empty !)"; 

      tmp_strstream << "; MinRowIndex = " 
                    << rowsVector_.Get_minIndex (); 
    }
    else
    {
      tmp_strstream << " (But Not Absolutely Empty !)"; 

      tmp_strstream << "; Rows range is [" 
                    << rowsVector_.Get_minIndex () 
                    << "-" 
                    << rowsVector_.Get_maxIndex ()
                    << "]"; 
    }
    tmp_strstream << "; MinColumnIndex = " 
                  << getFirstMatrixRow ().Get_minIndex () 
                  << endl;
  }
  else
  {
    //================================================
    // Only rectangular matrixes are used !!!!
    //================================================
    const int	firstRowIndex = rowsVector_.Get_minIndex ();
    for (int rowIndex = rowsVector_.Get_minIndex (); 
             rowIndex <= rowsVector_.Get_maxIndex (); 
             rowIndex++)
    {
      ASSERT (rowsVector_ [rowIndex].Get_minIndex () == rowsVector_ [firstRowIndex].Get_minIndex ()); 
      ASSERT (rowsVector_ [rowIndex].Get_maxIndex () == rowsVector_ [firstRowIndex].Get_maxIndex ()); 
    }
	
    tmp_strstream << "\tMatrix range is [" 
                  << rowsVector_.Get_minIndex () 
                  << "-" 
                  << rowsVector_.Get_maxIndex () 
                  << ", " 
                  << getFirstMatrixRow ().Get_minIndex () 
                  << "-" 
                  << getFirstMatrixRow ().Get_maxIndex () 
                  << "]" 
                  << "; Total elements = "
                  << (rowsVector_.Get_maxIndex () - rowsVector_.Get_minIndex () + 1) * (getFirstMatrixRow ().Get_maxIndex () - getFirstMatrixRow ().Get_minIndex () + 1) 
                  << endl
                  << endl;
  }
	
  tmp_strstream << rowsVector_.gstrObjectLocationShow () << endl;

  for (int rowIndex = rowsVector_.Get_minIndex (); 
           rowIndex <= rowsVector_.Get_maxIndex (); 
           rowIndex++)
  {
    for (int columnIndex = rowsVector_ [rowIndex].Get_minIndex (); 
             columnIndex <= rowsVector_ [rowIndex].Get_maxIndex (); 
             columnIndex++)
    {
      tmp_strstream << gstrMElemenShow (rowIndex, columnIndex, printFormat_i, width_i) 
                    << endl;
    } // for (int columnIndex = ...

    tmp_strstream << endl;

  } // for (int rowIndex = ...


  // --- tmp_strstream << rowsVector_.gstrVectorShow ("This is Vector of Rows"); 


  tmp_strstream << endl << "############### ShowMatrix : End ##########################" << endl << endl;

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // string ClassFlexibleMatrix<T>::gstrMatrixShow



//==================
template <class T>
void ClassFlexibleMatrix<T> :: showMatrix(
				char*	file_name_i, 
				int	line_no_i, 
				string	msg_i, 
				string	printFormat_i, 
				int	width_i
				) const
//==================
{
  cout << gstrMatrixShow (
		file_name_i, 
		line_no_i, 
		msg_i, 
		printFormat_i, 
		width_i
		) 
       << endl;

} // void ClassFlexibleMatrix<T> :: showMatrix(string msg_i, string printFormat_i, int width_i)




//==================
template <class T>
ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::operator= (const ClassFlexibleMatrix& instance_i)
//==================
{
  if (empty ())
  {
    for (int thatRowsIndex = ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_minIndex (); 
             thatRowsIndex <= ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_maxIndex (); 
             thatRowsIndex++)
    {
      emptyRow_ = ((ClassFlexibleMatrix&)instance_i).rowsVector_ [thatRowsIndex];
      rowsVector_.push_back (emptyRow_);
    }
  }
  else
  {
    if (!((totalRows () == ((ClassFlexibleMatrix&)instance_i).totalRows ()) && (totalColumns () == ((ClassFlexibleMatrix&)instance_i).totalColumns ()))) 
    {
      BUG_Matrix_MESSAGE(<< endl);

      cerr << endl 
           << "======================================================================= " 
           << endl
           << "Operator= : Matrixes' Sizes are not idendical : " << endl 
           << "\tFirst Matrix range is " 
           << " [" 
           << rowsVector_.Get_minIndex () 
           << "-" 
           << rowsVector_.Get_maxIndex ()
           << ", "
           << getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "\tSecond Matrix range is " 
           << " [" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_minIndex () 
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_maxIndex ()
           << ", "
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "======================================================================= " 
           << endl;
		
	
      cerr <<endl 
           << "First matrix : " 
           << rowsVector_.gstrObjectLocationShow () 
           << endl;
	
      cerr << endl
           << "Second matrix : " 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.gstrObjectLocationShow () 
           << endl;
	

      return *this;
      ASSERT (0);	// Currently unused
    } // if (!((totalRows () == ... 

    emptyRow_ = ((ClassFlexibleMatrix&)instance_i).emptyRow_;
    rowsVector_ = ((ClassFlexibleMatrix&)instance_i).rowsVector_;

  } // else - if (empty ())

  return *this;
} // ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::operator= (const ClassFlexibleMatrix& instance_i)



//==================
template <class T>
ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::softAssign (const ClassFlexibleMatrix& instance_i)
//==================
{
  if (empty ())
  {
    for (int thatRowsIndex = ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_minIndex (); 
             thatRowsIndex <= ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_maxIndex (); 
             thatRowsIndex++)
    {
      emptyRow_.softAssign (((ClassFlexibleMatrix&)instance_i).rowsVector_ [thatRowsIndex]);
      rowsVector_.push_back (emptyRow_);

    }
  }
  else
  {
    if (!((totalRows () == ((ClassFlexibleMatrix&)instance_i).totalRows ()) && (totalColumns () == ((ClassFlexibleMatrix&)instance_i).totalColumns ()))) 
    {
      BUG_Matrix_MESSAGE(<< endl);

      cerr << endl << "======================================================================= " 
           << endl
           << "Operator= : Matrixes' Sizes are not idendical : " << endl 
           << "\tFirst Matrix range is " 
           << " [" 
           << rowsVector_.Get_minIndex () 
           << "-" 
           << rowsVector_.Get_maxIndex ()
           << ", "
           << getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "\tSecond Matrix range is " 
           << " [" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_minIndex () 
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_maxIndex ()
           << ", "
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "======================================================================= " 
           << endl;
		
	
      cerr <<endl 
           << "First matrix : " 
           << rowsVector_.gstrObjectLocationShow () 
           << endl;
	
      cerr << endl
           << "Second matrix : " 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.gstrObjectLocationShow () 
           << endl;
	
		
      return *this;
      ASSERT (0);	// Currently unused
    } // if (!((totalRows () == ... 

    emptyRow_.softAssign (((ClassFlexibleMatrix&)instance_i).emptyRow_);
    rowsVector_.softAssign (((ClassFlexibleMatrix&)instance_i).rowsVector_);

  } // else - if (empty ())

  return *this;
} // ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::softAssign (const ClassFlexibleMatrix& instance_i)




//==================
template <class T>
ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::hardAssign (const ClassFlexibleMatrix& instance_i)
//==================
{
  if (!empty ())
  {
    if (!((totalRows () == ((ClassFlexibleMatrix&)instance_i).totalRows ()) && (totalColumns () == ((ClassFlexibleMatrix&)instance_i).totalColumns ()))) 
    {
      BUG_Matrix_MESSAGE(<< endl);
      cerr << endl << "======================================================================= " 
           << endl
           << "Operator= : Matrixes' Sizes are not idendical : " << endl 
           << "\tFirst Matrix range is " 
           << " [" 
           << rowsVector_.Get_minIndex () 
           << "-" 
           << rowsVector_.Get_maxIndex ()
           << ", "
           << getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "\tSecond Matrix range is " 
           << " [" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_minIndex () 
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.Get_maxIndex ()
           << ", "
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_minIndex ()
           << "-" 
           << ((ClassFlexibleMatrix&)instance_i).getFirstMatrixRow ().Get_maxIndex ()
           << "]" 
           << endl
           << "======================================================================= " 
           << endl;
		
	
      cerr <<endl 
           << "First matrix : " 
           << rowsVector_.gstrObjectLocationShow () 
           << endl;
	
      cerr << endl
           << "Second matrix : " 
           << ((ClassFlexibleMatrix&)instance_i).rowsVector_.gstrObjectLocationShow () 
           << endl;
	
		
      return *this;
      ASSERT (0);	// Currently unused
    } // if (!((totalRows () == ... 
  } // else - if (empty ())

  emptyRow_.hardAssign (((ClassFlexibleMatrix&)instance_i).emptyRow_);
  rowsVector_.hardAssign (((ClassFlexibleMatrix&)instance_i).rowsVector_);

  return *this;

} // ClassFlexibleMatrix<T>& ClassFlexibleMatrix<T>::hardAssign (const ClassFlexibleMatrix& instance_i)


//==================
template <class T>
string ClassFlexibleMatrix<T>::getErrorMsgAboutMatrixRowOutOfRange (
							int		externalRowIndex_i, 
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

  tmp_strstream << endl 
                << "======================================================================= " 
	        << endl
	        << "### "
	        << theFuncName_i
	        << endl
	        << "Matrix Row index " 
	        << externalRowIndex_i 
	        << " out of range [" 
	        << rowsVector_.Get_minIndex () 
	        << "," 
	        << rowsVector_.Get_maxIndex ()
	        << "]"; 

  if (empty ())
  {
    tmp_strstream << "  (Range is Empty)"; 
  }

  tmp_strstream << endl
	        << "======================================================================= " 
	        << endl;

  tmp_strstream << rowsVector_.gstrObjectLocationShow () << endl;


  if (!fileName_i.empty ())
  {
    tmp_strstream << endl;
    tmp_strstream << "\t#################################################" <<  endl;
    tmp_strstream << "\t### See : " << fileName_i << ", line#" << lineNo_i << endl;
    tmp_strstream << "\t###     : (Compilation - " << compilationDate_i << ",   " << compilationTime_i << ")" << endl;
    tmp_strstream << "\t#################################################" <<  endl;
    tmp_strstream << endl;
  }

  tmp_strstream << ends;
  ret_stringValue = tmp_strstream.str(); tmp_strstream.rdbuf()->freeze (0);

  return ret_stringValue;

} // string ClassFlexibleMatrix<T>::getErrorMsgAboutMatrixRowOutOfRange


//==================
template <class T>
ClassFlexibleVector<T>& ClassFlexibleMatrix<T>::operator[] (int externalRowIndex_i)
//==================
{

  if (!(checkExternalRowIndex (externalRowIndex_i)))
  {
    BUG_Matrix_MESSAGE (<< getErrorMsgAboutMatrixRowOutOfRange (externalRowIndex_i, __PRETTY_FUNCTION__));
    return dummy_vector_;
  }

  return rowsVector_ [externalRowIndex_i];

} // ClassFlexibleVector<T>& ClassFlexibleMatrix<T>::operator[] (int externalRowIndex_i



//==================
template <class T>
ClassFlexibleVector<T> ClassFlexibleMatrix<T>::operator[] (int externalRowIndex_i) const
//==================
{

  if (!(checkExternalRowIndex (externalRowIndex_i)))
  {
    BUG_Matrix_MESSAGE (<< getErrorMsgAboutMatrixRowOutOfRange (externalRowIndex_i, __PRETTY_FUNCTION__));
    return dummy_vector_;
  }

  return rowsVector_ [externalRowIndex_i];

} // ClassFlexibleVector<T> ClassFlexibleMatrix<T>::operator[] (int externalRowIndex_i


//==================
template <class T>
ClassFlexibleVector<T>& ClassFlexibleMatrix<T>::at (int 		externalRowIndex_i,
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				)
//==================
{
  if (!(checkExternalRowIndex (externalRowIndex_i)))
  {
    BUG_Matrix_MESSAGE (<< getErrorMsgAboutMatrixRowOutOfRange (externalRowIndex_i, __PRETTY_FUNCTION__, fileName_i, lineNo_i, compilationDate_i, compilationTime_i));
    return dummy_vector_;
  }

  return rowsVector_ [externalRowIndex_i];

} // T& ClassFlexibleMatrix<T>::at




//==================
template <class T>
ClassFlexibleVector<T> ClassFlexibleMatrix<T>::at (int externalRowIndex_i,
				const string 	fileName_i, 
				const int	lineNo_i, 
				const string	compilationDate_i, 
				const string	compilationTime_i
				) const
//==================
{
  if (!(checkExternalRowIndex (externalRowIndex_i)))
  {
    BUG_Matrix_MESSAGE (<< getErrorMsgAboutMatrixRowOutOfRange (externalRowIndex_i, __PRETTY_FUNCTION__, fileName_i, lineNo_i, compilationDate_i, compilationTime_i));
    return dummy_vector_;
  }

  return rowsVector_ [externalRowIndex_i];
} // T ClassFlexibleMatrix<T>::at 




//==================
template <class T>
ClassFlexibleVector<T> ClassFlexibleMatrix<T>::getFirstMatrixRow () const
//==================
{
  if (rowsVector_.empty ())
  {
		return emptyRow_;
  }
  return (*this) [rowsVector_.Get_minIndex ()];
} // ClassFlexibleVector<T> ClassFlexibleMatrix<T>::getFirstMatrixRow () const 



//==================
template <class T>
void ClassFlexibleMatrix<T>::push_row (const ClassFlexibleVector<T>& rowVector_i)
//==================
{
  // maybe will be deleted : softASSERT (totalColumns () == rowVector_i.size ());
  ClassFlexibleVector<T> tmpRow (getFirstMatrixRow ().Get_minIndex (), LOCATION);
  tmpRow = rowVector_i;
  rowsVector_.push_back (tmpRow);

const int	lastRowNo = rowsVector_.Get_maxIndex ();
  rowsVector_ [lastRowNo].setAboveOrdinalNumber (lastRowNo);
  rowsVector_ [lastRowNo].setPtrAboveVector (&rowsVector_);

} // void ClassFlexibleMatrix<T>::push_row (const ClassFlexibleVector<T>& rowVector_i) 




//==================
template <class T>
void ClassFlexibleMatrix<T>::push_column (const ClassFlexibleVector<T>& columnVector_i)
//==================
{
  ASSERT (totalRows () == columnVector_i.size ());
  ClassFlexibleVector<T> tmpColumn (rowsVector_.Get_minIndex (), LOCATION);
  tmpColumn = columnVector_i;
  for (int rowsIndex = rowsVector_.Get_minIndex (); 
           rowsIndex <= rowsVector_.Get_maxIndex (); 
           rowsIndex++)
  {
    rowsVector_[rowsIndex].push_back (tmpColumn [rowsIndex]);
  }

} // void ClassFlexibleMatrix<T>::push_column (const ClassFlexibleVector<T>& columnVector_i) 



//==================
template <class T>
bool ClassFlexibleMatrix<T>::checkExternalRowIndex (int externalRowIndex_i) const
//==================
{
  return ((externalRowIndex_i >= rowsVector_.Get_minIndex ()) && (externalRowIndex_i <= rowsVector_.Get_maxIndex ()));
} // bool ClassFlexibleMatrix<T>::checkExternalRowIndex (int externalRowIndex_i) const


//==================
template <class T>
bool ClassFlexibleMatrix<T>::empty () const
//==================
{
bool ret_boolValue = absolutelyEmpty ();

  if (!ret_boolValue)
  {
    //===============================
    // i.e. ret_boolValue = false
    //===============================

    //================================================
    // Only rectangular matrixes are used !!!!
    //================================================
    ASSERT (isRectangular ());
    ret_boolValue = getFirstMatrixRow ().empty ();
  }
  return ret_boolValue;
	
} // bool ClassFlexibleMatrix<T>::empty () const


//==================
template <class T>
bool ClassFlexibleMatrix<T>::absolutelyEmpty () const
//==================
{
  return rowsVector_.empty ();
} // bool ClassFlexibleMatrix<T>::absolutelyEmpty () const


//==================
template <class T>
bool ClassFlexibleMatrix<T>::allRowsAreEmpty () const
//==================
{
bool ret_boolValue = absolutelyEmpty ();

  if (!ret_boolValue)
  {
    // i.e. ret_boolValue = false
    ret_boolValue = true;

    for (int rowIndex = rowsVector_.Get_minIndex (); 
             rowIndex <= rowsVector_.Get_maxIndex (); 
             rowIndex++)
    {
      if (!(rowsVector_ [rowIndex].empty ()))
      {
        ret_boolValue = false;
        break;
      }
    } // for ...
		//################################################
  } // if (!ret_boolValue)

  return ret_boolValue;
	
} // bool ClassFlexibleMatrix<T>::allRowsAreEmpty () const



//####################################################################
//==================
template <class T>
bool ClassFlexibleMatrix<T>::isRectangular () const
//==================
{
bool ret_boolValue = absolutelyEmpty ();

  if (!ret_boolValue)
  {
    // i.e. ret_boolValue = false
    ret_boolValue = true;
    int	firstRowIndex = rowsVector_.Get_minIndex (); 

    for (int rowIndex = rowsVector_.Get_minIndex (); 
             rowIndex <= rowsVector_.Get_maxIndex (); 
             rowIndex++)
    {
      if (rowsVector_ [rowIndex].Get_minIndex() != rowsVector_ [firstRowIndex].Get_minIndex())
      {
        ret_boolValue = false;
        break;
      }

      if (rowsVector_ [rowIndex].Get_maxIndex() != rowsVector_ [firstRowIndex].Get_maxIndex())
      {
        ret_boolValue = false;
        break;
      }
    } // for ...
		//################################################
  } // if (!ret_boolValue)

  return ret_boolValue;
	
} // bool ClassFlexibleMatrix<T>::isRectangular () const

//==================
template <class T>
int ClassFlexibleMatrix<T>::totalColumns () const
//==================
{
  if (rowsVector_.empty ())   return 0;
  return getFirstMatrixRow ().size ();
} // int ClassFlexibleMatrix<T>::totalColumns () const 


//==================
template <class T>
ClassFlexibleMatrix<T> ClassFlexibleMatrix<T>::slice (
		const int& minRowIndexSlice_i, 
		const int& maxRowIndexSlice_i, 
		const int& minColumnIndexSlice_i, 
		const int& maxColumnIndexSlice_i
		)
//==================
{
ClassFlexibleVector< ClassFlexibleVector<T> >	tmpRowsVector;	
  tmpRowsVector = rowsVector_.slice (minRowIndexSlice_i, maxRowIndexSlice_i);

ClassFlexibleMatrix<T>  ret_ClassFlexibleMatrixObject (minRowIndexSlice_i, minColumnIndexSlice_i, LOCATION);
  for (int rowsIndex = tmpRowsVector.Get_minIndex (); 
           rowsIndex <= tmpRowsVector.Get_maxIndex(); 
           rowsIndex++)
  {
    ret_ClassFlexibleMatrixObject.rowsVector_.push_back (tmpRowsVector[rowsIndex].slice (minColumnIndexSlice_i, maxColumnIndexSlice_i));
  }

  return ret_ClassFlexibleMatrixObject;
} // ClassFlexibleMatrix<T> ClassFlexibleMatrix<T>::slice





//################################################################

#endif



//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #7 of 15 : fx_matr2.h ==========================

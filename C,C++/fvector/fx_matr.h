
// #########################################################
// === File #6 of 15 : fx_matr.h ===========================
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

#ifndef FX_MATR_H
#define FX_MATR_H

///////////////////////////////////////


// ##############################################################
//
//  SOFTWARE : Vector and Matrix with arbitrary bounds
//  FILE     : fx_matr.h
//
//  DESCRIPTION :
//         Definition of flexible matrix classes
//	   --------------------------------------------------
//         - ClassBasicMatrix
//         - ClassFlexibleMatrix
//	   --------------------------------------------------
//
//  ----           -------
//  Oct-30-2001    FVM 1.0
//
// ##############################################################

//==================
#include "fx_vect.h"
//==================

//===============================================
#define GET_melem(m, x, y) m##.at(x, LOCATION)##.at(y, LOCATION)

//########################################################
//#################### ClassBasicMatrix ##################
//######################## Declaration ###################
//########################################################
class ClassBasicMatrix
{
  protected:
    ClassBasicMatrix ();
    virtual ~ClassBasicMatrix ();
    static unsigned long	countBasicMatrixConstructors_s;
    static unsigned long	countBasicMatrixDestructors_s;
  public:
    static string		gstrBasicMatrixAccount_S (string msg_i = "");
};


//########################################################
//################### ClassFlexibleMatrix ################
//######################## Declaration ###################
//########################################################
template <class T>
class ClassFlexibleMatrix : public ClassBasicMatrix
{
  private:
    ClassFlexibleVector< ClassFlexibleVector<T> >	rowsVector_;
    ClassFlexibleVector<T>				emptyRow_;	// for Empty Matrix only
    ClassFlexibleVector<T>				dummy_vector_;

    bool		checkExternalRowIndex (int externalRowIndex_i) const;
    string		gstrMatrixShow (
				char*	file_name_i, 
				int	line_no_i, 
				string	msg_i = "",
				string	printFormat_i = "",
				int	width_i = 0
				) const;
    string		getErrorMsgAboutMatrixRowOutOfRange (
				int		externalIndex_i,
				const string&	theFuncName_i,
				const string 	fileName_i = "",
				const int	lineNo_i = 0,
				const string	compilationDate_i = "",
				const string	compilationTime_i = ""
				) const;

  public:
    ClassFlexibleMatrix ();
    ClassFlexibleMatrix (
		int 		minRowIndex_i,
		int 		minColumnIndex_i,
		const string 	fileName_i,
		const int	lineNo_i,
		const string	compilationDate_i,
		const string	compilationTime_i
		);
    ClassFlexibleMatrix (
		int 		minRowIndex_i,
		int		maxRowIndex_i,
		int 		minColumnIndex_i,
		int		maxColumnIndex_i,
		const T&	value_i,
		const string 	fileName_i,
		const int	lineNo_i,
		const string	compilationDate_i,
		const string	compilationTime_i
		);

    // Copy Constructor
    ClassFlexibleMatrix (const ClassFlexibleMatrix& theCopyInstance_i);
    ~ClassFlexibleMatrix ();
    bool		empty () const;			// for Rectangular Matrix only (Why?)
    bool		absolutelyEmpty () const;	// i.e. totalRows = 0
    bool		allRowsAreEmpty () const;	// i.e. totalRows > 0, but totalColumns in each row = 0;
    bool		isRectangular () const;
    int			totalRows () const {return rowsVector_.size ();}
    int			Get_minRowNo () const {return rowsVector_.Get_minIndex ();}
    int			Get_maxRowNo () const {return rowsVector_.Get_maxIndex ();}
    int			totalColumns () const;
    void		push_row (const ClassFlexibleVector<T>& row_i);
    void		push_column (const ClassFlexibleVector<T>& column_i);
    ClassFlexibleMatrix 	slice (
					const int& minRowIndexSlice_i,
					const int& maxRowIndexSlice_i,
					const int& minColumnIndexSlice_i,
					const int& maxColumnIndexSlice_i
					);
    ClassFlexibleMatrix&	operator= (const ClassFlexibleMatrix& instance_i);
    ClassFlexibleMatrix&	softAssign (const ClassFlexibleMatrix& instance_i);
    ClassFlexibleMatrix&	hardAssign (const ClassFlexibleMatrix& instance_i);
    ClassFlexibleVector<T>&	operator[] (int externalRowIndex_i);
    ClassFlexibleVector<T>	operator[] (int externalRowIndex_i) const;
    ClassFlexibleVector<T>&	at (int externalIndex_i,
					const string 	fileName_i,
					const int	lineNo_i,
					const string	compilationDate_i,
					const string	compilationTime_i
					);
    ClassFlexibleVector<T>	at (int externalIndex_i,
					const string 	fileName_i,
					const int	lineNo_i,
					const string	compilationDate_i,
					const string	compilationTime_i
					) const;
    ClassFlexibleVector<T>	getFirstMatrixRow () const;
    string			gstrVectorShowMatrix (string msg_i = "") const;
    string			gstrMElemenShow (
					int	externalRowIndex_i,
					int	externalColumnIndex_i,
					string	printFormat_i = "",
					int	width_i = 0
					) const;
    void			showMatrix (
					char*	file_name_i, 
					int	line_no_i, 
					string	msg_i = "",
					string	printFormat_i = "",
					int	width_i = 0
					) const;
};
//////////////////////////////////////////////////////////////////
//################################################################
//################################################################
//////////////////////////////////////////////////////////////////

//################################################################

#endif

//################################################################
//#                          END OF FILE                         # 
//################################################################


// ------------------- C++ code : END ----------------------
// === File #6 of 15 : fx_matr.h ===========================

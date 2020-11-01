#ifndef _DEFINE_H_
#define _DEFINE_H_

typedef VOID(CALLBACK * AddMoreMsg) (VOID);
typedef VOID(CALLBACK * Progress) (DOUBLE);

// Error codes
#define Success								    0
#define Invalid_Parameters_Signature_Type       1  
#define Invalid_Parameters_No_Function_Address  2  
#define Invalid_Parameters_No_Signature_Memory  3  
#define Invalid_Parameters_Pass				    4  
#define Invalid_Parameters_BreakLength			5
#define File_Open_Error						    6
#define File_Too_Long						    7
#define File_IO_Error			                8
#define Uninitialized_Reference                 9
#define Out_Of_Memory_Error		               10
#define Uninitialized_Memory				   11

// Global Error Variable
LONG Error = Success;

// Expected Buffer Size
#define MB_1    1048576L
#define KB_512  524288L
#define KB_256  262144L
#define KB_128  131072L
#define KB_64   65536L
#define KB_32   32768L

// Type of Signatures
#define MD_4_128		 1  // Message Digest 
#define MD_4_256	     2
#define MD_5             3	
#define RIPEMD_128       4  // RACE Integrity Primitives Evaluation
#define RIPEMD_160       5
#define RIPEMD_256       6
#define RIPEMD_320       7
#define SHA_1            8  // Secure Hash Algorithm
#define SHA_256          9  
#define SHA_384	        10
#define SHA_512	        11  
#define HAVAL_128       12
#define HAVAL_160       13
#define HAVAL_192       14
#define HAVAL_224       15
#define HAVAL_256       16
#define BASE64_ENCODE	17
#define BASE64_DECODE	18


// Lengths of the Signatures in Bytes
#define LENGTH_MD4_128_MD5_RIPEMD128_HAVAL128		16
#define LENGTH_SHA1_RIPEMD160_HAVAL160				20
#define LENGTH_HAVAL192								24
#define LENGTH_HAVAL224								28
#define LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256	32
#define LENGTH_RIPEMD320							40
#define LENGTH_SHA384								48
#define	LENGTH_SHA512								64

// HAVAL Version Number
#define HAVAL_VERSION	1

// Length of datatype
#define _32BIT	32
#define _64BIT	64

// Circular Rotate Left
#define Rotate_Left(Num,Value,D_Size) ((Num << Value) | \
									   (Num >> (D_Size - Value)))

// Circular Rotate Right
#define Rotate_Right(Num,Value,D_Size) ((Num >> Value) | \
										(Num << (D_Size - Value)))

// Right Shift
#define Shift_Right(Num,Value) (Num >> Value)

// The Core Functions Of Signatures
#define Func1(X,Y,Z) (Z ^ X & (Y ^ Z)) // XY v ~XZ optimized
#define Func2(X,Y,Z) ((X | ~Y) ^ Z)
#define Func3(X,Y,Z) (X ^ Y ^ Z)

// Functions for MD4_xxx
#define MD_4_1(X,Y,Z) Func1(X,Y,Z)
#define MD_4_2(X,Y,Z) ((X & Y) | (X & Z) | (Y & Z))
#define MD_4_3(X,Y,Z) Func3(X,Y,Z)

// Functions for MD5
#define MD_5_1(X,Y,Z) Func1(X,Y,Z)
#define MD_5_2(X,Y,Z) Func1(Z,X,Y)
#define MD_5_3(X,Y,Z) Func3(X,Y,Z)
#define MD_5_4(X,Y,Z) Func2(X,Z,Y)

// Functions For SHA-1
#define SHA_1_1(X,Y,Z) Func1(X,Y,Z)
#define SHA_1_2(X,Y,Z) Func3(X,Y,Z)
#define SHA_1_3(X,Y,Z) Func1(Y,(X | Z),(X & Z))
#define SHA_1_4(X,Y,Z) Func3(X,Y,Z)

// Functions For RIPEMD_xxx
#define RIPEMD_xxx_1(X,Y,Z) Func3(X,Y,Z)
#define RIPEMD_xxx_2(X,Y,Z) Func1(X,Y,Z)
#define RIPEMD_xxx_3(X,Y,Z) Func2(X,Y,Z)
#define RIPEMD_xxx_4(X,Y,Z) Func1(Z,X,Y)
#define RIPEMD_xxx_5(X,Y,Z) Func2(Y,Z,X)

// Functions For SHA-256
#define SHA_256_CH(X,Y,Z) (((X) & (Y)) ^ ((~X) & (Z)))
#define SHA_256_MAJ(X,Y,Z) (((X) & (Y)) ^ ((X) & (Z)) ^ ((Y) & (Z)))

#define Sig_256_RR_0(X) ((Rotate_Right(X,2,_32BIT)) ^ \
						 (Rotate_Right(X,13,_32BIT)) ^ \
						 (Rotate_Right(X,22,_32BIT)))

#define Sig_256_RR_1(X) ((Rotate_Right(X,6,_32BIT)) ^ \
						 (Rotate_Right(X,11,_32BIT)) ^ \
						 (Rotate_Right(X,25,_32BIT)))

#define Sig_256_SR_0(X) (Rotate_Right(X,7,_32BIT) ^ \
						 Rotate_Right(X,18,_32BIT) ^ \
						 Shift_Right(X,3))

#define Sig_256_SR_1(X) (Rotate_Right(X,17,_32BIT) ^ \
						 Rotate_Right(X,19,_32BIT) ^ \
						 Shift_Right(X,10))

// Functions for SHA-384 & SHA-512
#define SHA_384_512_CH(X,Y,Z) SHA_256_CH(X,Y,Z)
#define SHA_384_512_MAJ(X,Y,Z) SHA_256_MAJ(X,Y,Z)

#define Sig_384_512_RR_0(X) ((Rotate_Right(X,28,_64BIT)) ^ \
							 (Rotate_Right(X,34,_64BIT)) ^ \
							 (Rotate_Right(X,39,_64BIT)))

#define Sig_384_512_RR_1(X) ((Rotate_Right(X,14,_64BIT)) ^ \
							 (Rotate_Right(X,18,_64BIT)) ^ \
							 (Rotate_Right(X,41,_64BIT)))

#define Sig_384_512_SR_0(X) (Rotate_Right(X,1,_64BIT) ^ \
							 Rotate_Right(X,8,_64BIT) ^ \
							 Shift_Right(X,7))

#define Sig_384_512_SR_1(X) (Rotate_Right(X,19,_64BIT) ^ \
							 Rotate_Right(X,61,_64BIT) ^ \
							 Shift_Right(X,6))

// Functions or HAVAL
/* Basic Functions */
#define F1(X6,X5,X4,X3,X2,X1,X0) \
			 ((X1 & X4) ^ (X2 & X5) ^ (X3 & X6) ^ (X0 & X1) ^ X0)

#define F2(X6,X5,X4,X3,X2,X1,X0) \
			 ((X1 & X2 & X3) ^ (X2 & X4 & X5) ^ (X1 & X2) \
				^ (X1 & X4) ^ (X2 & X6) ^ (X3 & X5) ^ (X4 & X5) \
				^ (X0 & X2) ^ X0)

#define F3(X6,X5,X4,X3,X2,X1,X0) \
			 ((X1 & X2 & X3) ^ (X1 & X4) ^ (X2 & X5) ^ (X3 & X6) \
				^ (X0 & X3) ^ X0)

#define F4(X6,X5,X4,X3,X2,X1,X0) \
			 ((X1 & X2 & X3) ^ (X2 & X4 & X5) ^ (X3 & X4 & X6) \
				^ (X1 & X4) ^ (X2 & X6) ^ (X3 & X4) ^ (X3 & X5) \
				^ (X3 & X6) ^ (X4 & X5) ^ (X4 & X6) ^ (X0 & X4) \
				^ X0)

#define F5(X6,X5,X4,X3,X2,X1,X0) \
			 ((X1 & X4) ^ (X2 & X5) ^ (X3 & X6) ^ \
				(X0 & X1 & X2 & X3) ^ (X0 & X5) ^ X0)

/* Permutations Functions */
// For PASS = 3
#define Fphi_3_1(X6,X5,X4,X3,X2,X1,X0) \
			  F1(X1,X0,X3,X5,X6,X2,X4)

#define Fphi_3_2(X6,X5,X4,X3,X2,X1,X0) \
			  F2(X4,X2,X1,X0,X5,X3,X6)

#define Fphi_3_3(X6,X5,X4,X3,X2,X1,X0) \
			  F3(X6,X1,X2,X3,X4,X5,X0)

// For PASS = 4
#define Fphi_4_1(X6,X5,X4,X3,X2,X1,X0) \
			  F1(X2,X6,X1,X4,X5,X3,X0)

#define Fphi_4_2(X6,X5,X4,X3,X2,X1,X0) \
			  F2(X3,X5,X2,X0,X1,X6,X4)

#define Fphi_4_3(X6,X5,X4,X3,X2,X1,X0) \
			  F3(X1,X4,X3,X6,X0,X2,X5)

#define Fphi_4_4(X6,X5,X4,X3,X2,X1,X0) \
			  F4(X6,X4,X0,X5,X2,X1,X3)

// For PASS = 5
#define Fphi_5_1(X6,X5,X4,X3,X2,X1,X0) \
			  F1(X3,X4,X1,X0,X5,X2,X6)

#define Fphi_5_2(X6,X5,X4,X3,X2,X1,X0) \
			  F2(X6,X2,X1,X0,X3,X4,X5)

#define Fphi_5_3(X6,X5,X4,X3,X2,X1,X0) \
			  F3(X2,X6,X0,X4,X3,X1,X5)

#define Fphi_5_4(X6,X5,X4,X3,X2,X1,X0) \
			  F4(X1,X5,X3,X2,X0,X4,X6)

#define Fphi_5_5(X6,X5,X4,X3,X2,X1,X0) \
			  F5(X2,X5,X0,X6,X4,X3,X1)

#endif

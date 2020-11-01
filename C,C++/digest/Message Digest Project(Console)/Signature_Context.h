#ifndef _SIGNATURE_CONTEXT_H_
#define _SIGNATURE_CONTEXT_H_

#include "include.h"

class Signature_Context
{

private:
	UCHAR ucCur_Size_of_Buffer;
	UCHAR ucCheck;
	UCHAR ucSignature_Type;
	UCHAR ucDigest_Length;

	DOUBLE dProgress,dDelta_Progress;
	Progress ShowProgress;

	union
	{
		FILE * OutFileStream;
		PCHAR  lpChar;
	}OutPut;

	union Finger_Prints
	{
		ULONGLONG ullValues[8];
		ULONG     ulValues[16];
		UINT	  uiValues[32];
		UCHAR     ucValues[64];
		UCHAR	  ucullValues[8][8];
		UCHAR	  uculValues[16][4];
	}Hash;
	
	struct
	{
		UCHAR ucBlockSize;
		union
		{
			PUCHAR     ucValues;
			PSHORT     sValues;
			PULONG     ulValues;
			PULONGLONG ullValues;
		}Block;
	}Message;

	union
	{
		ULONGLONG ullLength;
		UCHAR ucChar_Codes[8];
		struct
		{
			unsigned Bit_4:6;
			unsigned Bit_3:6;
			unsigned Bit_2:6;
			unsigned Bit_1:6;
		}Bits;
	}Code_Convertor;

	// Private Functions
	LONG Initialize(UCHAR,UCHAR);
	VOID Destroy(VOID);

	LONG Expected_FileSize(ULONGLONG &);

	VOID MD4_Transform(VOID);
	VOID MD5_Transform(VOID);
	VOID SHA1_Transform(VOID);
	VOID SHA256_Transform(VOID);
	VOID SHA_384_512_Transform(VOID);
	VOID RIPEMD_128_256_Transform(VOID);
	VOID RIPEMD_160_320_Transform(VOID);
	VOID HAVAL_Transform(SHORT);

	VOID HAVAL_Tailor(VOID);

	VOID Signature_Transform(UCHAR);

	VOID Signature_Final(UCHAR);

	VOID BASE64_Encode_Update(PCHAR,ULONG &);
	VOID Base64_Encode_Final(VOID);
	VOID BASE64_Decode(PCHAR);

public:
	Signature_Context(UCHAR = MD_5, UCHAR = 0); // Parameterized Constructor
	~Signature_Context(VOID); // Destructor

	LONG Create_Signature(PCHAR,ULONG,PCHAR,SHORT,
						 UCHAR = 3,UCHAR = 0,SHORT = 0,	
						 LONG = NULL,LONG = NULL);

	VOID Signature_Update(PCHAR,ULONG &);
};

Signature_Context * Context = NULL;

#endif

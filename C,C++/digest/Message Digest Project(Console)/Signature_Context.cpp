#ifndef _SIGNATURE_CONTEXT_CPP_
#define _SIGNATURE_CONTEXT_CPP_

// Including the Signature_Context Class
#include "Signature_Context.h"
#include "Other_Functions.cpp"
#include "All.h"

/*******************************************************************/
/*  Name of function : Signature_Context
	
	Parameters:
		Type = [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18]
				as per the Requirement
		BreakL = The Break Length Value. Used only for BASE 64.

    Return Value : Nothing
	
	Purpose : Initializing Memory/Values to the Members of Class
*/
/*******************************************************************/

Signature_Context::Signature_Context(UCHAR Type, UCHAR BreakL)
{
	Initialize(Type,BreakL);
}

/*******************************************************************/
/*  Name of function : ~Signature_Context
	
	Parameters : Nothing
  
	Return Value : Nothing
	
	Purpose : Destroying Memory of the Members of Class
*/
/*******************************************************************/

Signature_Context::~Signature_Context(VOID)
{
	Destroy();
}

/*******************************************************************/
/*  Name of function : Initialize
	Parameters:
		Type = [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17/18]
				as per the Requirement
		BreakL = The Break Length Value. Used only for BASE 64.

	Return Value : Error value Codes
	
	Purpose : Private Member Function Called from the Constructor of
			  the Class to allocate the memory, Myseterious
			  Hash Values according the Type, BASE 64 Encoding Table
*/
/*******************************************************************/

LONG Signature_Context::Initialize(UCHAR Type, UCHAR BreakL)
{
	if (this == NULL)
		return(Error = Uninitialized_Reference);

	memset((VOID *)this,NULL,sizeof(Signature_Context));
	
	if(Type < MD_4_128 || Type > BASE64_DECODE)
		return(Error = Invalid_Parameters_Signature_Type);
	
	ucSignature_Type = Type; Message.ucBlockSize = 64;

	// Assigning First 4 Hash Values 
	// Since, First 4 Hash Values of atmost all Security Signatures 
	// are same
	Hash.ulValues[0] = 0x67452301L;
	Hash.ulValues[1] = 0xEFCDAB89L;
	Hash.ulValues[2] = 0x98BADCFEL;
	Hash.ulValues[3] = 0x10325476L;
	
	switch(Type)
	{
		case MD_4_128:
		case MD_4_256:
		case MD_5:
		case RIPEMD_128:
		{
			ucDigest_Length = LENGTH_MD4_128_MD5_RIPEMD128_HAVAL128;

			if(Type == MD_4_256)
			{
				// Extended Hash Values
				Hash.ulValues[4] = 0x33221100L;
				Hash.ulValues[5] = 0x77665544L;
				Hash.ulValues[6] = 0xBBAA9988L;
				Hash.ulValues[7] = 0xFFEEDDCCL;
				
				ucDigest_Length = LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256;
			}
			break;
		}
		case SHA_1:
		case RIPEMD_160:
		{
			Hash.ulValues[4] = 0xC3D2E1F0L;
			ucDigest_Length = LENGTH_SHA1_RIPEMD160_HAVAL160;
			break;
		}
		case RIPEMD_256:
		case RIPEMD_320:
		{
			Hash.ulValues[4 + Type - RIPEMD_256] = 0x76543210L;
			Hash.ulValues[5 + Type - RIPEMD_256] = 0xFEDCBA98L;
			Hash.ulValues[6 + Type - RIPEMD_256] = 0x89ABCDEFL;
			Hash.ulValues[7 + Type - RIPEMD_256] = 0x01234567L;

			if(Type == RIPEMD_256)
				ucDigest_Length = LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256;
			else
			{
				ucDigest_Length = LENGTH_RIPEMD320;
				Hash.ulValues[4] = 0xC3D2E1F0L;
				Hash.ulValues[9] = 0x3C2D1E0FL;
			}		
			break;
		}
		case SHA_256:
		{
			ucDigest_Length = LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256;
			Hash.ulValues[0] = 0x6A09E667L;
			Hash.ulValues[1] = 0xBB67AE85L;
			Hash.ulValues[2] = 0x3C6EF372L;
			Hash.ulValues[3] = 0xA54FF53AL;
			Hash.ulValues[4] = 0x510E527FL;
			Hash.ulValues[5] = 0x9B05688CL;
			Hash.ulValues[6] = 0x1F83D9ABL;
			Hash.ulValues[7] = 0x5BE0CD19L;
			break;
		}
		case SHA_384:
		{
			ucDigest_Length = LENGTH_SHA384;
			Hash.ullValues[0] = 0xcbbb9d5dc1059ed8;
			Hash.ullValues[1] = 0x629a292a367cd507;
			Hash.ullValues[2] = 0x9159015a3070dd17;
			Hash.ullValues[3] = 0x152fecd8f70e5939;
			Hash.ullValues[4] = 0x67332667ffc00b31;
			Hash.ullValues[5] = 0x8eb44a8768581511;
			Hash.ullValues[6] = 0xdb0c2e0d64f98fa7;
			Hash.ullValues[7] = 0x47b5481dbefa4fa4;

			Message.ucBlockSize = 128;
			break;
		}
		case SHA_512:
		{
			ucDigest_Length = LENGTH_SHA512;
			Hash.ullValues[0] = 0x6a09e667f3bcc908;
			Hash.ullValues[1] = 0xbb67ae8584caa73b;
			Hash.ullValues[2] = 0x3c6ef372fe94f82b;
			Hash.ullValues[3] = 0xa54ff53a5f1d36f1;
			Hash.ullValues[4] = 0x510e527fade682d1;
			Hash.ullValues[5] = 0x9b05688c2b3e6c1f;
			Hash.ullValues[6] = 0x1f83d9abfb41bd6b;
			Hash.ullValues[7] = 0x5be0cd19137e2179;

			Message.ucBlockSize = 128;
			break;
		}
		case HAVAL_128:
		case HAVAL_160:
		case HAVAL_192:
		case HAVAL_224:
		case HAVAL_256:
		{
			if(Type == HAVAL_128)
				ucDigest_Length = LENGTH_MD4_128_MD5_RIPEMD128_HAVAL128;

			if(Type == HAVAL_160)
				ucDigest_Length = LENGTH_SHA1_RIPEMD160_HAVAL160;
			
			if(Type == HAVAL_192)
				ucDigest_Length = LENGTH_HAVAL192;
			
			if(Type == HAVAL_224)
				ucDigest_Length = LENGTH_HAVAL224;
			
			if(Type == HAVAL_256)
				ucDigest_Length = LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256;

			Hash.ulValues[0] = 0x243F6A88L;
			Hash.ulValues[1] = 0x85A308D3L;
			Hash.ulValues[2] = 0x13198A2EL;
			Hash.ulValues[3] = 0x03707344L;
			Hash.ulValues[4] = 0xA4093822L;
			Hash.ulValues[5] = 0x299F31D0L;
			Hash.ulValues[6] = 0x082EFA98L;
			Hash.ulValues[7] = 0xEC4E6C89L;

			Message.ucBlockSize = 128;
			break;
		}
		case BASE64_ENCODE:
		case BASE64_DECODE:
		{
			UCHAR i;
			for(i=0;i<26;Hash.ucValues[i++] = i + 65);
			for(i=26;i<52;Hash.ucValues[i++] = i + 71);
			for(i=52;i<62;Hash.ucValues[i++] = i - 4);
			Hash.ucValues[62] = '+';
			Hash.ucValues[63] = (ucSignature_Type == BASE64_ENCODE ? \
													 '/':'\0');
			Code_Convertor.ucChar_Codes[5] = BreakL;
			break;
		}
	}

	// Allocating the Memory 
	if((Message.Block.ucValues = new \
					UCHAR[Message.ucBlockSize]) == NULL)
		return(Error = Out_Of_Memory_Error);

	return(Error = Success);
}

/*******************************************************************/
/*  Name of function : Destroy

	Parameters: Nothing
				
	Return Value : Nothing
	
	Purpose : Private Member Function Called from the Destructor of
			  the Class to Destroy the memory which was allocated by
			  the Constructor.	
*/
/*******************************************************************/

VOID Signature_Context::Destroy(VOID)
{
	if(Message.Block.ucValues)
		delete [] Message.Block.ucValues;
	memset((VOID *)this,NULL,sizeof(Signature_Context));
}
	
/*******************************************************************/
/*  Name of function : Expected_FileSize

	Parameters: 
			Fsize :- Size of the File
				
	Return Value : File Size Codes
	
	Purpose : Private Member Function which returns the expected
			  Buffer Size so as to speed up the operation.
*/
/*******************************************************************/

LONG Signature_Context::Expected_FileSize(ULONGLONG &Fsize)
{
	if((Fsize >> 16) == 0)
		return(KB_32);
	
	if((Fsize >> 17) == 0)
		return(KB_64);

	if((Fsize >> 18) == 0)
		return(KB_128);

	if((Fsize >> 19) == 0)
		return(KB_256);

	if((Fsize >> 20) == 0)
		return(KB_512);

	return(MB_1);
}

/*******************************************************************/
/*  Name of function : Signature_Transform

	Parameters: Pass [3/4/5]
				The Number of Pass in the HAVAL Algorithm
				
	Return Value : Nothing
	
	Purpose : Private Member Function for calling the Transformation
			  Function as per the Type of the Signature.
			  Also calling the callback function to show the progress
*/
/*******************************************************************/


VOID Signature_Context::Signature_Transform(UCHAR Pass)
{
	switch(ucSignature_Type)
	{
		case MD_4_128:
		case MD_4_256:
		{
			MD4_Transform();
			break;
		}
		case MD_5:
		{
			MD5_Transform();
			break;
		}
		case SHA_1:
		{
			SHA1_Transform();
			break;
		}
		case RIPEMD_128:
		case RIPEMD_256:
		{
			RIPEMD_128_256_Transform();
			break;
		}
		case RIPEMD_160:
		case RIPEMD_320:
		{
			RIPEMD_160_320_Transform();
			break;
		}
		case SHA_256:
		{
			SHA256_Transform();
			break;
		}
		case SHA_512:
		case SHA_384:
		{
			SHA_384_512_Transform();
			break;
		}
		case HAVAL_128:
		case HAVAL_160:
		case HAVAL_192:
		case HAVAL_224:
		case HAVAL_256:
		{
			HAVAL_Transform(Pass);
			break;
		}
		
	}
	if(ShowProgress)
	{
		dProgress += dDelta_Progress;
		ShowProgress(dProgress);
	}
}

/*******************************************************************/
/*  Name of function : Signature_Update

	Parameters: 
			Buff : The Message Which is send to process
			Len  : The Length of the Message, Send into Buff.
				
	Return Value : Nothing
	
	Purpose : Private Member Function to do the Transformation of the 
			  Message till the size of Message is not less the 64 or
			  128 bytes as per the Signature Type.This function will
			  also call the BASE 64 Encode and Decode Function.
*/
/*******************************************************************/

VOID Signature_Context::Signature_Update(PCHAR Buff, ULONG & Len)
{
	
	switch(ucSignature_Type)
	{
		case BASE64_ENCODE:
		{
			BASE64_Encode_Update(Buff,Len);
			break;
		}// case ends
		case BASE64_DECODE:
		{
			BASE64_Decode(Buff);
			break;
		}// Case ends
		default:
		{
			if(Len == 0)
				return;

			UCHAR Data_Size;

			if(ucSignature_Type >= MD_4_128 && ucSignature_Type \
												<= SHA_256)
				Data_Size = 64;
			else
				Data_Size = 128;

			Code_Convertor.ullLength += Len;

			if(ucCur_Size_of_Buffer)
			{
				UCHAR RemainingBytes = Data_Size - \
									   ucCur_Size_of_Buffer;

				UCHAR BytesCopy = \
					(Len < RemainingBytes) ? (UCHAR)Len : \
											 RemainingBytes;

				memcpy(&Message.Block.ucValues[ucCur_Size_of_Buffer],
											  Buff,BytesCopy);

				ucCur_Size_of_Buffer = \
					(ucCur_Size_of_Buffer + BytesCopy) & 0x3F;

				if(ucCur_Size_of_Buffer)
					return;

				Len -= BytesCopy;
				Signature_Transform(0);
			}
			
			while(Len >= Data_Size)
			{
				memcpy(Message.Block.ucValues,Buff,Data_Size);
				Signature_Transform(0);
				Buff += Data_Size;
				Len -= Data_Size;
			}

			if(Len)
			{
				memcpy(Message.Block.ucValues,Buff,Len);
				ucCur_Size_of_Buffer = (UCHAR)Len;
			}
			break;
		}// Default end
	}// Switch end
}

/*******************************************************************/
/*  Name of function : Signature_Final

	Parameters: Pass [3/4/5]
				Used only for HAVAL series
				
	Return Value : Nothing
	
	Purpose : Private Member Function to do the Final Transformation
			  of the Remaining Message.
*/
/*******************************************************************/

VOID Signature_Context::Signature_Final(UCHAR Pass)
{
	
	UCHAR Data_Size, Min_Length;

	if(ucSignature_Type >= MD_4_128 && ucSignature_Type <= SHA_256)
	{
		Data_Size = 64; 
		Min_Length = 8;
	}
	else
		// This is for SHA-384, SHA-512, HAVAL
	{
			Data_Size = 128;
		if(ucSignature_Type == SHA_384 || ucSignature_Type == SHA_512)
			Min_Length = 16;
		else
			Min_Length = 10;
	}

	UCHAR RemainingBytes = Data_Size - 1 - ucCur_Size_of_Buffer;

	if(ucSignature_Type >= MD_4_128 && ucSignature_Type <= SHA_512)
		Message.Block.ucValues[ucCur_Size_of_Buffer] = 0x80;
	else
		// This if for HAVAL
		Message.Block.ucValues[ucCur_Size_of_Buffer] = 1;

	if(RemainingBytes < Min_Length)
	{
		memset(&Message.Block.ucValues[ucCur_Size_of_Buffer + 1],
					0x0,RemainingBytes);
		Signature_Transform(Pass);
		memset(Message.Block.ucValues,0x0,(ucSignature_Type >= \
							MD_4_128 && ucSignature_Type <= SHA_256) \
							? 56 : 128);
	}
	else
		memset(&Message.Block.ucValues[ucCur_Size_of_Buffer + 1],
				0x0, RemainingBytes - \
				((ucSignature_Type >= MD_4_128 && \
				  ucSignature_Type <= SHA_512)? 8 : 5));

	if(ucSignature_Type >= HAVAL_128 && ucSignature_Type <= HAVAL_256)
		Message.Block.sValues[59] = (SHORT(ucDigest_Length) << 9 |
							(Pass << 3) | SHORT(HAVAL_VERSION));

	Code_Convertor.ullLength <<= 3;


	Message.Block.ullValues[(Message.ucBlockSize >> 3) - 1] = 
							Code_Convertor.ullLength;


	if(ucSignature_Type >= SHA_1 && ucSignature_Type <= SHA_512)
	{
		Message.Block.ullValues[(Message.ucBlockSize >> 3) - 1] = \
			Endian_Conversion(Message.Block.ullValues \
								[(Message.ucBlockSize >> 3) - 1]);
	}

	Signature_Transform(Pass);

	UCHAR Temp;
	if(ucSignature_Type == SHA_1 || ucSignature_Type == SHA_256)
	{
		CHAR Values = ucSignature_Type == SHA_1 ? 5 : 8;
		for(Temp = 0; Temp < Values; Hash.ulValues[Temp++] = \
						Endian_Conversion(Hash.ulValues[Temp]));
	}
	else
	{
		if(ucSignature_Type == SHA_384 || ucSignature_Type == SHA_512)
		{
			for(Temp = 0; Temp < 8; Hash.ullValues[Temp++] = \
							Endian_Conversion(Hash.ullValues[Temp]));
		}
	}
	if(ucSignature_Type >= HAVAL_128 && ucSignature_Type <= HAVAL_256)
		HAVAL_Tailor();
}

/*******************************************************************/
/*  Name of function : Create_Signature

	Parameters:
		 Message         : The Message which is to be process
					       Can be a filename also.
		 BufferLength    : The Size of Message. If the Message is
						   filename then value is 0.
		 Signature       : Buffer which will return the calculated
						   Message Digest.
		 Destination     : The Destination could be file or the 
						   Character Pointer 'Signature'
						   If Character Pointer then value is 0
						   If File then value is 1.
		 Pass		     : Number of Pass (Used for only HAVAL
						   algorithm) Default value is 3.
						   If Signature_Type is BASE64_ENCODE then 
						   Pass represents the breaklength Value
		 Case			 : To set the Case of the output
						   Any Positive value then case is Upper else
						   Lower case.
		 IsMoreMsg       : If more Message is there then any Positive
						   value or else 0. 	
		 LPFnShowProg    : A Function pointer which will be called to
						   show the progress.
	     LPFnAddMsg      : A Function Pointer which will be called so
						   as to add any remaining Message.

				
	Return Value : Error Value Codes
	
	Purpose : Public Member Function which is to be called so as to
			  create the Message Digest, BASE 64 Encoding and 
			  Decoding.
*/
/*******************************************************************/

LONG Signature_Context::Create_Signature(PCHAR Message,
						 ULONG BufferLength, PCHAR Signature,
						 SHORT Destination,UCHAR Pass,UCHAR Case,
						 SHORT IsMoreMsg,LONG AddMsg,LONG ShowProg)
{

	FILE *FileStream = NULL; // To perform file operation
	ULONGLONG FSize = 0;    // Size of file (64 bit unsigned)
	LONGLONG BufferRead = 0; // Total no. of 64 bytes buffer in file
	PCHAR Buffer = NULL;    // Process 512 blocks of 64 byte each
	static CHAR Re_Entrant;   
	AddMoreMsg LPFnAddMsg;

	LPFnAddMsg = (AddMoreMsg)AddMsg; // Assign the Fucntion Addresses
	ShowProgress = (Progress)ShowProg;
	
	if(!Re_Entrant)
		if(Destination != NULL)
		{
			if((OutPut.OutFileStream = fopen(Signature,"wb")) == NULL)
				return(Error = File_Open_Error);
			else
				if(ucSignature_Type == BASE64_ENCODE || \
				   ucSignature_Type == BASE64_DECODE)
					ucCheck = 1; // Sets for the File 
		}
		else
			if(ucSignature_Type == BASE64_ENCODE || \
			   ucSignature_Type == BASE64_DECODE )
				OutPut.lpChar = Signature; // Sets for the Pointer

	if(BufferLength || strlen(Message) == 0)
		Buffer = Message;
	else
	{
		if((FileStream = fopen(Message,"rb")) == NULL)
			return(Error = File_Open_Error);
		else
		{
			FSize = _filelengthi64(_fileno(FileStream)); 
		
			BufferRead = FSize >> 6; // Total no. of 64 blocks

			if(BufferRead < 0)
			{
				FileStream = (FILE *)(fclose(FileStream) & 0x0);
				return(Error = File_Too_Long);
			}
			
			BufferLength = Expected_FileSize(FSize);
			
			while((BufferLength >= KB_32) && \
				  ((Buffer = \
						   new CHAR[BufferLength + 1]) == NULL))
						BufferLength >>= 1;

			if(Buffer == NULL)
			{
				FileStream = (FILE *)(fclose(FileStream) & 0x0);
				return(Error = Out_Of_Memory_Error);
			}
			Buffer[strlen(Buffer)] = 0;
		}
	}

	dProgress = 0;
	dDelta_Progress = (DOUBLE)100 /(DOUBLE)(BufferLength);

	BufferRead = BufferLength;

	do
	{
		if(FileStream)
			BufferLength = fread(Buffer,1,(UINT)BufferRead,FileStream);
		if(BufferLength)
			if(ucSignature_Type == BASE64_ENCODE)
				Buffer[BufferLength] = 0;
		Signature_Update(Buffer,BufferLength);
	}while(FileStream && !feof(FileStream));

	if(FileStream)
	{
		FileStream = (FILE *)(fclose(FileStream) & 0x0);
		delete [] Buffer;
	}

	if(Re_Entrant)
		return(Error = Success);
	else
		Re_Entrant = 1;

	if(IsMoreMsg)
		LPFnAddMsg();

	switch(ucSignature_Type)
	{
		case BASE64_ENCODE:
		{
			Base64_Encode_Final();
			Re_Entrant = 0;
			return(Error = Success);
			break;
		}
		case BASE64_DECODE:
		{
			Re_Entrant = 0;
			return(Error = Success);
			break;
		}
		default:
		{
			Signature_Final(Pass);
			break;
		}
	}

	if(ShowProgress)
		ShowProgress(100);

	if(Destination == 0)
		for(short i = 0;i <= ucDigest_Length - 1;i++)
			sprintf(Signature + i*2,(Case?"%02X":"%02x"),
											Hash.ucValues[i]);
	else
		if(OutPut.OutFileStream)
		{
			for(short i = 0;i <= ucDigest_Length - 1;i++)
				fprintf(OutPut.OutFileStream,(Case?"%02X":"%02x"),
											    Hash.ucValues[i]);
			OutPut.OutFileStream = (FILE *)(fclose(OutPut.OutFileStream) & 0x0);
		}
		else
			return(Error = File_Open_Error);

	Re_Entrant = 0;
	return(Error = Success);
}
#endif
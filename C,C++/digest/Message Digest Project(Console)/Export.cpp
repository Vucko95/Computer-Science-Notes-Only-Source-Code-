#ifndef _EXPORT_CPP_
#define _EXPORT_CPP_

#include "Signature_Context.cpp"

#define MD_API  __declspec(dllexport)
#define MD_CALL __stdcall

// Functions Prototypes
MD_API LONG MD_CALL CreateSignatureStr(UCHAR, LPSTR, ULONG, LPSTR, SHORT, \
								 UCHAR = 3,UCHAR = 0,SHORT = 0,\
								 LONG = NULL,LONG = NULL);

MD_API LONG MD_CALL CreateSignatureByte(UCHAR, LPSTR, ULONG, LPSTR, SHORT, \
								  UCHAR = 3,UCHAR = 0,SHORT = 0,\
								  LONG = NULL,LONG = NULL);

MD_API LONG MD_CALL AppendChunk(LPSTR,ULONG);

MD_API LONG MD_CALL GetDecodeLength(UCHAR,LONG,SHORT = 0);

MD_API INT MD_CALL GetErrorDescription(LONG,LPSTR);

// Functions Defination

/*******************************************************************/
/*  Name of function : CreateSignatureStr

	Parameters:
		 Signature_Type  : The Type of the Signature which is to be
						   produced. The Values can be  
						   [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17
						    18]
		 Message         : The Message which is to be process
					       can be a filename also.
		 BufferLength    : The Size of Message. If the Message is
						   filename then value is 0.
		 Signature       : Buffer which will return the calculated
						   Message Digest.
		 MD_Destination  : The Destination could be file or the 
						   character Pointer Signature
						   If Character Pointer then value is 0
						   If File then value is 1.
		 Pass		     : Number of Pass (Used for only HAVAL
						   algorithm) Default value is 3.
						   If Signature_Type is BASE64_ENCODE then 
						   Pass represents the breaklength Value
		 Case			 : To set the case to Upper to Lower
						   Value = 0 then Lower Case
						   Value = 1 then Lower Case
		 IsMoreMsg       : If more Message is there then any Positive
						   value or else 0. 	
		 LPFnShowProg    : A Function pointer which will be called to
						   show the progress.
	     LPFnAddMsg      : A Function Pointer which will be called so
						   as to add any remaining Message.

				
	Return Value : Error Value Codes
	
	Purpose : Exported Function which is to be called so as to
			  create the Message Digest in string Format
			  Also Computes the Base 64 Encoding, Base 64 Decoding.
*/
/*******************************************************************/

MD_API LONG MD_CALL CreateSignatureStr(UCHAR Signature_Type,LPSTR Message,
								 ULONG BufferLength,LPSTR Signature,
								 SHORT MD_Destination,UCHAR Pass,
								 UCHAR Case,SHORT IsMoreMsg,
								 LONG LPFnAddMsg,LONG LPFnShowProg)
{
	if(Message == NULL || Signature == NULL)
		return(Error = Uninitialized_Memory);

	if(Signature_Type < MD_4_128 || \
	   Signature_Type > BASE64_DECODE)
		return(Error = Invalid_Parameters_Signature_Type);

	if(IsMoreMsg && (LPFnAddMsg == NULL))
		return(Error = Invalid_Parameters_No_Function_Address);

	if(MD_Destination == 0 && Signature == NULL)
		return(Error = Invalid_Parameters_No_Signature_Memory);

	if(Signature_Type >= HAVAL_128 && Signature_Type <= HAVAL_256)
		if(Pass < 3 || Pass > 5)
			return(Error = Invalid_Parameters_Pass);

	if(Signature_Type == BASE64_ENCODE)
		if((Pass && Pass < 50) || (Pass > 132))
			return(Error = Invalid_Parameters_BreakLength);

	if(Signature_Type == BASE64_DECODE)
		Pass = 0;
		
	Context = new Signature_Context(Signature_Type,Pass);

	if(Context == NULL)
		return(Error = Out_Of_Memory_Error);

	Context->Create_Signature(Message,BufferLength,Signature,
							  MD_Destination,Pass,Case,
							  IsMoreMsg,LPFnAddMsg,LPFnShowProg);
	delete Context;
	Context = NULL;
	return(Error);
}

/*******************************************************************/
/*  Name of function : CreateSignatureByte

	Parameters:
		 Signature_Type  : The Type of the Signature which is to be
						   produced. The Values can be  
						   [1/2/3/4/5/6/7/8/9/10/11/12/13/14/15/16/17
						    18]
		 Message         : The Message which is to be process
					       can be a filename also.
		 BufferLength    : The Size of Message. If the Message is
						   filename then value is 0.
		 Signature       : Buffer which will return the calculated
						   Message Digest.
		 MD_Destination  : The Destination could be file or the 
						   character Pointer Signature
						   If Character Pointer then value is 0
						   If File then value is 1.
		 Pass		     : Number of Pass (Used for only HAVAL
						   algorithm) Default value is 3.
		 Case			 : To set the case to Upper to Lower
						   Value = 0 then Lower Case
						   Value = 1 then Lower Case
		 IsMoreMsg       : If more Message is there then any Positive
						   value or else 0. 	
		 LPFnShowProg    : A Function pointer which will be called to
						   show the progress.
	     LPFnAddMsg      : A Function Pointer which will be called so
						   as to add any remaining Message.

				
	Return Value : Error Value Codes
	
	Purpose : Exported Function which is to be called so as to
			  create the Message Digest in Byte Format.
			  Also Computes the Base 64 Encoding, Base 64 Decoding.
*/
/*******************************************************************/

MD_API LONG MD_CALL CreateSignatureByte(UCHAR Signature_Type,LPSTR Message,
								  ULONG BufferLength,LPSTR Signature,
								  SHORT MD_Destination,UCHAR Pass,
								  UCHAR Case,SHORT IsMoreMsg,
								  LONG LPFnAddMsg,LONG LPFnShowProg)
{
	if(Signature_Type == BASE64_ENCODE || \
					Signature_Type == BASE64_DECODE)
			return(CreateSignatureStr(Signature_Type,Message,
									  BufferLength,Signature,
									  MD_Destination,Pass,Case,
							          IsMoreMsg,LPFnAddMsg,
									  LPFnShowProg));
	LONG Err = Success;

	LONG Dgst_Len = GetDecodeLength(Signature_Type,1);
	
	PCHAR Local_Digest = new CHAR[Dgst_Len];

	if(Local_Digest == NULL)
		return(Error = Out_Of_Memory_Error);

	memset(Local_Digest,0,Dgst_Len);

	Err = CreateSignatureStr(Signature_Type,Message,
     					     BufferLength,Local_Digest,
							 0,Pass,1,IsMoreMsg,LPFnAddMsg,
							 LPFnShowProg);

	if(Err)
		return(Err);

	Dgst_Len >>= 2;

	UCHAR Temp1,Temp2,i,j;

	if(MD_Destination)
	{
		FILE * FStream = NULL;
		if((FStream = fopen(Signature,"wb")) == NULL)
		{
			delete [] Local_Digest;
			return(Error = File_IO_Error);
		}

		/* Convert String to Byte Format */
		for(i = 0 ; i < Dgst_Len ; i++)
		{
			Temp1 = Local_Digest[i] - 0x30;
			if(Temp1 > 0x09)
				Temp1 -= 0x07;

			Temp2 = Local_Digest[++i] - 0x30;
			if(Temp2 > 0x09)
				Temp2 -= 0x07;

			Temp1 = (Temp1 << 4) | Temp2;
			fprintf(FStream,"%c",Temp1);
		}
		FStream = (FILE *)fclose(FStream);
	}
	else
	{
		/* Convert String to Byte Format */
		for(i = 0, j = 0 ; i < Dgst_Len ; i++)
		{
			Temp1 = Local_Digest[i] - 0x30;
			if(Temp1 > 0x09)
				Temp1 -= 0x07;

			Temp2 = Local_Digest[++i] - 0x30;
			if(Temp2 > 0x09)
				Temp2 -= 0x07;

			Signature[j++] = (Temp1 << 4) | Temp2;
		}
	}                                                                         
	delete [] Local_Digest;                                                   
	return(Error = Success);                                                  
}                                                                                 
		
/********************************************************************/
/* Name of the Function  : AppendChunk

    Parameters: 

		 Message         : The Message which is to be process
					       can be a filename also.
		 BufferLength    : The Size of Message. If the Message is
						   filename then value is 0.

	Return Value : Error Value Codes
	
	Purpose : Exported Function which is to be called so as to
			  add more message to the existing transformation
*/
/*******************************************************************/

MD_API LONG MD_CALL AppendChunk(LPSTR Message, ULONG BufferLength)
{
	if (Context == NULL)
		return(Error = Uninitialized_Reference);
	
	if(BufferLength || strlen(Message) == 0)
		Context->Signature_Update(Message,BufferLength);
	else
		return(Error = Context->Create_Signature(Message,BufferLength\
												,"",0));
	return(Error = Success);
}

/********************************************************************/
/* Name of the Function  : GetDecodeLength

    Parameters: 

		 Type		     : The Signature Type for which the 
						   size isto be determined
		 Size			 : In Characters or Bytes
						   Value 0:- then in Characters
						   Value 1:- then in Bytes
						   If Type is BASE_64 then
						   Length of the string which is to be 
						   encoded
		 BreakLength     : Optional Parameter Initial Value = 0.
						   Specifies the Break Length of the 
						   encoded string
						   Used only when Type = BASE_64

    Return Value : Error Value Codes
	
	Purpose : Exported Function which is to be called so as to
			  get the decode length.
*/
/*******************************************************************/

MD_API LONG MD_CALL GetDecodeLength(UCHAR Type, LONG Size,SHORT BreakLength)
{
	LONG Length;

	switch(Type)
	{
		case BASE64_DECODE:
		{
			return((LONG)((Size + 3) >> 2) * 3);
			break;
		}
		case BASE64_ENCODE:
		{
			Length = ((Size + 2) / 3) << 2;
			return(BreakLength?Length+(Length/BreakLength)*2:Length);
			break;
		}
		case MD_4_128:
		case MD_5:
		case RIPEMD_128:
		case HAVAL_128:
		{
			Length = LENGTH_MD4_128_MD5_RIPEMD128_HAVAL128;
			break;
		}
		case SHA_1:
		case RIPEMD_160:
		case HAVAL_160:
		{
			Length = LENGTH_SHA1_RIPEMD160_HAVAL160;
			break;
		}
		case MD_4_256:
		case RIPEMD_256:
		case SHA_256:
		case HAVAL_256:
		{
			Length = LENGTH_MD4_256_RIPEMD256_SHA256_HAVAL256;
			break;
		}
		case HAVAL_192:
		{
			Length = LENGTH_HAVAL192;
			break;
		}
		case HAVAL_224:
		{
			Length = LENGTH_HAVAL224;
			break;
		}
		case RIPEMD_320:
		{
			Length = LENGTH_RIPEMD320;
			break;
		}
		case SHA_384:
		{
			Length = LENGTH_SHA384;
			break;
		}
		case SHA_512:
		{
			Length = LENGTH_SHA512;
			break;
		}
		default:
		{
			return(Error = Invalid_Parameters_Signature_Type);
			break;
		}
	}
	return((Length << (Size * 3)));
}

/********************************************************************/
/* Name of the Function  : GetErrorDescription

    Parameters: 

			Error  : The Error value returned by the Class
		
			Name   : The CHAR * where the description of the error
					 is returned

    Return Value : Length required for the description
	
	Purpose : Exported Function which is to be called so as to
			  get the error description of the error.
*/
/*******************************************************************/

MD_API INT MD_CALL GetErrorDescription(LONG Error, LPSTR Name)
{
	UCHAR Size = 0;
	if(Name == NULL)
		Size = 1;
	switch(Error)
	{
		case Invalid_Parameters_Signature_Type:
		{
			if(Size)
				return(strlen("Invalid Signature Type") + 1);
			else
				strcpy(Name,"Invalid Signature Type");
			break;
		}
		case Invalid_Parameters_No_Function_Address:
		{
			if(Size)
				return(strlen("Invalid Function Address") + 1);
			else
				strcpy(Name,"Invalid Function Address");
			break;
		}
		case Invalid_Parameters_No_Signature_Memory:
		{
			if(Size)
				return(strlen("Invalid Signature Memory") + 1);
			else
				strcpy(Name,"Invalid Signature Memory");
			break;
		}
		case Invalid_Parameters_Pass:
		{
			if(Size)
				return(strlen("Invalid Pass") + 1);
			else
				strcpy(Name,"Invalid Pass");
			break;
		}
		case File_Open_Error:
		{
			if(Size)
				return(strlen("File Open Error") + 1);
			else
				strcpy(Name,"File Open Error");
			break;
		}
		case File_Too_Long:
		{
			if(Size)
				return(strlen("File Too Long") + 1);
			else
				strcpy(Name,"File Too Long");
			break;
		}
		case File_IO_Error:
		{
			if(Size)
				return(strlen("File IO Error") + 1);
			else
				strcpy(Name,"File IO Error");
			break;
		}
		case Uninitialized_Reference:
		{
			if(Size)
				return(strlen("Uninitialized Reference") + 1);
			else
				strcpy(Name,"Uninitialized Reference");
			break;
		}
		case Out_Of_Memory_Error:
		{
			if(Size)
				return(strlen("Out Of Memory Error") + 1);
			else
				strcpy(Name,"Out Of Memory Error");
			break;
		}
		case Uninitialized_Memory:
		{
			if(Size)
				return(strlen("Uninitialized Memory") + 1);
			else
				strcpy(Name,"Uninitialized Memory");
			break;
		}
		case Success:
		{
			if(Size)
				return(strlen("No Error") + 1);
			else
				strcpy(Name,"No Error");
			break;
		}
		case Invalid_Parameters_BreakLength:
		{
			if(Size)
				return(strlen("Invalid_Parameters_BreakLength") + 1);
			else
				strcpy(Name,"Invalid Parameters BreakLength");
			break;
		}
		default:
		{
			if(Size)
				return(strlen("Invalid Error Number") + 1);
			else
				strcpy(Name,"Invalid Error Number");
			break;
		}
	}
	return(Success);
}

#endif

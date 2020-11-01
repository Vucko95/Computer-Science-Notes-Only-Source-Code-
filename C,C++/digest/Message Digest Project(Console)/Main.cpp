#include "Export.cpp"

#include "system.h"
#include "main.h"

BOOL Is_Display = true;

INT main(INT argc,PCHAR argv[])
{
	if(argc == 1)
	{
		Print_Error(NO_ARGS,true);
 		Print_Help();
		return(NO_ARGS);
	}
	UCHAR Signature_Type = MD_5;
	UCHAR Break_Length = 0;
	UCHAR Pass = 3;UCHAR Case = 0;
	CHAR Source_File[MD_MAX_LENGTH];
	CHAR Dest_File[MD_MAX_LENGTH];
	CHAR Check_File[MD_MAX_LENGTH];
	PCHAR Digest = NULL; PCHAR Temp1 = NULL;
	BOOL Of_Set = false; BOOL Ifc_Set = false;
	BOOL If_Set = false; BOOL Is_Base64enc = false;
	BOOL Local = true; BOOL Is_StrSet = true;
	
	for(UCHAR i = 1; i < argc; i++)
	{
		strlwr(argv[i]);
		if(strcmp(argv[i],"-help") == 0)
		{ 
			Print_Help();
			return(Success);
		}
		if(strcmp(argv[i],"-?") == 0)
		{
			Print_Help();
			return(Success);
		}
		if(strcmp(argv[i],"-s") == 0) Is_Display = false;
		if(strcmp(argv[i],"-uc") == 0) Case = 1;
		if(strcmp(argv[i],"-lc") == 0) Case = 0;
		if(strcmp(argv[i],"-str") == 0) Is_StrSet = true;
		if(strcmp(argv[i],"-byte") == 0) Is_StrSet = false;

		if(strncmp(argv[i],"-st",3) == 0)
		{
			Temp1 = argv[i];
			Temp1 += 3;
			Signature_Type = atoi(Temp1);
			Temp1 = NULL;
		}
		if(strncmp(argv[i],"-pass",5) == 0)
		{
			Temp1 = argv[i];
			Temp1 += 5;
			Pass = *Temp1;
			Temp1 = NULL;
		}
		if(strncmp(argv[i],"-bl",3) == 0)
		{
			Temp1 = argv[i];
			Temp1 += 3;
			Break_Length = atoi(Temp1);
			Temp1 = NULL;
		}
		if(strncmp(argv[i],"-if",3) == 0)
		{
			If_Set = true;
			Temp1 = argv[i];
			Temp1 += 3;
			strcpy(Source_File,Temp1);
			Temp1 = NULL;
		}
		if(strncmp(argv[i],"-of",3) == 0) 
		{
			Of_Set = true;
			Temp1 = argv[i];
			Temp1 += 3;
			strcpy(Dest_File,Temp1);
			Temp1 = NULL;
		}
		if(strncmp(argv[i],"-cf",3) == 0) 
		{
			Ifc_Set = true;
			Temp1 = argv[i];
			Temp1 += 3;
			strcpy(Check_File,Temp1);
			Temp1 = NULL;
		}
	}
	if(!If_Set)
	{
		Print_Error(NO_FILE,Local);
		return(NO_FILE);
	}
	/* Checks for the Base 64 Type */
	if(Signature_Type == BASE64_ENCODE ||\
				Signature_Type == BASE64_DECODE)
	{
		if(Ifc_Set || (!Of_Set))
		{
			Print_Error(INVALID_PARAMETERS,Local);
			return(INVALID_PARAMETERS);
		}
		Is_Base64enc = true;
	}
	LONG iError = Success;
	/* Prints the Header */
	if(Is_Base64enc)
		Print_Heading(Signature_Type,Source_File,
					 (Of_Set ?Dest_File:NULL),
					 (Ifc_Set?Check_File:NULL),Break_Length);
	else
		Print_Heading(Signature_Type,Source_File,
					 (Of_Set ?Dest_File:NULL),
					 (Ifc_Set?Check_File:NULL),Pass);
	/* If the Output File is Set */
	if(Of_Set)
	{
		if(!Is_Base64enc)
			if(Is_StrSet)
				iError = CreateSignatureStr(Signature_Type,
										 Source_File,0,Dest_File,
										 1,Pass,Case);
			else
				iError = CreateSignatureByte(Signature_Type,
										 Source_File,0,Dest_File,
										 1,Pass,Case);
		else
			if(Is_StrSet)
				iError = CreateSignatureStr(Signature_Type,
										 Source_File,0,Dest_File,
										 1,Break_Length,Case);
			else
				iError = CreateSignatureByte(Signature_Type,
										 Source_File,0,Dest_File,
										 1,Break_Length,Case);
		if(iError)
		{
			Print_Error(iError);
			return(iError);
		}
	}
	else /* if the Output File is not Set */
	{
		LONG Length;

		Length = GetDecodeLength(Signature_Type,
									   (Is_StrSet ? 1 : 0));
		
		Digest = new CHAR[Length];
		if(Digest == NULL)
		{
			Print_Error(Out_Of_Memory_Error);
			return(Out_Of_Memory_Error);
		}

		memset(Digest,0,Length);

		if(!Is_Base64enc)
			if(Is_StrSet)
				iError = CreateSignatureStr(Signature_Type,
											Source_File,0,Digest,
											0,Pass,Case);
			else
				iError = CreateSignatureByte(Signature_Type,
											Source_File,0,Digest,
											0,Pass,Case);
		else
			if(Is_StrSet)
				iError = CreateSignatureStr(Signature_Type,
											 Source_File,0,Digest,
											 0,Break_Length);
			else
				iError = CreateSignatureByte(Signature_Type,
											 Source_File,0,Digest,
											 0,Break_Length);
		if(iError)
		{
			Print_Error(iError);
			if(Digest)
			{
				delete [] Digest;
				Digest = NULL;
			}
			return(iError);
		}
	}
	/* If the Checking File Is Set */
	if(Ifc_Set)
	{
		if(Of_Set)
			iError = Check_Digest(Signature_Type,Check_File,
								  Dest_File,Case,Of_Set);
		else
			iError = Check_Digest(Signature_Type,Check_File,Digest,
									Case);
		Print_Error(iError,Local);
	}
	else
	{
		if(!Of_Set)
			printf("\n%s",Digest);
	}
	if(Digest)
	{
		delete [] Digest;
		Digest = NULL;
	}
	Print_Error(iError,Local); 
	return(iError);
}


VOID Print_Help(VOID)
{
	printf("\n\tMessage Digest Project \n");
	printf("\n Usage :-\n");
	printf(" MsgDgst.exe -stDigest_Type -passPass_NO -ifFile");
	printf(" -ofFile -cfFile -s [-uc/-lc] -str -byte\n\n");

	printf(" Description :- \n\n");
	printf("  -st   :- Signature Type Default value is MD5\n");	
	printf("  -pass :- Pass (Used only for HAVAL) Default value is 3\n");
	printf("  -bl	:- Break Length (Used only for BASE 64 ENCODING)\n");
	printf("  -if   :- File Name of which Digest is to be Computed\n");
	printf("  -of   :- File Name where the Digest is going to Store\n");
	printf("  -cf   :- File Name where the already created Digest is");
	printf(" Kept, \n\t   which is to be Checked\n");
	printf("  -s    :- Sets the Quit Mode\n");
	printf("  -uc	:- Sets the Output to Upper Case\n");
	printf("  -lc	:- Sets the Output to Lower Case\n");
	printf("  -str  :- Sets the String Output\n");
	printf("  -byte :- Sets the Byte Output\n\n");

	printf(" Digest_Type Values :- \n\n");
	printf("  1     :- MD4 128\n");
	printf("  2     :- MD4 256\n");
	printf("  3     :- MD5\n");
	printf("  4     :- RIPEMD 128\n");
	printf("  5     :- RIPEMD 160\n");
	printf("  6     :- RIPEMD 256\n");
	printf("  7     :- RIPEMD 320\n");
	printf("  8     :- SHA 1\n");
	printf("  9     :- SHA 256\n");
	printf("  10    :- SHA 384\n");
	printf("  11    :- SHA 512\n");
	printf("  12    :- HAVAL 128\n");
	printf("  13    :- HAVAL 160\n");
	printf("  14    :- HAVAL 192\n");
	printf("  15    :- HAVAL 224\n");
	printf("  16    :- HAVAL 256\n");
	printf("  17    :- BASE 64 ENCODING\n");
	printf("  18    :- BASE 64 DECODING\n\n");

	printf(" Pass Values :-  3, 4, 5 \n\n");

	printf(" BreakLength :-  Should be Greater than 50 and Less than 132\n");

	printf("\n Project Done By Mr. Shinde Vikram V.");
	printf("\n M. Sc. Computer Science Part-II");
	printf("\n K. M. C. College, Khopoli");
	printf("\n Under the Guidance of Lect. Shyam R. Soni\n");
}

VOID Print_Error(LONG Error, BOOL Local)
{
	if(!Is_Display)
		return;
	if(!Local)
	{
		PCHAR Message = NULL;
		Message = new CHAR[GetErrorDescription(Error,Message)];
		if(Message)
		{
			GetErrorDescription(Error,Message);
			printf("\n%s",Message);
			printf("\n");
			delete [] Message;
			Message = NULL;
		}
	}
	else
	{
		switch(Error)
		{
			case NO_ARGS:
			{
				printf("\nNo Arguments \n");
				break;
			}
			case NO_FILE:
			{
				printf("\nNo File is Given \n");
				break;
			}
			case INVALID_FILE:
			{
				printf("\nFile Given is Invalid \n");
				break;
			}
			case INVALID_PARAMETERS:
			{
				printf("\nInvalid Arguments \n");
				break;
			}
			case NO_MATCH:
			{
				printf("\nNo Match of The Signature \n");
				break;
			}
			case SUCCESS_MATCH:
			{
				printf("\nSuccessfull Match of The Signature \n");
				break;
			}
			case NO_MEM:
			{
				printf("\nOut Of Memory \n");
				break;
			}

			default:
			{
				printf("\nSuccess \n");
				break;
			}
		}
	}
}

VOID Print_Heading(UCHAR Type,PCHAR Source,PCHAR Dest,PCHAR Check,
				   UCHAR Pass)
{
	if(!Is_Display)
		return;
	UCHAR IsPass = 0;
	UCHAR IsBreak = 0;
	printf("\nYou Had Given Following Arguments");
	switch(Type)
	{
		case MD_4_128:
		{
			printf("\nSignature Type   :- MD-4 128 Bit");
			break;
		}
		case MD_4_256:
		{
			printf("\nSignature Type   :- MD-4 258 Bit");
			break;
		}
		case MD_5:
		{
			printf("\nSignature Type   :- MD-5 128 Bit");
			break;
		}
		case RIPEMD_128:
		{
			printf("\nSignature Type   :- RIPEMD 128 Bit");
			break;
		}
		case RIPEMD_160:
		{
			printf("\nSignature Type   :- RIPEMD 160 Bit");
			break;
		}
		case RIPEMD_256:
		{
			printf("\nSignature Type   :- RIPEMD 256 Bit");
			break;
		}
		case RIPEMD_320:
		{
			printf("\nSignature Type   :- RIPEMD 320 Bit");
			break;
		}
		case SHA_1:
		{
			printf("\nSignature Type   :- SHA-1");
			break;
		}
		case SHA_256:
		{
			printf("\nSignature Type   :- SHA 256 Bit");
			break;
		}
		case SHA_384:
		{
			printf("\nSignature Type   :- SHA 384 Bit");
			break;
		}
		case SHA_512:
		{
			printf("\nSignature Type   :- SHA 512 Bit");
			break;
		}
		case HAVAL_128:
		{
			printf("\nSignature Type   :- HAVAL 128 Bit");
			IsPass = 1;
			break;
		}
		case HAVAL_160:
		{
			printf("\nSignature Type   :- HAVAL 160 Bit");
			IsPass = 1;
			break;
		}
		case HAVAL_192:
		{
			printf("\nSignature Type   :- HAVAL 193 Bit");
			IsPass = 1;
			break;
		}
		case HAVAL_224:
		{
			printf("\nSignature Type   :- HAVAL 224 Bit");
			IsPass = 1;
			break;
		}
		case HAVAL_256:
		{
			printf("\nSignature Type   :- HAVAL 256 Bit");
			IsPass = 1;
			break;
		}
		case BASE64_ENCODE:
		{
			printf("\nSignature Type   :- BASE 64 ENCODING");
			IsBreak = 1;
			break;
		}
		case BASE64_DECODE:
		{
			printf("\nSignature Type   :- BASE 64 DECODING");
			IsBreak = 1;
			break;
		}
	}

	printf("\nSource File      :- %s",Source);
	if(Dest)
		printf("\nDestination File :- %s",Dest);
	if(Check)
		printf("\nChecking File    :- %s",Check);
	if(IsPass)
		printf("\nPass Number is   :- %d",Pass);
	if(IsBreak)
		printf("\nBreak Length is  :- %d",Pass);
	printf("\n");

}
			
LONG Check_Digest(UCHAR Type,PCHAR Filename,PCHAR Digest,
				  BOOL Case,BOOL File)
{		
	FILE * OFStream = NULL;
	PCHAR OFileBuffer = NULL;

	LONG Digest_Length = GetDecodeLength(Type,0) << 1;

	if((OFStream = fopen(Filename,"rb")) == NULL)
		return(INVALID_FILE);

	LONG FSize = _filelength(_fileno(OFStream)); 

	if(FSize < Digest_Length)
		return(NO_MATCH);

	OFileBuffer = new CHAR[Digest_Length];
	if(OFileBuffer == NULL)
	{
		OFStream = (FILE *) fclose(OFStream);
		return(NO_MEM);
	}
	memset(OFileBuffer,NULL,Digest_Length);

	fread(OFileBuffer,1,(UINT)Digest_Length,OFStream);

	OFStream = (FILE *) fclose(OFStream);

	if(File)
	{
		FILE * IFStream = NULL;

		PCHAR IFileBuffer = NULL;

		if((IFStream = fopen(Digest,"rb")) == NULL)
		{
			delete [] OFileBuffer;	
			return(INVALID_FILE);
		}

		IFileBuffer = new CHAR[Digest_Length];
		if(IFileBuffer == NULL)
		{
			IFStream = (FILE *) fclose(IFStream);
			return(NO_MEM);
		}
		
		memset(IFileBuffer,NULL,Digest_Length);
	
		fread(IFileBuffer,1,(UINT)Digest_Length,IFStream);

		IFStream = (FILE *) fclose(IFStream);

		if(Case)
		{
			IFileBuffer = strlwr(IFileBuffer);
			OFileBuffer = strlwr(OFileBuffer);
		}
		else
		{
			IFileBuffer = strupr(IFileBuffer);
			OFileBuffer = strupr(OFileBuffer);
		}
		if(strncmp(IFileBuffer,OFileBuffer,Digest_Length) == 0)
		{
				delete [] IFileBuffer;	
				delete [] OFileBuffer;	
				return(SUCCESS_MATCH);
		}
		else
		{
				delete [] IFileBuffer;	
				delete [] OFileBuffer;	
				return(NO_MATCH);
		}
	}
	else
	{
		if(Case)
		{
			OFileBuffer = strlwr(OFileBuffer);
			Digest = strlwr(Digest);
		}
		else
		{
			OFileBuffer = strupr(OFileBuffer);
			Digest = strupr(Digest);
		}
		if(strncmp(Digest,OFileBuffer,Digest_Length) == 0)
		{
				delete [] OFileBuffer;	
				return(SUCCESS_MATCH);
		}
		else
		{
			delete [] OFileBuffer;	
			return(NO_MATCH);
		}
	}
	return(Success);
}





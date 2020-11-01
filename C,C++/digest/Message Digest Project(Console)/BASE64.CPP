#ifndef _BASE64_CPP_
#define _BASE64_CPP_

/*******************************************************************/
/*  Name of function : BASE64_Encode_Update

	Parameters: Nothing
				
	Return Value : Nothing
	
	Purpose : Private Member Function Used for Updating the BASE 64 
			  Encoding
*/
/*******************************************************************/

VOID Signature_Context::BASE64_Encode_Update(PCHAR Buff, ULONG &Len)
{  
	UCHAR &Current_Pos = Code_Convertor.ucChar_Codes[4];

	UCHAR Temp[4];


	while(Len)
	{
		Current_Pos %= 3;
		do
		{
			Code_Convertor.ucChar_Codes[2 - (Current_Pos++) % 3] \
				                                = *Buff++;
			Len--;
		}while((Current_Pos % 3) && Len);
		
		if(Current_Pos % 3)
			return;

		Temp[0] = Hash.ucValues[Code_Convertor.Bits.Bit_1];
		Temp[1] = Hash.ucValues[Code_Convertor.Bits.Bit_2];
		Temp[2] = Hash.ucValues[Code_Convertor.Bits.Bit_3];
		Temp[3] = Hash.ucValues[Code_Convertor.Bits.Bit_4];
		
		for(UCHAR i = 0; i < 4; i++)
		{
			if(ucCheck)
				fprintf(OutPut.OutFileStream,"%c",Temp[i]);
			else
				*(OutPut.lpChar++) = Temp[i];
	
			Code_Convertor.ucChar_Codes[6]++;

			if(Code_Convertor.ucChar_Codes[5] && \
				(Code_Convertor.ucChar_Codes[6] == \
						Code_Convertor.ucChar_Codes[5]))
			{

				if(ucCheck)
					fprintf(OutPut.OutFileStream,"%c%c",0x0D,0x0A);
				else
				{
					*(OutPut.lpChar++) = 0x0D; // cr
					*(OutPut.lpChar++) = 0x0A; // lf
				}
				Code_Convertor.ucChar_Codes[6] = 0;
			}
		}
	}//while ends
}

/*******************************************************************/
/*  Name of function : BASE64_Encode_Final

	Parameters: Nothing
				
	Return Value : Nothing
	
	Purpose : Private Member Function for finalizing the BASE 64 
			  Encoding
*/
/*******************************************************************/

VOID Signature_Context::Base64_Encode_Final(VOID)
{
	UCHAR &Current_Pos = Code_Convertor.ucChar_Codes[4];
	Current_Pos %= 3;

	if(Current_Pos)
	{
		UCHAR Temp[4];
		Code_Convertor.ucChar_Codes[Current_Pos % 2] = 0;
		Code_Convertor.ucChar_Codes[0] = 0;
		
		Temp[0] = Hash.ucValues[Code_Convertor.Bits.Bit_1];
		Temp[1] = Hash.ucValues[Code_Convertor.Bits.Bit_2];
		Temp[2] = (Current_Pos == 2) ? Hash.ucValues[Code_Convertor.Bits.Bit_3]:'=';
		Temp[3] = '=';
	
		for(UCHAR i = 0; i < 4; i++)
		{
			if(ucCheck)
				fprintf(OutPut.OutFileStream,"%c",Temp[i]);
			else
				*(OutPut.lpChar++) = Temp[i];
	
			Code_Convertor.ucChar_Codes[6]++;

			if(Code_Convertor.ucChar_Codes[5] && \
				(Code_Convertor.ucChar_Codes[6] == \
						Code_Convertor.ucChar_Codes[5]))
			{

				if(ucCheck)
					fprintf(OutPut.OutFileStream,"%c%c",0x0D,0x0A);
				else
				{
					*(OutPut.lpChar++) = 0x0D; // cr
					*(OutPut.lpChar++) = 0x0A; // lf
				}
				Code_Convertor.ucChar_Codes[6] = 0;
			}
		}
	}
	return;
}

/*******************************************************************/
/*  Name of function : BASE64_Decode

	Parameters: Nothing
				
	Return Value : Nothing
	
	Purpose : Private Member Function Used for doing the BASE 64 
			  Decoding
*/
/*******************************************************************/

VOID Signature_Context::BASE64_Decode(PCHAR Buff)
{
	if(*Buff == NULL)
		return;
	PCHAR Value = NULL;
	UCHAR Result = 0, &Counter = Code_Convertor.ucChar_Codes[5];

	while(*Buff && *Buff != '=')
	{
		if((*Buff == '/') || ((Value = strchr((const PCHAR)Hash.ucValues,*Buff)) != NULL))
		{
			Result = (*Buff == '/'? 63 : (Value - (PCHAR)Hash.ucValues));
			Counter++;
			switch(Counter)
			{
				case 1:
				{
					Code_Convertor.Bits.Bit_1 = Result;
					break;
				}
				case 2:
				{
					Code_Convertor.Bits.Bit_2 = Result;
					break;
				}
				case 3:
				{
					Code_Convertor.Bits.Bit_3 = Result;
					break;
				}
				case 4:
				{
					Code_Convertor.Bits.Bit_4 = Result;
					for(Counter = 3; Counter > 0 ; Counter--)
						if(ucCheck)
							fprintf(OutPut.OutFileStream,"%c",
								Code_Convertor.ucChar_Codes[Counter-1]);
						else
							*(OutPut.lpChar++) = \
								Code_Convertor.ucChar_Codes[Counter-1];

					Code_Convertor.ucChar_Codes[0] = 0;
					Code_Convertor.ucChar_Codes[1] = 0;
					Code_Convertor.ucChar_Codes[2] = 0;
					break;
				}
			}
		}
		Buff++;
	}// while ends
	
	if(Counter)
	{
		if(ucCheck)
			fprintf(OutPut.OutFileStream,"%c",
				Code_Convertor.ucChar_Codes[2]);
		else
			*(OutPut.lpChar++) = \
				Code_Convertor.ucChar_Codes[2];

		if(Code_Convertor.ucChar_Codes[1])
			if(ucCheck)
				fprintf(OutPut.OutFileStream,"%c",
					Code_Convertor.ucChar_Codes[1]);
			else
				*(OutPut.lpChar++) = \
					Code_Convertor.ucChar_Codes[1];

		if(Code_Convertor.ucChar_Codes[0])
			if(ucCheck)
				fprintf(OutPut.OutFileStream,"%c",
					Code_Convertor.ucChar_Codes[0]);
			else
				*(OutPut.lpChar++) = \
					Code_Convertor.ucChar_Codes[0];
	}
	if(ucCheck)
		OutPut.OutFileStream = (FILE *)(fclose(OutPut.OutFileStream) & 0x0);
}
#endif
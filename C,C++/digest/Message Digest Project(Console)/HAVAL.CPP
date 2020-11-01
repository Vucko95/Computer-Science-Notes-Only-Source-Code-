#ifndef _HAVAL_CPP_
#define _HAVAL_CPP_
/*******************************************************************/
/*  Name of function : HAVAL_Transform

	Parameters: Pass [3/4/5]
				The Number of Pass in the Algorithm
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in HAVAL Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::HAVAL_Transform(SHORT Pass)
{
	register ULONG H1,H2,H3,H4,H5,H6,H7,H8,Temp,Result;

	// Transferring the Initial Hash Values 
	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];
	H5 = Hash.ulValues[4];
	H6 = Hash.ulValues[5];
	H7 = Hash.ulValues[6];
	H8 = Hash.ulValues[7];

	switch(Pass)
	{
		case 3:
		{
			/* Pass - 1 */
			/* 01 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_3_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 2 */
			/* 01 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x452821E6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x38D01377;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xBE5466CF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0x34E90C6C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0xC0AC29B7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xC97C50DD;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x3F84D5B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xB5470917;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x9216D5D9;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0x8979FB1B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0xD1310BA6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x98DFB5AC;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x2FFD72DB;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0xD01ADFB7L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xB8E1AFED;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x6A267E96;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xBA7C9045;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0xF12C7F99;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x24A19947;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0xB3916CF7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x0801F2E2;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x858EFC16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x636920D8;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x71574E69;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0xA458FEA3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xF4933D7E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x0D95748F;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x728EB658;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x718BCD58;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0x82154AEE;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x7B54A41D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_3_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0xC25A59B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 3 */
			/* 01 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x9C30D539;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0x2AF26013;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xC5D1B023;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0x286085F0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xCA417918;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0xB8DB38EF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x8E79DCB0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x603A180E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x6C9E0E8B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0xB01E8A3E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xD71577C1;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xBD314B27;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x78AF2FDA;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0x55605C60;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xE65525F3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xAA55AB94L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x57489862;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x63E81440;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x55CA396A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0x2AAB10B6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0xB4CC5C34;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x1141E8CEL;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xA15486AF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0x7C72E993L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0xB3EE1411;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x636FBC2A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x2BA9C55D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0x741831F6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xCE5C3E16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x9B87931E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0xAFD6BA33;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_3_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x6C24CF5C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			break;
		}
		case 4:
		{
			/* Pass - 1 */
			/* 01 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_4_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 2 */
			/* 01 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x452821E6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x38D01377;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xBE5466CF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0x34E90C6C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0xC0AC29B7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xC97C50DD;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x3F84D5B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xB5470917;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x9216D5D9;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0x8979FB1B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0xD1310BA6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x98DFB5AC;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x2FFD72DB;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0xD01ADFB7L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xB8E1AFED;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x6A267E96;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xBA7C9045;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0xF12C7F99;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x24A19947;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0xB3916CF7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x0801F2E2;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x858EFC16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x636920D8;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x71574E69;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0xA458FEA3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xF4933D7E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x0D95748F;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x728EB658;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x718BCD58;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0x82154AEE;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x7B54A41D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_4_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0xC25A59B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 3 */
			/* 01 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x9C30D539;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0x2AF26013;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xC5D1B023;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0x286085F0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xCA417918;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0xB8DB38EF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x8E79DCB0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x603A180E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x6C9E0E8B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0xB01E8A3E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xD71577C1;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xBD314B27;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x78AF2FDA;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0x55605C60;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xE65525F3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xAA55AB94L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x57489862;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x63E81440;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x55CA396A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0x2AAB10B6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0xB4CC5C34;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x1141E8CEL;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xA15486AF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0x7C72E993L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0xB3EE1411;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x636FBC2A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x2BA9C55D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0x741831F6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xCE5C3E16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x9B87931E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0xAFD6BA33;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_4_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x6C24CF5C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 4 */
			/* 01 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x7A325381;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0x28958677;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x3B8F4898;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x6B4BB9AF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0xC4BFE81B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x66282193;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0x61D809CC;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xFB21A991;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0x487CAC60;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x5DEC8032;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xEF845D5D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0xE98575B1;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xDC262302;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xEB651B88;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x23893E81;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0xD396ACC5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x0F6D6FF3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x83F44239;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x2E0B4482;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0xA4842004;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x69C8F04A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0x9E1F9B5E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0x21C66842;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0xF6E96C9A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x670C9C61;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0xABD388F0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x6A51A0D2;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0xD8542F68;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x960FA728;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0xAB5133A3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0x6EEF0B6C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_4_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x137A3BE4;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			break;
		}
		case 5:
		{
			/* Pass - 1 */
			/* 01 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_5_1(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31];
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 2 */
			/* 01 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x452821E6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x38D01377;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xBE5466CF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0x34E90C6C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0xC0AC29B7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xC97C50DD;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x3F84D5B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xB5470917;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x9216D5D9;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0x8979FB1B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0xD1310BA6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x98DFB5AC;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x2FFD72DB;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0xD01ADFB7L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xB8E1AFED;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x6A267E96;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xBA7C9045;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0xF12C7F99;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x24A19947;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0xB3916CF7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x0801F2E2;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x858EFC16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x636920D8;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x71574E69;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0xA458FEA3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xF4933D7E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x0D95748F;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x728EB658;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x718BCD58;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0x82154AEE;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x7B54A41D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_5_2(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0xC25A59B5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 3 */
			/* 01 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x9C30D539;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0x2AF26013;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0xC5D1B023;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0x286085F0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0xCA417918;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0xB8DB38EF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x8E79DCB0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x603A180E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x6C9E0E8B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0xB01E8A3E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xD71577C1;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xBD314B27;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x78AF2FDA;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0x55605C60;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xE65525F3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0xAA55AB94L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x57489862;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x63E81440;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x55CA396A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0x2AAB10B6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0xB4CC5C34;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x1141E8CEL;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xA15486AF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0x7C72E993L;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0xB3EE1411;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x636FBC2A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0x2BA9C55D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0x741831F6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xCE5C3E16;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x9B87931E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0xAFD6BA33;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_5_3(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x6C24CF5C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 4 */
			/* 01 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x7A325381;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0x28958677;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x3B8F4898;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x6B4BB9AF;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0xC4BFE81B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x66282193;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0x61D809CC;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xFB21A991;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0x487CAC60;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x5DEC8032;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xEF845D5D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0xE98575B1;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xDC262302;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xEB651B88;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x23893E81;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0xD396ACC5;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0x0F6D6FF3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x83F44239;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x2E0B4482;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0xA4842004;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x69C8F04A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0x9E1F9B5E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0x21C66842;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0xF6E96C9A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x670C9C61;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0xABD388F0;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x6A51A0D2;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0xD8542F68;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x960FA728;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0xAB5133A3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0x6EEF0B6C;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_5_4(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x137A3BE4;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* Pass - 5 */
			/* 01 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[27] + 0xBA3BF050;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 02 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[3] + 0x7EFB2A98;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 03 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[21] + 0xA1F1651D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 04 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[26] + 0x39AF0176;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 05 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[17] + 0x66CA593E;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
	
			/* 06 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[11] + 0x82430E88;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 07 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[20] + 0x8CEE8619;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 08 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[29] + 0x456F9FB4;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 09 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[19] + 0x7D84A5C3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 10 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[0] + 0x3B8B5EBE;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 11 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[12] + 0xE06F75D8;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 12 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[7] + 0x85C12073;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 13 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[13] + 0x401A449F;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 14 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[8] + 0x56C16AA6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 15 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[31] + 0x4ED3AA62;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 16 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[10] + 0x363F7706;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 17 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[5] + 0x1BFEDF72;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 18 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[9] + 0x429B023D;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 19 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[14] + 0x37D0D724;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 20 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[30] + 0xD00A1248;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 21 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[18] + 0xDB0FEAD3;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 22 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[6] + 0x49F1C09B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 23 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[28] + 0x075372C9;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 24 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[24] + 0x80991B7B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 25 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[2] + 0x25D479D8;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 26 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[23] + 0xF6E8DEF7;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 27 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[16] + 0xE3FE501A;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 28 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[22] + 0xB6794C3B;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 29 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[4] + 0x976CE0BD;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 30 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[1] + 0x04C006BA;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 31 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[25] + 0xC1A94FB6;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;

			/* 32 */
			Temp = Fphi_5_5(H7,H6,H5,H4,H3,H2,H1);
			Result = Rotate_Right(Temp, 7,_32BIT) + \
					 Rotate_Right(H8, 11,_32BIT);
			Result += Message.Block.ulValues[15] + 0x409F60C4;
			H8 = H7; H7 = H6; H6 = H5; H5 = H4; H4 = H3;
			H3 = H2; H2 = H1; H1 = Result;
		
			break;
		}
	}

		Hash.ulValues[0] += H1;
		Hash.ulValues[1] += H2;
		Hash.ulValues[2] += H3;
		Hash.ulValues[3] += H4;
		Hash.ulValues[4] += H5;
		Hash.ulValues[5] += H6;
		Hash.ulValues[6] += H7;
		Hash.ulValues[7] += H8;
}

/*******************************************************************/
/*  Name of function : HAVAL_Tailor

	Parameters: Nothing
				
	Return Value : Nothing
	
	Purpose : Private Member Function for tailoring the output for 
			  HAVAL
*/
/*******************************************************************/

VOID Signature_Context::HAVAL_Tailor(VOID)
{
	switch(ucSignature_Type)
	{
		case HAVAL_256:
			break;
		case HAVAL_128:
		{
			union
			{
				ULONG ulValue;
				UCHAR ucSplit[4];
			}Haval128_0,Haval128_1,Haval128_2,Haval128_3,Temp;
			
			Haval128_0.ulValue = Hash.ulValues[7];
			Haval128_1.ulValue = Hash.ulValues[6];
			Haval128_2.ulValue = Hash.ulValues[5];
			Haval128_3.ulValue = Hash.ulValues[4];

			// Fourth Hash Value
			Temp.ucSplit[3] = Haval128_0.ucSplit[3];
			Temp.ucSplit[2] = Haval128_1.ucSplit[2];
			Temp.ucSplit[1] = Haval128_2.ucSplit[1];
			Temp.ucSplit[0] = Haval128_3.ucSplit[0];
		
			Hash.ulValues[3] += Temp.ulValue;

			// Third Hash Value
			Temp.ucSplit[3] = Haval128_0.ucSplit[2];
			Temp.ucSplit[2] = Haval128_1.ucSplit[1];
			Temp.ucSplit[1] = Haval128_2.ucSplit[0];
			Temp.ucSplit[0] = Haval128_3.ucSplit[3];
		
			Hash.ulValues[2] += Temp.ulValue;

			// Second Hash Value
			Temp.ucSplit[3] = Haval128_0.ucSplit[1];
			Temp.ucSplit[2] = Haval128_1.ucSplit[0];
			Temp.ucSplit[1] = Haval128_2.ucSplit[3];
			Temp.ucSplit[0] = Haval128_3.ucSplit[2];
		
			Hash.ulValues[1] += Temp.ulValue;
			
			// First Hash Value
			Temp.ucSplit[3] = Haval128_0.ucSplit[0];
			Temp.ucSplit[2] = Haval128_1.ucSplit[3];
			Temp.ucSplit[1] = Haval128_2.ucSplit[2];
			Temp.ucSplit[0] = Haval128_3.ucSplit[1];
		
			Hash.ulValues[0] += Temp.ulValue;
			break;
		}
		case HAVAL_160:
		{
			union
			{
				ULONG ulValue;
				struct
				{
					unsigned Six_0  :6;
					unsigned Six_1  :6;
					unsigned Seven_2:7;
					unsigned Six_3  :6;
					unsigned Seven_4:7;
				}Bits;

				struct
				{
					unsigned Seven_0:7;
					unsigned Six_1	:6;
					unsigned Seven_2:7;
				}Fourth_Hash;

				struct
				{
					unsigned Six_0  :6;
					unsigned Seven_1:7;
					unsigned Six_2  :6;
				}Zeroth_Third_Hash;

				struct
				{
					unsigned Seven_0:7;
					unsigned Six_1  :6;
					unsigned Six_2  :6;
				}First_Hash;
			}Haval160_0,Haval160_1,Haval160_2,Temp;

			Haval160_0.ulValue = Hash.ulValues[7];
			Haval160_1.ulValue = Hash.ulValues[6];
			Haval160_2.ulValue = Hash.ulValues[5];

			// Fourth Hash Value
			Temp.ulValue = 0;
			Temp.Fourth_Hash.Seven_2 = Haval160_0.Bits.Seven_4;
			Temp.Fourth_Hash.Six_1   = Haval160_1.Bits.Six_3;
			Temp.Fourth_Hash.Seven_0 = Haval160_2.Bits.Seven_2;

			Hash.ulValues[4] += Temp.ulValue;

			// Third Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_Third_Hash.Six_2  = \
									Haval160_0.Bits.Six_3;
			Temp.Zeroth_Third_Hash.Seven_1= \
									Haval160_1.Bits.Seven_2;
			Temp.Zeroth_Third_Hash.Six_0  = \
									Haval160_2.Bits.Six_1;

			Hash.ulValues[3] += Temp.ulValue;

			// Second Hash Value
			Temp.ulValue = 0;
			Temp.Bits.Seven_2 = Haval160_0.Bits.Seven_2;
			Temp.Bits.Six_1   = Haval160_1.Bits.Six_1;
			Temp.Bits.Six_0   = Haval160_2.Bits.Six_0;

			Hash.ulValues[2] += Temp.ulValue;

			// First Hash Value
			Temp.ulValue = 0;
			Temp.First_Hash.Six_2   = Haval160_0.Bits.Six_1;
			Temp.First_Hash.Six_1   = Haval160_1.Bits.Six_0;
			Temp.First_Hash.Seven_0 = Haval160_2.Bits.Seven_4;

			Hash.ulValues[1] += Temp.ulValue;

			// Zeroth Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_Third_Hash.Six_2  = \
									Haval160_0.Bits.Six_0;
			Temp.Zeroth_Third_Hash.Seven_1= \
									Haval160_1.Bits.Seven_4;
			Temp.Zeroth_Third_Hash.Six_0  = \
									Haval160_2.Bits.Six_3;

			Hash.ulValues[0] += Temp.ulValue;

			break;
		}
		case HAVAL_192:
		{
			union
			{
				ULONG ulValue;
				struct
				{
					unsigned Five_0 :5;
					unsigned Five_1 :5;
					unsigned Six_2  :6;
					unsigned Five_3 :5;
					unsigned Five_4 :5;
					unsigned Six_5  :6;
				}Bits;
				
				struct
				{
					unsigned Five_0 :5;
					unsigned Six_1  :6;
				}Second_Fifth;

				struct
				{
					unsigned Five_0 :5;
					unsigned Five_1 :5;
				}First_Fourth;

				struct
				{
					unsigned Six_0  :6;
					unsigned Five_1 :5;
				}Zeroth_Third;
			}Haval192_0,Haval192_1,Temp;

			Haval192_0.ulValue = Hash.ulValues[7];
			Haval192_1.ulValue = Hash.ulValues[6];
			
			// Fifth Hash Value
			Temp.ulValue = 0;
			Temp.Second_Fifth.Six_1  = Haval192_0.Bits.Six_5;
			Temp.Second_Fifth.Five_0 = Haval192_1.Bits.Five_4;

			Hash.ulValues[5] += Temp.ulValue;
			
			// Fourth Hash Value
			Temp.ulValue = 0;
			Temp.First_Fourth.Five_1 = Haval192_0.Bits.Five_4;
			Temp.First_Fourth.Five_0 = Haval192_1.Bits.Five_3;

			Hash.ulValues[4] += Temp.ulValue;

			// Third Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_Third.Five_1 = Haval192_0.Bits.Five_3;
			Temp.Zeroth_Third.Six_0  = Haval192_1.Bits.Six_2;

			Hash.ulValues[3] += Temp.ulValue;

			// Second Hash Value
			Temp.ulValue = 0;
			Temp.Second_Fifth.Six_1  = Haval192_0.Bits.Six_2;
			Temp.Second_Fifth.Five_0 = Haval192_1.Bits.Five_1;

			Hash.ulValues[2] += Temp.ulValue;
			
			// First Hash Value
			Temp.ulValue = 0;
			Temp.First_Fourth.Five_1 = Haval192_0.Bits.Five_1;
			Temp.First_Fourth.Five_0 = Haval192_1.Bits.Five_0;

			Hash.ulValues[1] += Temp.ulValue;

			// Zeroth Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_Third.Five_1 = Haval192_0.Bits.Five_0;
			Temp.Zeroth_Third.Six_0  = Haval192_1.Bits.Six_5;

			Hash.ulValues[0] += Temp.ulValue;

			break;
		}
		case HAVAL_224:
		{
			union
			{
				ULONG ulValue;
				struct
				{
					unsigned Four_0 :4;
					unsigned Five_1 :5;
					unsigned Four_2 :4;
					unsigned Five_3 :5;
					unsigned Four_4 :4;
					unsigned Five_5 :5;
					unsigned Five_6 :5;
				}Bits;

				struct
				{
					unsigned Four :4;
				}Second_Fourth_Sixth;

				struct
				{
					unsigned Five :5;
				}Zeroth_First_Third_Fifth;
			}Haval224,Temp;

			Haval224.ulValue = Hash.ulValues[7];

			// Sixth Hash Value
			Temp.ulValue = 0;
			Temp.Second_Fourth_Sixth.Four = Haval224.Bits.Four_0;

			Hash.ulValues[6] += Temp.ulValue;

			// Fifth Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_First_Third_Fifth.Five = Haval224.Bits.Five_1;

			Hash.ulValues[5] += Temp.ulValue;

			// Fourth Hash Value
			Temp.ulValue = 0;
			Temp.Second_Fourth_Sixth.Four = Haval224.Bits.Four_2;

			Hash.ulValues[4] += Temp.ulValue;

			// Third Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_First_Third_Fifth.Five = Haval224.Bits.Five_3;

			Hash.ulValues[3] += Temp.ulValue;

			// Second Hash Value
			Temp.ulValue = 0;
			Temp.Second_Fourth_Sixth.Four = Haval224.Bits.Four_4;

			Hash.ulValues[2] += Temp.ulValue;

			// First Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_First_Third_Fifth.Five = Haval224.Bits.Five_5;

			Hash.ulValues[1] += Temp.ulValue;

			// Zeroth Hash Value
			Temp.ulValue = 0;
			Temp.Zeroth_First_Third_Fifth.Five = Haval224.Bits.Five_6;

			Hash.ulValues[0] += Temp.ulValue;

			break;
		}
	}		
}

#endif
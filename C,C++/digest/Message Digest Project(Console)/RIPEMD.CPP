#ifndef _RIPEMD_CPP_
#define _RIPEMD_CPP_
/*******************************************************************/
/*  Name of function : RIPEMD_128_256_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in RIPEMD-128 and RIPEMD-256 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::RIPEMD_128_256_Transform(VOID)
{
	register ULONG H1,H2,H3,H4, H_1,H_2,H_3,H_4;
	register ULONG Temp;

	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];

	if(ucSignature_Type == RIPEMD_128)
	{
		H_1 = H1;
		H_2 = H2;
		H_3 = H3;
		H_4 = H4;
	}
	else
	{
		H_1 = Hash.ulValues[4];
		H_2 = Hash.ulValues[5];
		H_3 = Hash.ulValues[6];
		H_4 = Hash.ulValues[7];
	}

	/* j = 0 to 15 */
	/* 00 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 01 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 02 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 03 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 04 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 05 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 06 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 07 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 08 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 09 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 10 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 11 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 12 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 13 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 14 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 15 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	if(ucSignature_Type == RIPEMD_256)
	{
		Temp = H1; H1 = H_1; H_1 = Temp;
	}

	/* j = 16 to 32 */
	/* 16 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 17 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 18 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 19 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 20 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 21 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 22 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 23 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 24 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 25 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 26 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 27 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 28 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 29 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 30 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 31 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	if(ucSignature_Type == RIPEMD_256)
	{
		Temp = H2; H2 = H_2; H_2 = Temp;
	}

	/* j = 32 to 47 */
	/* 32 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 33 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 34 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 35 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 36 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 37 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 38 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 39 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 40 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 41 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 42 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 43 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 44 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 45 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,13,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 46 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 7,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 47 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	if(ucSignature_Type == RIPEMD_256)
	{
		Temp = H3; H3 = H_3; H_3 = Temp;
	}
	
	/* j = 48 to 63 */
	/* 48 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 49 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 50 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 51 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,11,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 52 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 53 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 54 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 55 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 56 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 57 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,14,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 58 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 59 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 9,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 60 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 61 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 6,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 62 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 5,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,15,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	/* 63 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,12,_32BIT);
	H1 = H4; H4 = H3; H3 = H2; H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 8,_32BIT);
	H_1 = H_4; H_4 = H_3; H_3 = H_2; H_2 = Temp;

	if(ucSignature_Type == RIPEMD_256)
	{
		Temp = H4; H4 = H_4; H_4 = Temp;
	}

	if(ucSignature_Type == RIPEMD_128)
	{
		Temp = Hash.ulValues[1] + H3 + H_4;
		Hash.ulValues[1] = Hash.ulValues[2] + H4 + H_1;
		Hash.ulValues[2] = Hash.ulValues[3] + H1 + H_2;
		Hash.ulValues[3] = Hash.ulValues[0] + H2 + H_3;
		Hash.ulValues[0] = Temp;
	}
	else
	{
		Hash.ulValues[0] += H1;
		Hash.ulValues[1] += H2;
		Hash.ulValues[2] += H3;
		Hash.ulValues[3] += H4;
		Hash.ulValues[4] += H_1;
		Hash.ulValues[5] += H_2;
		Hash.ulValues[6] += H_3;
		Hash.ulValues[7] += H_4;
	}
}

/*******************************************************************/
/*  Name of function : RIPEMD_160_320_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in RIPEMD-160 AND RIPEMD-320 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::RIPEMD_160_320_Transform(VOID)
{
	register ULONG H1,H2,H3,H4,H5, H_1,H_2,H_3,H_4,H_5;
	register ULONG Temp;

	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];
	H5 = Hash.ulValues[4];

	if(ucSignature_Type == RIPEMD_160)
	{
		H_1 = H1;
		H_2 = H2;
		H_3 = H3;
		H_4 = H4;
		H_5 = H5;
	}
	else
	{
		H_1 = Hash.ulValues[5];
		H_2 = Hash.ulValues[6];
		H_3 = Hash.ulValues[7];
		H_4 = Hash.ulValues[8];
		H_5 = Hash.ulValues[9];
	}

	/* j = 0 to 15 */
	/* 00 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 01 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 02 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 03 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 04 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 05 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 06 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 07 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 08 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 09 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 10 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 11 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 12 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 13 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 14 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 15 */
	Temp  = H1 + RIPEMD_xxx_1(H2,H3,H4); // + 0x00000000
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_5(H_2,H_3,H_4) + 0x50A28BE6;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	if(ucSignature_Type == RIPEMD_320)
	{
		Temp = H2; H2 = H_2; H_2 = Temp;
	}

	/* j = 16 to 32 */
	/* 16 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 17 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 18 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 19 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 20 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 21 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 22 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 23 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 24 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 25 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 26 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 27 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 28 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 29 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 30 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 31 */
	Temp  = H1 + RIPEMD_xxx_2(H2,H3,H4) + 0x5A827999;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_4(H_2,H_3,H_4) + 0x5C4DD124;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	if(ucSignature_Type == RIPEMD_320)
	{
		Temp = H4; H4 = H_4; H_4 = Temp;
	}

	/* j = 32 to 47 */
	/* 32 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 33 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 34 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 35 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 36 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 37 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 38 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 39 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 40 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 41 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 42 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 43 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 44 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 45 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 46 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 7,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 47 */
	Temp  = H1 + RIPEMD_xxx_3(H2,H3,H4) + 0x6ED9EBA1;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_3(H_2,H_3,H_4) + 0x6D703EF3;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	if(ucSignature_Type == RIPEMD_320)
	{
		Temp = H1; H1 = H_1; H_1 = Temp;
	}
	
	/* j = 48 to 63 */
	/* 48 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 49 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 50 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 51 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 52 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 53 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 54 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 55 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 56 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 57 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 58 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 59 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 60 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 61 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 62 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 63 */
	Temp  = H1 + RIPEMD_xxx_4(H2,H3,H4) + 0x8F1BBCDC;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_2(H_2,H_3,H_4) + 0x7A6D76E9;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	if(ucSignature_Type == RIPEMD_320)
	{
		Temp = H3; H3 = H_3; H_3 = Temp;
	}

	/* j = 64 to 79 */
	/* 64 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 65 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 66 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 67 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 4];
	Temp  = Rotate_Left(Temp, 9,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 68 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 69 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[12];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 5];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 70 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 71 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[10];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 7];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 72 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 73 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 1];
	Temp  = Rotate_Left(Temp,12,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 2];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 74 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 75 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 8];
	Temp  = Rotate_Left(Temp,14,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[14];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 76 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 0];
	Temp  = Rotate_Left(Temp,15,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 77 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[ 6];
	Temp  = Rotate_Left(Temp, 8,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 3];
	Temp  = Rotate_Left(Temp,13,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 78 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[15];
	Temp  = Rotate_Left(Temp, 5,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2;
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[ 9];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	/* 79 */
	Temp  = H1 + RIPEMD_xxx_5(H2,H3,H4) + 0xA953FD4E;
	Temp += Message.Block.ulValues[13];
	Temp  = Rotate_Left(Temp, 6,_32BIT) + H5;
	H1 = H5; H5 = H4; H4 = Rotate_Left(H3,10,_32BIT); H3 = H2; 
	H2 = Temp;

	Temp  = H_1 + RIPEMD_xxx_1(H_2,H_3,H_4); // + 0x00000000
	Temp += Message.Block.ulValues[11];
	Temp  = Rotate_Left(Temp,11,_32BIT) + H_5;
	H_1 = H_5; H_5 = H_4; H_4 = Rotate_Left(H_3,10,_32BIT); H_3 = H_2;
	H_2 = Temp;

	if(ucSignature_Type == RIPEMD_320)
	{
		Temp = H5; H5 = H_5; H_5 = Temp;
	}

	if(ucSignature_Type == RIPEMD_160)
	{
		Temp = Hash.ulValues[1] + H3 + H_4;
		Hash.ulValues[1] = Hash.ulValues[2] + H4 + H_5;
		Hash.ulValues[2] = Hash.ulValues[3] + H5 + H_1;
		Hash.ulValues[3] = Hash.ulValues[4] + H1 + H_2;
		Hash.ulValues[4] = Hash.ulValues[0] + H2 + H_3;
		Hash.ulValues[0] = Temp;
	}
	else
	{
		Hash.ulValues[0] += H1;
		Hash.ulValues[1] += H2;
		Hash.ulValues[2] += H3;
		Hash.ulValues[3] += H4;
		Hash.ulValues[4] += H5;
		Hash.ulValues[5] += H_1;
		Hash.ulValues[6] += H_2;
		Hash.ulValues[7] += H_3;
		Hash.ulValues[8] += H_4;
		Hash.ulValues[9] += H_5;

	}
}
#endif
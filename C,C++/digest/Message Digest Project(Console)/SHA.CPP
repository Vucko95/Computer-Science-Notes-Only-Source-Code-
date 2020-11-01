#ifndef _SHA_CPP_
#define _SHA_CPP_
/*******************************************************************/
/*  Name of function : SHA1_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in SHA1 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::SHA1_Transform(VOID)
{
	register ULONG H1,H2,H3,H4,H5;
	register ULONG Temp;
	UCHAR Loop, Idx;

	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];
	H5 = Hash.ulValues[4];

/*	for(Loop = 0; Loop < 16; Loop++)
	{
		Idx = Message.Block.ucValues[Loop * 4];
		Message.Block.ucValues[Loop * 4] = \
				Message.Block.ucValues[Loop * 4 + 3];
		Message.Block.ucValues[Loop * 4 + 3] = Idx;

		Idx = Message.Block.ucValues[Loop * 4 + 1];
		Message.Block.ucValues[Loop * 4 + 1] = \
				Message.Block.ucValues[Loop * 4 + 2];
		Message.Block.ucValues[Loop * 4 + 2] = Idx;
	}*/
	for(Loop = 0; Loop < 16; Message.Block.ulValues[Loop++] = \
							Endian_Conversion(Message.Block.ulValues[Loop]));

 	for(Loop = 0; Loop <= 79; Loop++)
	{
		Idx = Loop & 0xF;
		if(Loop > 15)
		{
			Temp  = Message.Block.ulValues[(Idx+13) & 0xF];
			Temp ^= Message.Block.ulValues[(Idx+ 8) & 0xF];
			Temp ^= Message.Block.ulValues[(Idx+ 2) & 0xF];
			Temp ^= Message.Block.ulValues[Idx];

			Message.Block.ulValues[Idx] = Rotate_Left(Temp,1,_32BIT);
		}
		
		Temp = Rotate_Left(H1,5,_32BIT) + H5;
		
		switch (Loop/20)
		{
			case 0:
			{
				Temp += SHA_1_1(H2,H3,H4) + 0x5A827999;
				break;
			}

			case 1:
			{
				Temp += SHA_1_2(H2,H3,H4) + 0x6ED9EBA1;
				break;
			}
				
			case 2:
			{
				Temp += SHA_1_3(H2,H3,H4) + 0x8F1BBCDC;
				break;
			}

			case 3:
			{
				Temp += SHA_1_4(H2,H3,H4) + 0xCA62C1D6;
				break;
			}
		}

		Temp += Message.Block.ulValues[Idx];
		H5 = H4; H4 = H3;
		H3 = Rotate_Left(H2,30,_32BIT);
		H2 = H1; H1 = Temp;
	}
	
	Hash.ulValues[0] += H1;
	Hash.ulValues[1] += H2;
	Hash.ulValues[2] += H3;
	Hash.ulValues[3] += H4;
	Hash.ulValues[4] += H5;
}

/*******************************************************************/
/*  Name of function : SHA256_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in SHA256 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::SHA256_Transform(VOID)
{
	register ULONG H1,H2,H3,H4,H5,H6,H7,H8;
	register ULONG Temp,Temp1,Temp2;
	UCHAR Loop;

	/* Copying the previous Hash Values */
	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];
	H5 = Hash.ulValues[4];
	H6 = Hash.ulValues[5];
	H7 = Hash.ulValues[6];
	H8 = Hash.ulValues[7];

	/* Inverting the Message block */
/*	for(Loop = 0; Loop < 16; Loop++)
	{
		Idx = Message.Block.ucValues[Loop * 4];
		Message.Block.ucValues[Loop * 4] = \
				Message.Block.ucValues[Loop * 4 + 3];
		Message.Block.ucValues[Loop * 4 + 3] = Idx;

		Idx = Message.Block.ucValues[Loop * 4 + 1];
		Message.Block.ucValues[Loop * 4 + 1] = \
				Message.Block.ucValues[Loop * 4 + 2];
		Message.Block.ucValues[Loop * 4 + 2] = Idx;
	}*/

	for(Loop = 0; Loop < 16; Message.Block.ulValues[Loop++] = \
					Endian_Conversion(Message.Block.ulValues[Loop]));

	/* 01 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[0]
								  + 0x428a2f98;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 02 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[1]
								  + 0x71374491;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 03 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[2]
								  + 0xb5c0fbcf;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 04 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[3]
								  + 0xe9b5dba5;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 05 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[4]
								  + 0x3956c25b;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 06 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[5]
								  + 0x59f111f1;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 07 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[6]
								  + 0x923f82a4;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 08 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[7]
								  + 0xab1c5ed5;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 09 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[8]
								  + 0xd807aa98;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 10 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[9]
								  + 0x12835b01;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 11 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[10]
								  + 0x243185be;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 12 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[11]
								  + 0x550c7dc3;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 13 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[12]
								  + 0x72be5d74;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 14 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[13]
								  + 0x80deb1fe;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 15 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[14]
								  + 0x9bdc06a7;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 16 */
	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[15]
								  + 0xc19bf174;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 17 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[9];
	Temp += Sig_256_SR_0(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[0];

	Message.Block.ulValues[0] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[0]
								  + 0xe49b69c1;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 18 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[10];
	Temp += Sig_256_SR_0(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[1];

	Message.Block.ulValues[1] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[1]
								  + 0xefbe4786;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 19 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[11];
	Temp += Sig_256_SR_0(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[2];

	Message.Block.ulValues[2] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[2]
								  + 0x0fc19dc6;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 20 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[12];
	Temp += Sig_256_SR_0(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[3];

	Message.Block.ulValues[3] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[3]
								  + 0x240ca1cc;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 21 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[13];
	Temp += Sig_256_SR_0(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[4];

	Message.Block.ulValues[4] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[4]
								  + 0x2de92c6f;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 22 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[14];
	Temp += Sig_256_SR_0(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[5];

	Message.Block.ulValues[5] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[5]
								  + 0x4a7484aa;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 23 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[15];
	Temp += Sig_256_SR_0(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[6];

	Message.Block.ulValues[6] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[6]
								  + 0x5cb0a9dc;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 24 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[0];
	Temp += Sig_256_SR_0(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[7];

	Message.Block.ulValues[7] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[7]
								  + 0x76f988da;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 25 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[1];
	Temp += Sig_256_SR_0(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[8];

	Message.Block.ulValues[8] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[8]
								  + 0x983e5152;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 26 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[2];
	Temp += Sig_256_SR_0(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[9];

	Message.Block.ulValues[9] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[9]
								  + 0xa831c66d;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 27 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[3];
	Temp += Sig_256_SR_0(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[10];

	Message.Block.ulValues[10] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[10]
								  + 0xb00327c8;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 28 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[4];
	Temp += Sig_256_SR_0(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[11];

	Message.Block.ulValues[11] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[11]
								  + 0xbf597fc7;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 29 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[5];
	Temp += Sig_256_SR_0(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[12];

	Message.Block.ulValues[12] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[12]
								  + 0xc6e00bf3;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 30 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[6];
	Temp += Sig_256_SR_0(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[13];

	Message.Block.ulValues[13] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[13]
								  + 0xd5a79147;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 31 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[7];
	Temp += Sig_256_SR_0(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[14];

	Message.Block.ulValues[14] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[14]
								  + 0x06ca6351;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 32 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[8];
	Temp += Sig_256_SR_0(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[15];

	Message.Block.ulValues[15] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[15]
								  + 0x14292967;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 33 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[9];
	Temp += Sig_256_SR_0(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[0];

	Message.Block.ulValues[0] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[0]
								  + 0x27b70a85;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 34 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[10];
	Temp += Sig_256_SR_0(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[1];

	Message.Block.ulValues[1] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[1]
								  + 0x2e1b2138;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 35 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[11];
	Temp += Sig_256_SR_0(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[2];

	Message.Block.ulValues[2] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[2]
								  + 0x4d2c6dfc;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 36 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[12];
	Temp += Sig_256_SR_0(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[3];

	Message.Block.ulValues[3] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[3]
								  + 0x53380d13;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 37 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[13];
	Temp += Sig_256_SR_0(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[4];

	Message.Block.ulValues[4] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[4]
								  + 0x650a7354;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 38 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[14];
	Temp += Sig_256_SR_0(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[5];

	Message.Block.ulValues[5] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[5]
								  + 0x766a0abb;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 40 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[15];
	Temp += Sig_256_SR_0(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[6];

	Message.Block.ulValues[6] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[6]
								  + 0x81c2c92e;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 41 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[0];
	Temp += Sig_256_SR_0(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[7];

	Message.Block.ulValues[7] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[7]
								  + 0x92722c85;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 42 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[1];
	Temp += Sig_256_SR_0(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[8];

	Message.Block.ulValues[8] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[8]
								  + 0xa2bfe8a1;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 43 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[2];
	Temp += Sig_256_SR_0(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[9];

	Message.Block.ulValues[9] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[9]
								  + 0xa81a664b;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 44 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[3];
	Temp += Sig_256_SR_0(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[10];

	Message.Block.ulValues[10] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[10]
								  + 0xc24b8b70;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 45 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[4];
	Temp += Sig_256_SR_0(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[11];

	Message.Block.ulValues[11] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[11]
								  + 0xc76c51a3;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 46 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[5];
	Temp += Sig_256_SR_0(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[12];

	Message.Block.ulValues[12] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[12]
								  + 0xd192e819;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 47 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[6];
	Temp += Sig_256_SR_0(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[13];

	Message.Block.ulValues[13] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[13]
								  + 0xd6990624;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 48 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[7];
	Temp += Sig_256_SR_0(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[14];

	Message.Block.ulValues[14] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[14]
								  + 0xf40e3585;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 49 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[8];
	Temp += Sig_256_SR_0(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[15];

	Message.Block.ulValues[15] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[15]
								  + 0x106aa070;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 50 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[9];
	Temp += Sig_256_SR_0(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[0];

	Message.Block.ulValues[0] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[0]
								  + 0x19a4c116;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 51 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[10];
	Temp += Sig_256_SR_0(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[1];

	Message.Block.ulValues[1] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[1]
								  + 0x1e376c08;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 52 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[11];
	Temp += Sig_256_SR_0(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[2];

	Message.Block.ulValues[2] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[2]
								  + 0x2748774c;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 53 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[1]);
	Temp += Message.Block.ulValues[12];
	Temp += Sig_256_SR_0(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[3];

	Message.Block.ulValues[3] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[3]
								  + 0x34b0bcb5;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 54 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[2]);
	Temp += Message.Block.ulValues[13];
	Temp += Sig_256_SR_0(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[4];

	Message.Block.ulValues[4] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[4]
								  + 0x391c0cb3;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 55 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[3]);
	Temp += Message.Block.ulValues[14];
	Temp += Sig_256_SR_0(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[5];

	Message.Block.ulValues[5] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[5]
								  + 0x4ed8aa4a;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 56 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[4]);
	Temp += Message.Block.ulValues[15];
	Temp += Sig_256_SR_0(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[6];

	Message.Block.ulValues[6] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[6]
								  + 0x5b9cca4f;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 57 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[5]);
	Temp += Message.Block.ulValues[0];
	Temp += Sig_256_SR_0(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[7];

	Message.Block.ulValues[7] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[7]
								  + 0x682e6ff3;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 58 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[6]);
	Temp += Message.Block.ulValues[1];
	Temp += Sig_256_SR_0(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[8];

	Message.Block.ulValues[8] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[8]
								  + 0x748f82ee;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 59 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[7]);
	Temp += Message.Block.ulValues[2];
	Temp += Sig_256_SR_0(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[9];

	Message.Block.ulValues[9] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[9]
								  + 0x78a5636f;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 60 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[8]);
	Temp += Message.Block.ulValues[3];
	Temp += Sig_256_SR_0(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[10];

	Message.Block.ulValues[10] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[10]
								  + 0x84c87814;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 61 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[9]);
	Temp += Message.Block.ulValues[4];
	Temp += Sig_256_SR_0(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[11];

	Message.Block.ulValues[11] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[11]
								  + 0x8cc70208;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 62 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[10]);
	Temp += Message.Block.ulValues[5];
	Temp += Sig_256_SR_0(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[12];

	Message.Block.ulValues[12] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[12]
								  + 0x90befffa;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 63 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[11]);
	Temp += Message.Block.ulValues[6];
	Temp += Sig_256_SR_0(Message.Block.ulValues[14]);
	Temp += Message.Block.ulValues[13];

	Message.Block.ulValues[13] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[13]
								  + 0xa4506ceb;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 64 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[12]);
	Temp += Message.Block.ulValues[7];
	Temp += Sig_256_SR_0(Message.Block.ulValues[15]);
	Temp += Message.Block.ulValues[14];

	Message.Block.ulValues[14] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[14]
								  + 0xbef9a3f7;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 65 */
	Temp  = Sig_256_SR_1(Message.Block.ulValues[13]);
	Temp += Message.Block.ulValues[8];
	Temp += Sig_256_SR_0(Message.Block.ulValues[0]);
	Temp += Message.Block.ulValues[15];

	Message.Block.ulValues[15] = Temp;

	Temp1 = H8 + Sig_256_RR_1(H5) + SHA_256_CH(H5,H6,H7)\
								  + Message.Block.ulValues[15]
								  + 0xc67178f2;
	Temp2 = Sig_256_RR_0(H1) + SHA_256_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* storing the changed Hash Values */
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
/*  Name of function : SHA_384_512_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function do the Transformation of the 
			  Message Block in SHA-384 SHA-512 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::SHA_384_512_Transform(VOID)
{
	register ULONGLONG H1,H2,H3,H4,H5,H6,H7,H8;
	register ULONGLONG Temp,Temp1,Temp2;
	UCHAR Loop;

	/* Copying the previous Hash Values */
	H1 = Hash.ullValues[0];
	H2 = Hash.ullValues[1];
	H3 = Hash.ullValues[2];
	H4 = Hash.ullValues[3];
	H5 = Hash.ullValues[4];
	H6 = Hash.ullValues[5];
	H7 = Hash.ullValues[6];
	H8 = Hash.ullValues[7];

	/* Inverting the Message block */
/*	for(Loop = 0; Loop < 16; Loop++)
	{
		Idx = Message.Block.ucValues[Loop * 8];
		Message.Block.ucValues[Loop * 8] = \
				Message.Block.ucValues[Loop * 8 + 7];
		Message.Block.ucValues[Loop * 8 + 7] = Idx;

		Idx = Message.Block.ucValues[Loop * 8 + 1];
		Message.Block.ucValues[Loop * 8 + 1] = \
				Message.Block.ucValues[Loop * 8 + 6];
		Message.Block.ucValues[Loop * 8 + 6] = Idx;

		Idx = Message.Block.ucValues[Loop * 8 + 2];
		Message.Block.ucValues[Loop * 8 + 2] = \
				Message.Block.ucValues[Loop * 8 + 5];
		Message.Block.ucValues[Loop * 8 + 5] = Idx;

		Idx = Message.Block.ucValues[Loop * 8 + 3];
		Message.Block.ucValues[Loop * 8 + 3] = \
				Message.Block.ucValues[Loop * 8 + 4];
		Message.Block.ucValues[Loop * 8 + 4] = Idx;
	}*/
	for(Loop = 0; Loop < 16; Message.Block.ullValues[Loop++] = \
							 Endian_Conversion(Message.Block.ullValues[Loop]));


	/* 01 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[0]
								  + 0x428a2f98d728ae22;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 02 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[1]
								  + 0x7137449123ef65cd;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 03 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[2]
								  + 0xb5c0fbcfec4d3b2f;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 04 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[3]
								  + 0xe9b5dba58189dbbc;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 05 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[4]
								  + 0x3956c25bf348b538;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 06 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[5]
								  + 0x59f111f1b605d019;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 07 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[6]
								  + 0x923f82a4af194f9b;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 08 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[7]
								  + 0xab1c5ed5da6d8118;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 09 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[8]
								  + 0xd807aa98a3030242;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 10 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[9]
								  + 0x12835b0145706fbe;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 11 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[10]
								  + 0x243185be4ee4b28c;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 12 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[11]
								  + 0x550c7dc3d5ffb4e2;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 13 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[12]
								  + 0x72be5d74f27b896f;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 14 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[13]
								  + 0x80deb1fe3b1696b1;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 15 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[14]
								  + 0x9bdc06a725c71235;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 16 */
	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[15]
								  + 0xc19bf174cf692694;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 17 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[9];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[0];

	Message.Block.ullValues[0] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[0]
								  + 0xe49b69c19ef14ad2;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 18 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[10];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[1];

	Message.Block.ullValues[1] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[1]
								  + 0xefbe4786384f25e3;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 19 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[11];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[2];

	Message.Block.ullValues[2] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[2]
								  + 0x0fc19dc68b8cd5b5;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 20 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[12];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[3];

	Message.Block.ullValues[3] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[3]
								  + 0x240ca1cc77ac9c65;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 21 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[13];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[4];

	Message.Block.ullValues[4] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[4]
								  + 0x2de92c6f592b0275;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 22 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[14];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[5];

	Message.Block.ullValues[5] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[5]
								  + 0x4a7484aa6ea6e483;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 23 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[15];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[6];

	Message.Block.ullValues[6] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[6]
								  + 0x5cb0a9dcbd41fbd4;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 24 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[0];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[7];

	Message.Block.ullValues[7] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[7]
								  + 0x76f988da831153b5;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 25 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[1];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[8];

	Message.Block.ullValues[8] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[8]
								  + 0x983e5152ee66dfab;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 26 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[2];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[9];

	Message.Block.ullValues[9] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[9]
								  + 0xa831c66d2db43210;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 27 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[3];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[10];

	Message.Block.ullValues[10] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[10]
								  + 0xb00327c898fb213f;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 28 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[4];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[11];

	Message.Block.ullValues[11] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[11]
								  + 0xbf597fc7beef0ee4;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 29 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[5];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[12];

	Message.Block.ullValues[12] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[12]
								  + 0xc6e00bf33da88fc2;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 30 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[6];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[13];

	Message.Block.ullValues[13] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[13]
								  + 0xd5a79147930aa725;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 31 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[7];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[14];

	Message.Block.ullValues[14] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[14]
								  + 0x06ca6351e003826f;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 32 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[8];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[15];

	Message.Block.ullValues[15] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[15]
								  + 0x142929670a0e6e70;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 33 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[9];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[0];

	Message.Block.ullValues[0] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[0]
								  + 0x27b70a8546d22ffc;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 34 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[10];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[1];

	Message.Block.ullValues[1] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[1]
								  + 0x2e1b21385c26c926;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 35 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[11];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[2];

	Message.Block.ullValues[2] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[2]
								  + 0x4d2c6dfc5ac42aed;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 36 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[12];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[3];

	Message.Block.ullValues[3] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[3]
								  + 0x53380d139d95b3df;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 37 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[13];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[4];

	Message.Block.ullValues[4] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[4]
								  + 0x650a73548baf63de;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 38 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[14];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[5];

	Message.Block.ullValues[5] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[5]
								  + 0x766a0abb3c77b2a8;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 39 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[15];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[6];

	Message.Block.ullValues[6] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[6]
								  + 0x81c2c92e47edaee6;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 40 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[0];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[7];

	Message.Block.ullValues[7] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[7]
								  + 0x92722c851482353b;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 41 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[1];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[8];

	Message.Block.ullValues[8] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[8]
								  + 0xa2bfe8a14cf10364;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 42 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[2];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[9];

	Message.Block.ullValues[9] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[9]
								  + 0xa81a664bbc423001;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 43 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[3];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[10];

	Message.Block.ullValues[10] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[10]
								  + 0xc24b8b70d0f89791;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 44 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[4];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[11];

	Message.Block.ullValues[11] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[11]
								  + 0xc76c51a30654be30;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 45 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[5];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[12];

	Message.Block.ullValues[12] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[12]
								  + 0xd192e819d6ef5218;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 46 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[6];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[13];

	Message.Block.ullValues[13] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[13]
								  + 0xd69906245565a910;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 47 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[7];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[14];

	Message.Block.ullValues[14] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[14]
								  + 0xf40e35855771202a;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 48 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[8];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[15];

	Message.Block.ullValues[15] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[15]
								  + 0x106aa07032bbd1b8;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 49 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[9];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[0];

	Message.Block.ullValues[0] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[0]
								  + 0x19a4c116b8d2d0c8;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 50 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[10];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[1];

	Message.Block.ullValues[1] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[1]
								  + 0x1e376c085141ab53;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 51 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[11];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[2];

	Message.Block.ullValues[2] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[2]
								  + 0x2748774cdf8eeb99;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 52 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[12];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[3];

	Message.Block.ullValues[3] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[3]
								  + 0x34b0bcb5e19b48a8;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 53 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[13];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[4];

	Message.Block.ullValues[4] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[4]
								  + 0x391c0cb3c5c95a63;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 54 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[14];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[5];

	Message.Block.ullValues[5] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[5]
								  + 0x4ed8aa4ae3418acb;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 55 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[15];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[6];

	Message.Block.ullValues[6] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[6]
								  + 0x5b9cca4f7763e373;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 56 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[0];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[7];

	Message.Block.ullValues[7] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[7]
								  + 0x682e6ff3d6b2b8a3;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 57 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[1];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[8];

	Message.Block.ullValues[8] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[8]
								  + 0x748f82ee5defb2fc;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 58 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[2];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[9];

	Message.Block.ullValues[9] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[9]
								  + 0x78a5636f43172f60;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 59 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[3];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[10];

	Message.Block.ullValues[10] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[10]
								  + 0x84c87814a1f0ab72;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 60 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[4];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[11];

	Message.Block.ullValues[11] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[11]
								  + 0x8cc702081a6439ec;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 61 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[5];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[12];

	Message.Block.ullValues[12] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[12]
								  + 0x90befffa23631e28;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 62 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[6];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[13];

	Message.Block.ullValues[13] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[13]
								  + 0xa4506cebde82bde9;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 63 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[7];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[14];

	Message.Block.ullValues[14] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[14]
								  + 0xbef9a3f7b2c67915;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4 + Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 64 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[8];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[15];

	Message.Block.ullValues[15] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[15]
								  + 0xc67178f2e372532b;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 65 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[9];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[0];

	Message.Block.ullValues[0] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[0]
								  + 0xca273eceea26619c;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 66 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[10];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[1];

	Message.Block.ullValues[1] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[1]
								  + 0xd186b8c721c0c207;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 67 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[11];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[2];

	Message.Block.ullValues[2] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[2]
								  + 0xeada7dd6cde0eb1e;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 68*/
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[1]);
	Temp += Message.Block.ullValues[12];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[3];

	Message.Block.ullValues[3] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[3]
								  + 0xf57d4f7fee6ed178;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 69*/
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[2]);
	Temp += Message.Block.ullValues[13];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[4];

	Message.Block.ullValues[4] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[4]
								  + 0x06f067aa72176fba;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 70 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[3]);
	Temp += Message.Block.ullValues[14];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[5];

	Message.Block.ullValues[5] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[5]
								  + 0x0a637dc5a2c898a6;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 71 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[4]);
	Temp += Message.Block.ullValues[15];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[6];

	Message.Block.ullValues[6] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[6]
								  + 0x113f9804bef90dae;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 72 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[5]);
	Temp += Message.Block.ullValues[0];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[7];

	Message.Block.ullValues[7] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[7]
								  + 0x1b710b35131c471b;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 73 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[6]);
	Temp += Message.Block.ullValues[1];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[8];

	Message.Block.ullValues[8] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[8]
								  + 0x28db77f523047d84;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 74 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[7]);
	Temp += Message.Block.ullValues[2];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[9];

	Message.Block.ullValues[9] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[9]
								  + 0x32caab7b40c72493;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 75 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[8]);
	Temp += Message.Block.ullValues[3];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[10];

	Message.Block.ullValues[10] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[10]
								  + 0x3c9ebe0a15c9bebc;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 76 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[9]);
	Temp += Message.Block.ullValues[4];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[11];

	Message.Block.ullValues[11] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[11]
								  + 0x431d67c49c100d4c;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 77 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[10]);
	Temp += Message.Block.ullValues[5];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[12];

	Message.Block.ullValues[12] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[12]
								  + 0x4cc5d4becb3e42b6;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 78 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[11]);
	Temp += Message.Block.ullValues[6];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[14]);
	Temp += Message.Block.ullValues[13];

	Message.Block.ullValues[13] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[13]
								  + 0x597f299cfc657e2a;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 79 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[12]);
	Temp += Message.Block.ullValues[7];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[15]);
	Temp += Message.Block.ullValues[14];

	Message.Block.ullValues[14] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[14]
								  + 0x5fcb6fab3ad6faec;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* 80 */
	Temp  = Sig_384_512_SR_1(Message.Block.ullValues[13]);
	Temp += Message.Block.ullValues[8];
	Temp += Sig_384_512_SR_0(Message.Block.ullValues[0]);
	Temp += Message.Block.ullValues[15];

	Message.Block.ullValues[15] = Temp;

	Temp1 = H8 + Sig_384_512_RR_1(H5) + SHA_384_512_CH(H5,H6,H7)\
								  + Message.Block.ullValues[15]
								  + 0x6c44198c4a475817;
	Temp2 = Sig_384_512_RR_0(H1) + SHA_384_512_MAJ(H1,H2,H3);
	
	H8 = H7; H7 = H6; H6 = H5; H5 = H4+ Temp1;
	H4 = H3; H3 = H2; H2 = H1; H1 = Temp1 + Temp2;

	/* storing the changed Hash Values */
	Hash.ullValues[0] += H1;
	Hash.ullValues[1] += H2;
	Hash.ullValues[2] += H3;
	Hash.ullValues[3] += H4;
	Hash.ullValues[4] += H5;
	Hash.ullValues[5] += H6;
	Hash.ullValues[6] += H7;
	Hash.ullValues[7] += H8;
}
#endif
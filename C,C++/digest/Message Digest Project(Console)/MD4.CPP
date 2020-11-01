#ifndef _MD4_CPP_
#define _MD4_CPP_
/*******************************************************************/
/*  Name of function : MD4_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function to do the Transformation of the 
			  Message Block in MD4 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context :: MD4_Transform(VOID)
{
	register ULONG H1,H2,H3,H4,Constant;
	UCHAR i,j,Condition = ucDigest_Length >> 4 ;

	/* Round - 1 */
	for(i = j = 0; i < Condition; i++, j = i << 2)
	{
		H1 = Hash.ulValues[j];
		H2 = Hash.ulValues[j + 1];
		H3 = Hash.ulValues[j + 2];
		H4 = Hash.ulValues[j + 3];

		H1 += MD_4_1(H2,H3,H4) + Message.Block.ulValues[0];
		H1 = Rotate_Left(H1,3, _32BIT);

		H4 += MD_4_1(H1,H2,H3) + Message.Block.ulValues[1];
		H4 = Rotate_Left(H4,7, _32BIT);

		H3 += MD_4_1(H4,H1,H2) + Message.Block.ulValues[2];
		H3 = Rotate_Left(H3, 11, _32BIT);

		H2 += MD_4_1(H3,H4,H1) + Message.Block.ulValues[3];
		H2 = Rotate_Left(H2, 19, _32BIT);

		H1 += MD_4_1(H2,H3,H4) + Message.Block.ulValues[4];
		H1 = Rotate_Left(H1,3, _32BIT);

		H4 += MD_4_1(H1,H2,H3) + Message.Block.ulValues[ 5];
		H4 = Rotate_Left(H4,7, _32BIT);

		H3 += MD_4_1(H4,H1,H2) + Message.Block.ulValues[ 6];
		H3 = Rotate_Left(H3, 11, _32BIT);

		H2 += MD_4_1(H3,H4,H1) + Message.Block.ulValues[ 7];
		H2 = Rotate_Left(H2, 19, _32BIT);

		H1 += MD_4_1(H2,H3,H4) + Message.Block.ulValues[ 8];
		H1 = Rotate_Left(H1,3, _32BIT);

		H4 += MD_4_1(H1,H2,H3) + Message.Block.ulValues[ 9];
		H4 = Rotate_Left(H4,7, _32BIT);

		H3 += MD_4_1(H4,H1,H2) + Message.Block.ulValues[10];
		H3 = Rotate_Left(H3, 11, _32BIT);

		H2 += MD_4_1(H3,H4,H1) + Message.Block.ulValues[11];
		H2 = Rotate_Left(H2, 19, _32BIT);

		H1 += MD_4_1(H2,H3,H4) + Message.Block.ulValues[12];
		H1 = Rotate_Left(H1,3, _32BIT);

		H4 += MD_4_1(H1,H2,H3) + Message.Block.ulValues[13];
		H4 = Rotate_Left(H4,7, _32BIT);

		H3 += MD_4_1(H4,H1,H2) + Message.Block.ulValues[14];
		H3 = Rotate_Left(H3, 11, _32BIT);

		H2 += MD_4_1(H3,H4,H1) + Message.Block.ulValues[15];
		H2 = Rotate_Left(H2, 19, _32BIT);

		Hash.ulValues[j +  8] = H1;
		Hash.ulValues[j +  9] = H2;
		Hash.ulValues[j + 10] = H3;
		Hash.ulValues[j + 11] = H4;
	}
	
	if(ucSignature_Type == MD_4_256)
	{
		// Swap the First Hash Values
		H1 = Hash.ulValues[8];
		Hash.ulValues[8] = Hash.ulValues[12];
		Hash.ulValues[12] = H1;
	}

	
	/* Round - 2 */
	// Initialize the Constant 
	Constant = 0x5A827999L;
	for(i = j = 0; i < Condition; i++, j = i << 2)
	{
		
		H1 = Hash.ulValues[j +  8];
		H2 = Hash.ulValues[j +  9];
		H3 = Hash.ulValues[j + 10];
		H4 = Hash.ulValues[j + 11];

		H1 += MD_4_2(H2,H3,H4) + Message.Block.ulValues[ 0] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_2(H1,H2,H3) + Message.Block.ulValues[ 4] + Constant;
		H4 = Rotate_Left(H4, 5, _32BIT);

		H3 += MD_4_2(H4,H1,H2) + Message.Block.ulValues[ 8] + Constant;
		H3 = Rotate_Left(H3, 9, _32BIT);

		H2 += MD_4_2(H3,H4,H1) + Message.Block.ulValues[12] + Constant;
		H2 = Rotate_Left(H2,13, _32BIT);

		H1 += MD_4_2(H2,H3,H4) + Message.Block.ulValues[ 1] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_2(H1,H2,H3) + Message.Block.ulValues[ 5] + Constant;
		H4 = Rotate_Left(H4, 5, _32BIT);

		H3 += MD_4_2(H4,H1,H2) + Message.Block.ulValues[ 9] + Constant;
		H3 = Rotate_Left(H3, 9, _32BIT);

		H2 += MD_4_2(H3,H4,H1) + Message.Block.ulValues[13] + Constant;
		H2 = Rotate_Left(H2, 13, _32BIT);

		H1 += MD_4_2(H2,H3,H4) + Message.Block.ulValues[ 2] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_2(H1,H2,H3) + Message.Block.ulValues[ 6] + Constant;
		H4 = Rotate_Left(H4, 5, _32BIT);

		H3 += MD_4_2(H4,H1,H2) + Message.Block.ulValues[10] + Constant;
		H3 = Rotate_Left(H3, 9, _32BIT);

		H2 += MD_4_2(H3,H4,H1) + Message.Block.ulValues[14] + Constant;
		H2 = Rotate_Left(H2,13, _32BIT);

		H1 += MD_4_2(H2,H3,H4) + Message.Block.ulValues[ 3] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_2(H1,H2,H3) + Message.Block.ulValues[ 7] + Constant;
		H4 = Rotate_Left(H4, 5, _32BIT);

		H3 += MD_4_2(H4,H1,H2) + Message.Block.ulValues[11] + Constant;
		H3 = Rotate_Left(H3, 9, _32BIT);

		H2 += MD_4_2(H3,H4,H1) + Message.Block.ulValues[15] + Constant;
		H2 = Rotate_Left(H2,13, _32BIT);

		Hash.ulValues[j +  8] = H1;
		Hash.ulValues[j +  9] = H2;
		Hash.ulValues[j + 10] = H3;
		Hash.ulValues[j + 11] = H4;

		Constant = 0x50A8B6L;
	}

	if(ucSignature_Type == MD_4_256)
	{
		// Swap the First Hash Values
		H1 = Hash.ulValues[4];
		Hash.ulValues[4] = Hash.ulValues[12];
		Hash.ulValues[12] = H1;
	}

	/* Round - 3 */
	// Initialize the Constant 
	Constant = 0x6ED9EBA1;
	for(i = j = 0; i < Condition; i++, j = i << 2)
	{
		
		H1 = Hash.ulValues[j +  8];
		H2 = Hash.ulValues[j +  9];
		H3 = Hash.ulValues[j + 10];
		H4 = Hash.ulValues[j + 11];

		H1 += MD_4_3(H2,H3,H4) + Message.Block.ulValues[ 0] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_3(H1,H2,H3) + Message.Block.ulValues[ 8] + Constant;
		H4 = Rotate_Left(H4, 9, _32BIT);

		H3 += MD_4_3(H4,H1,H2) + Message.Block.ulValues[ 4] + Constant;
		H3 = Rotate_Left(H3,11, _32BIT);

		H2 += MD_4_3(H3,H4,H1) + Message.Block.ulValues[12] + Constant;
		H2 = Rotate_Left(H2,15, _32BIT);

		H1 += MD_4_3(H2,H3,H4) + Message.Block.ulValues[ 2] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_3(H1,H2,H3) + Message.Block.ulValues[10] + Constant;
		H4 = Rotate_Left(H4, 9, _32BIT);

		H3 += MD_4_3(H4,H1,H2) + Message.Block.ulValues[ 6] + Constant;
		H3 = Rotate_Left(H3,11, _32BIT);

		H2 += MD_4_3(H3,H4,H1) + Message.Block.ulValues[14] + Constant;
		H2 = Rotate_Left(H2,15, _32BIT);

		H1 += MD_4_3(H2,H3,H4) + Message.Block.ulValues[ 1] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_3(H1,H2,H3) + Message.Block.ulValues[ 9] + Constant;
		H4 = Rotate_Left(H4, 9, _32BIT);

		H3 += MD_4_3(H4,H1,H2) + Message.Block.ulValues[ 5] + Constant;
		H3 = Rotate_Left(H3,11, _32BIT);

		H2 += MD_4_3(H3,H4,H1) + Message.Block.ulValues[13] + Constant;
		H2 = Rotate_Left(H2,15, _32BIT);

		H1 += MD_4_3(H2,H3,H4) + Message.Block.ulValues[ 3] + Constant;
		H1 = Rotate_Left(H1, 3, _32BIT);

		H4 += MD_4_3(H1,H2,H3) + Message.Block.ulValues[11] + Constant;
		H4 = Rotate_Left(H4, 9, _32BIT);

		H3 += MD_4_3(H4,H1,H2) + Message.Block.ulValues[ 7] + Constant;
		H3 = Rotate_Left(H3,11, _32BIT);

		H2 += MD_4_3(H3,H4,H1) + Message.Block.ulValues[15] + Constant;
		H2 = Rotate_Left(H2,15, _32BIT);

		Hash.ulValues[j +  8] = H1;
		Hash.ulValues[j +  9] = H2;
		Hash.ulValues[j + 10] = H3;
		Hash.ulValues[j + 11] = H4;

		Constant = 0x5C4DD124L;
	}

	if(ucSignature_Type == MD_4_256)
	{
		// Swap the First Hash Values
		H1 = Hash.ulValues[4];
		Hash.ulValues[4] = Hash.ulValues[12];
		Hash.ulValues[12] = H1;
	}

	Hash.ulValues[0] += Hash.ulValues[ 8];
	Hash.ulValues[1] += Hash.ulValues[ 9];
	Hash.ulValues[2] += Hash.ulValues[10];
	Hash.ulValues[3] += Hash.ulValues[11];

	if(ucSignature_Type == MD_4_256)
	{
		Hash.ulValues[4] += Hash.ulValues[12];
		Hash.ulValues[5] += Hash.ulValues[13];
		Hash.ulValues[6] += Hash.ulValues[14];
		Hash.ulValues[7] += Hash.ulValues[15];
	}	
}
#endif
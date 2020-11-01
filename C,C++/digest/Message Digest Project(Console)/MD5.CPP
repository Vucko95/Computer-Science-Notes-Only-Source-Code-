#ifndef _MD5_CPP_
#define _MD5_CPP_
/*******************************************************************/
/*  Name of function : MD5_Transform

	Parameters: Nothing			
				
	Return Value : Nothing
	
	Purpose : Private Member Function to do the Transformation of the 
			  Message Block in MD5 Algorithm.
*/
/*******************************************************************/

VOID Signature_Context::MD5_Transform(VOID)
{
	register ULONG H1,H2,H3,H4; // So as to Speed up the operation
	

	H1 = Hash.ulValues[0];
	H2 = Hash.ulValues[1];
	H3 = Hash.ulValues[2];
	H4 = Hash.ulValues[3];

	/* Round - 1 */

	H1 += MD_5_1(H2,H3,H4) + Message.Block.ulValues[ 0] + 0xd76aa478;
	H1 = Rotate_Left(H1, 7,_32BIT);
	H1 += H2;

	H4 += MD_5_1(H1,H2,H3) + Message.Block.ulValues[ 1] + 0xe8c7b756;
	H4 = Rotate_Left(H4,12,_32BIT);
	H4 += H1;

	H3 += MD_5_1(H4,H1,H2) + Message.Block.ulValues[ 2] + 0x242070db;
	H3 = Rotate_Left(H3,17,_32BIT);
	H3 += H4;

	H2 += MD_5_1(H3,H4,H1) + Message.Block.ulValues[ 3] + 0xc1bdceee;
	H2 = Rotate_Left(H2,22,_32BIT);
	H2 += H3;

	H1 += MD_5_1(H2,H3,H4) + Message.Block.ulValues[ 4] + 0xf57c0faf;
	H1 = Rotate_Left(H1, 7,_32BIT);
	H1 += H2;

	H4 += MD_5_1(H1,H2,H3) + Message.Block.ulValues[ 5] + 0x4787c62a;
	H4 = Rotate_Left(H4,12,_32BIT);
	H4 += H1;

	H3 += MD_5_1(H4,H1,H2) + Message.Block.ulValues[ 6] + 0xa8304613;
	H3 = Rotate_Left(H3,17,_32BIT);
	H3 += H4;

	H2 += MD_5_1(H3,H4,H1) + Message.Block.ulValues[ 7] + 0xfd469501;
	H2 = Rotate_Left(H2,22,_32BIT);
	H2 += H3;

	H1 += MD_5_1(H2,H3,H4) + Message.Block.ulValues[ 8] + 0x698098d8;
	H1 = Rotate_Left(H1, 7,_32BIT);
	H1 += H2;

	H4 += MD_5_1(H1,H2,H3) + Message.Block.ulValues[ 9] + 0x8b44f7af;
	H4 = Rotate_Left(H4,12,_32BIT);
	H4 += H1;

	H3 += MD_5_1(H4,H1,H2) + Message.Block.ulValues[10] + 0xffff5bb1;
	H3 = Rotate_Left(H3,17,_32BIT);
	H3 += H4;

	H2 += MD_5_1(H3,H4,H1) + Message.Block.ulValues[11] + 0x895cd7be;
	H2 = Rotate_Left(H2,22,_32BIT);
	H2 += H3;

	H1 += MD_5_1(H2,H3,H4) + Message.Block.ulValues[12] + 0x6b901122;
	H1 = Rotate_Left(H1, 7,_32BIT);
	H1 += H2;

	H4 += MD_5_1(H1,H2,H3) + Message.Block.ulValues[13] + 0xfd987193;
	H4 = Rotate_Left(H4,12,_32BIT);
	H4 += H1;

	H3 += MD_5_1(H4,H1,H2) + Message.Block.ulValues[14] + 0xa679438e;
	H3 = Rotate_Left(H3,17,_32BIT);
	H3 += H4;

	H2 += MD_5_1(H3,H4,H1) + Message.Block.ulValues[15] + 0x49b40821;
	H2 = Rotate_Left(H2,22,_32BIT);
	H2 += H3;

	/* Round - 2 */

	H1 += MD_5_2(H2,H3,H4) + Message.Block.ulValues[ 1] + 0xf61e2562;
	H1 = Rotate_Left(H1, 5,_32BIT);
	H1 += H2;

	H4 += MD_5_2(H1,H2,H3) + Message.Block.ulValues[ 6] + 0xc040b340;
	H4 = Rotate_Left(H4, 9,_32BIT);
	H4 += H1;

	H3 += MD_5_2(H4,H1,H2) + Message.Block.ulValues[11] + 0x265e5a51;
	H3 = Rotate_Left(H3,14,_32BIT);
	H3 += H4;

	H2 += MD_5_2(H3,H4,H1) + Message.Block.ulValues[ 0] + 0xe9b6c7aa;
	H2 = Rotate_Left(H2,20,_32BIT);
	H2 += H3;

	H1 += MD_5_2(H2,H3,H4) + Message.Block.ulValues[ 5] + 0xd62f105d;
	H1 = Rotate_Left(H1, 5,_32BIT);
	H1 += H2;

	H4 += MD_5_2(H1,H2,H3) + Message.Block.ulValues[10] + 0x02441453;
	H4 = Rotate_Left(H4, 9,_32BIT);
	H4 += H1;

	H3 += MD_5_2(H4,H1,H2) + Message.Block.ulValues[15] + 0xd8a1e681;
	H3 = Rotate_Left(H3,14,_32BIT);
	H3 += H4;

	H2 += MD_5_2(H3,H4,H1) + Message.Block.ulValues[ 4] + 0xe7d3fbc8;
	H2 = Rotate_Left(H2,20,_32BIT);
	H2 += H3;

	H1 += MD_5_2(H2,H3,H4) + Message.Block.ulValues[ 9] + 0x21e1cde6;
	H1 = Rotate_Left(H1, 5,_32BIT);
	H1 += H2;

	H4 += MD_5_2(H1,H2,H3) + Message.Block.ulValues[14] + 0xc33707d6;
	H4 = Rotate_Left(H4, 9,_32BIT);
	H4 += H1;

	H3 += MD_5_2(H4,H1,H2) + Message.Block.ulValues[ 3] + 0xf4d50d87;
	H3 = Rotate_Left(H3,14,_32BIT);
	H3 += H4;

	H2 += MD_5_2(H3,H4,H1) + Message.Block.ulValues[ 8] + 0x455a14ed;
	H2 = Rotate_Left(H2,20,_32BIT);
	H2 += H3;

	H1 += MD_5_2(H2,H3,H4) + Message.Block.ulValues[13] + 0xa9e3e905;
	H1 = Rotate_Left(H1, 5,_32BIT);
	H1 += H2;

	H4 += MD_5_2(H1,H2,H3) + Message.Block.ulValues[ 2] + 0xfcefa3f8;
	H4 = Rotate_Left(H4, 9,_32BIT);
	H4 += H1;

	H3 += MD_5_2(H4,H1,H2) + Message.Block.ulValues[ 7] + 0x676f02d9;
	H3 = Rotate_Left(H3,14,_32BIT);
	H3 += H4;

	H2 += MD_5_2(H3,H4,H1) + Message.Block.ulValues[12] + 0x8d2a4c8a;
	H2 = Rotate_Left(H2,20,_32BIT);
	H2 += H3;

	/* Round - 3 */

	H1 += MD_5_3(H2,H3,H4) + Message.Block.ulValues[ 5] + 0xfffa3942;
	H1 = Rotate_Left(H1, 4,_32BIT);
	H1 += H2;

	H4 += MD_5_3(H1,H2,H3) + Message.Block.ulValues[ 8] + 0x8771f681;
	H4 = Rotate_Left(H4,11,_32BIT);
	H4 += H1;

	H3 += MD_5_3(H4,H1,H2) + Message.Block.ulValues[11] + 0x6d9d6122;
	H3 = Rotate_Left(H3,16,_32BIT);
	H3 += H4;

	H2 += MD_5_3(H3,H4,H1) + Message.Block.ulValues[14] + 0xfde5380c;
	H2 = Rotate_Left(H2,23,_32BIT);
	H2 += H3;

	H1 += MD_5_3(H2,H3,H4) + Message.Block.ulValues[ 1] + 0xa4beea44;
	H1 = Rotate_Left(H1, 4,_32BIT);
	H1 += H2;

	H4 += MD_5_3(H1,H2,H3) + Message.Block.ulValues[ 4] + 0x4bdecfa9;
	H4 = Rotate_Left(H4,11,_32BIT);
	H4 += H1;

	H3 += MD_5_3(H4,H1,H2) + Message.Block.ulValues[ 7] + 0xf6bb4b60;
	H3 = Rotate_Left(H3,16,_32BIT);
	H3 += H4;

	H2 += MD_5_3(H3,H4,H1) + Message.Block.ulValues[10] + 0xbebfbc70;
	H2 = Rotate_Left(H2,23,_32BIT);
	H2 += H3;

	H1 += MD_5_3(H2,H3,H4) + Message.Block.ulValues[13] + 0x289b7ec6;
	H1 = Rotate_Left(H1, 4,_32BIT);
	H1 += H2;

	H4 += MD_5_3(H1,H2,H3) + Message.Block.ulValues[ 0] + 0xeaa127fa;
	H4 = Rotate_Left(H4,11,_32BIT);
	H4 += H1;

	H3 += MD_5_3(H4,H1,H2) + Message.Block.ulValues[ 3] + 0xd4ef3085;
	H3 = Rotate_Left(H3,16,_32BIT);
	H3 += H4;

	H2 += MD_5_3(H3,H4,H1) + Message.Block.ulValues[ 6] + 0x04881d05;
	H2 = Rotate_Left(H2,23,_32BIT);
	H2 += H3;

	H1 += MD_5_3(H2,H3,H4) + Message.Block.ulValues[ 9] + 0xd9d4d039;
	H1 = Rotate_Left(H1, 4,_32BIT);
	H1 += H2;

	H4 += MD_5_3(H1,H2,H3) + Message.Block.ulValues[12] + 0xe6db99e5;
	H4 = Rotate_Left(H4,11,_32BIT);
	H4 += H1;

	H3 += MD_5_3(H4,H1,H2) + Message.Block.ulValues[15] + 0x1fa27cf8;
	H3 = Rotate_Left(H3,16,_32BIT);
	H3 += H4;

	H2 += MD_5_3(H3,H4,H1) + Message.Block.ulValues[ 2] + 0xc4ac5665;
	H2 = Rotate_Left(H2,23,_32BIT);
	H2 += H3;

	/* Round - 4 */

	H1 += MD_5_4(H2,H3,H4) + Message.Block.ulValues[ 0] + 0xf4292244;
	H1 = Rotate_Left(H1, 6,_32BIT);
	H1 += H2;

	H4 += MD_5_4(H1,H2,H3) + Message.Block.ulValues[ 7] + 0x432aff97;
	H4 = Rotate_Left(H4,10,_32BIT);
	H4 += H1;

	H3 += MD_5_4(H4,H1,H2) + Message.Block.ulValues[14] + 0xab9423a7;
	H3 = Rotate_Left(H3,15,_32BIT);
	H3 += H4;

	H2 += MD_5_4(H3,H4,H1) + Message.Block.ulValues[ 5] + 0xfc93a039;
	H2 = Rotate_Left(H2,21,_32BIT);
	H2 += H3;

	H1 += MD_5_4(H2,H3,H4) + Message.Block.ulValues[12] + 0x655b59c3;
	H1 = Rotate_Left(H1, 6,_32BIT);
	H1 += H2;

	H4 += MD_5_4(H1,H2,H3) + Message.Block.ulValues[ 3] + 0x8f0ccc92;
	H4 = Rotate_Left(H4,10,_32BIT);
	H4 += H1;

	H3 += MD_5_4(H4,H1,H2) + Message.Block.ulValues[10] + 0xffeff47d;
	H3 = Rotate_Left(H3,15,_32BIT);
	H3 += H4;

	H2 += MD_5_4(H3,H4,H1) + Message.Block.ulValues[ 1] + 0x85845dd1;
	H2 = Rotate_Left(H2,21,_32BIT);
	H2 += H3;

	H1 += MD_5_4(H2,H3,H4) + Message.Block.ulValues[ 8] + 0x6fa87e4f;
	H1 = Rotate_Left(H1, 6,_32BIT);
	H1 += H2;

	H4 += MD_5_4(H1,H2,H3) + Message.Block.ulValues[15] + 0xfe2ce6e0;
	H4 = Rotate_Left(H4,10,_32BIT);
	H4 += H1;

	H3 += MD_5_4(H4,H1,H2) + Message.Block.ulValues[ 6] + 0xa3014314;
	H3 = Rotate_Left(H3,15,_32BIT);
	H3 += H4;

	H2 += MD_5_4(H3,H4,H1) + Message.Block.ulValues[13] + 0x4e0811a1;
	H2 = Rotate_Left(H2,21,_32BIT);
	H2 += H3;

	H1 += MD_5_4(H2,H3,H4) + Message.Block.ulValues[ 4] + 0xf7537e82;
	H1 = Rotate_Left(H1, 6,_32BIT);
	H1 += H2;

	H4 += MD_5_4(H1,H2,H3) + Message.Block.ulValues[11] + 0xbd3af235;
	H4 = Rotate_Left(H4,10,_32BIT);
	H4 += H1;

	H3 += MD_5_4(H4,H1,H2) + Message.Block.ulValues[ 2] + 0x2ad7d2bb;
	H3 = Rotate_Left(H3,15,_32BIT);
	H3 += H4;

	H2 += MD_5_4(H3,H4,H1) + Message.Block.ulValues[ 9] + 0xeb86d391;
	H2 = Rotate_Left(H2,21,_32BIT);
	H2 += H3;

	Hash.ulValues[0] += H1;
	Hash.ulValues[1] += H2;
	Hash.ulValues[2] += H3;
	Hash.ulValues[3] += H4;
}
#endif
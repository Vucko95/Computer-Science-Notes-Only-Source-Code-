#ifndef _OTHER_FUNCTIONS_CPP_
#define _OTHER_FUNCTIONS_CPP_

template <class T>
T Endian_Conversion(T Input)
{
	unsigned char * OutArr = (unsigned char *) &Input;
	for(char i = 0, j = 0, k = sizeof(Input) -1;i < k;i++,k--)
	{
		j = OutArr[i];
		OutArr[i] = OutArr[k];
		OutArr[k] = j;
	}
	return Input;
}
#endif
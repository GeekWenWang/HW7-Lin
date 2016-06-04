# include < iostream >
# include < cstdlib >
#include <string.h>

#include "unixCmd.h"

#define CMD_IN_LINE 10;

using namespace std; 

UNIX_DATA unixData;
UNIX_DATA *unixDataPtr = &unixData;


int main( int argc, char *argv[])
{
	char cmdName[10];

	char *dynamicBufferPtr1;

	dynamicBufferPtr1 = (char*)malloc(10);

	scanf("%s", cmdName);

	strcpy(dynamicBufferPtr1 , cmdName);

	argv[0] = dynamicBufferPtr1;

	//free(dynamicBufferPtr1);

	if ( *argv[0] == 'c')
	{
		unixDataPtr->unixCmd = cat; 
	}

	else if ( *argv[0] == 'r')
	{
		unixDataPtr->unixCmd = removetag; 
	}

	switch(unixDataPtr->unixCmd)
	{
	case cat:
		char* dynamicBufferPtr;
		char* dynamicBufferPtr2;
		int size;
		char fileName[40];

		scanf( "%s", &fileName);

		dynamicBufferPtr2 = (char*)malloc(40);

		strcpy(dynamicBufferPtr2, fileName);

		//argv[1] = dynamicBufferPtr2;

		//free(dynamicBufferPtr2);

		FILE *filePtr;

		char *asciiPtr;

		filePtr = fopen(dynamicBufferPtr2, "r");

		if(filePtr != NULL)
		{
			fseek(filePtr, 1, SEEK_END);
			size = ftell(filePtr);
			fseek(filePtr, 1, SEEK_SET);

			dynamicBufferPtr = (char*)malloc(size+1);

			for( int i=0;i<size;i++)
			{
				dynamicBufferPtr[i] = '\0';
			}
		}

		if(dynamicBufferPtr != NULL)
		{
			fread( dynamicBufferPtr, sizeof(char), size, filePtr);
			asciiPtr = dynamicBufferPtr;
		}

		for( int i=size ; i>0 ;i--)
		{
			printf( "%c", *asciiPtr);
			asciiPtr++;
		}
		system("pause");
		break;
	case removetag:
		break;

	}











	return 1;
}
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
	readCmd(unixDataPtr);

	argv[0] = unixDataPtr->dynamicBufferPtr1;

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
		scanf( "%s", &unixDataPtr->fileName);

		unixDataPtr->dynamicBufferPtr2 = (char*)malloc(40);

		strcpy(unixDataPtr->dynamicBufferPtr2, unixDataPtr->fileName);

		//argv[1] = dynamicBufferPtr2;

		//free(dynamicBufferPtr2);
		
		openFile(unixDataPtr);

		if(unixDataPtr->dynamicBufferPtr != NULL)
		{
			fread( unixDataPtr->dynamicBufferPtr, sizeof(char), unixDataPtr->size, unixDataPtr->filePtr);
			unixDataPtr->asciiPtr = unixDataPtr->dynamicBufferPtr;
		}

		for( int i=unixDataPtr->size ; i>0 ;i--)
		{
			printf( "%c", *unixDataPtr->asciiPtr);
			unixDataPtr->asciiPtr++;
		}

		fclose(unixDataPtr->filePtr);
		break;
	case removetag:
		scanf( "%s", &unixDataPtr->fileName);

		unixDataPtr->dynamicBufferPtr2 = (char*)malloc(40);

		strcpy(unixDataPtr->dynamicBufferPtr2, unixDataPtr->fileName);

		//argv[1] = dynamicBufferPtr2;

		//free(dynamicBufferPtr2);

		openFile(unixDataPtr);

		if(unixDataPtr->dynamicBufferPtr != NULL)
		{
			fread( unixDataPtr->dynamicBufferPtr, sizeof(char), unixDataPtr->size, unixDataPtr->filePtr);
			unixDataPtr->asciiPtr = unixDataPtr->dynamicBufferPtr;
		}

		for( int i=unixDataPtr->size ; i>0 ;i--)
		{
			if( *unixDataPtr->asciiPtr !='='&& *unixDataPtr->asciiPtr !='+'&& *unixDataPtr->asciiPtr != ',' && *unixDataPtr->asciiPtr !='.' && *unixDataPtr->asciiPtr !='/'&&  *unixDataPtr->asciiPtr != '"'&& *unixDataPtr->asciiPtr != '!' && *unixDataPtr->asciiPtr !='-'&& *unixDataPtr->asciiPtr !=';'&& *unixDataPtr->asciiPtr !='('&& *unixDataPtr->asciiPtr !=')')
			{
				printf( "%c", *unixDataPtr->asciiPtr);
				unixDataPtr->asciiPtr++;
			}
			else
			{
				unixDataPtr->asciiPtr++;
			}
		}

		fclose(unixDataPtr->filePtr);
		

		break;

	}

	char operater[1];

	scanf ( "%s", &operater);

	if(*operater == '>' && unixDataPtr->unixCmd == cat)
	{

		scanf("%s", &unixDataPtr->nextFileName);

		unixDataPtr->dynamicBufferPtr3 = (char*)malloc(40);

		strcpy(unixDataPtr->dynamicBufferPtr3, unixDataPtr->nextFileName);


		unixDataPtr->nextFilePtr = fopen(unixDataPtr->dynamicBufferPtr3, "w");

		openFile(unixDataPtr);

		if(unixDataPtr->dynamicBufferPtr != NULL)
		{
			fread( unixDataPtr->dynamicBufferPtr, sizeof(char), unixDataPtr->size, unixDataPtr->filePtr);
			unixDataPtr->asciiPtr1 = unixDataPtr->dynamicBufferPtr;
		}

		for( int i=unixDataPtr->size ; i>0 ;i--)
		{
			fprintf(unixDataPtr->nextFilePtr ,"%c", *unixDataPtr->asciiPtr1);
			unixDataPtr->asciiPtr1++;
		}

		fclose(unixDataPtr->filePtr);
		fclose(unixDataPtr->nextFilePtr);
	}

	else if(*operater == '>' && unixDataPtr->unixCmd == removetag)
	{

		scanf("%s", &unixDataPtr->nextFileName);

		unixDataPtr->dynamicBufferPtr3 = (char*)malloc(40);

		strcpy(unixDataPtr->dynamicBufferPtr3, unixDataPtr->nextFileName);


		unixDataPtr->nextFilePtr = fopen(unixDataPtr->dynamicBufferPtr3, "w");

		openFile(unixDataPtr);

		if(unixDataPtr->dynamicBufferPtr != NULL)
		{
			fread( unixDataPtr->dynamicBufferPtr, sizeof(char), unixDataPtr->size, unixDataPtr->filePtr);
			unixDataPtr->asciiPtr1 = unixDataPtr->dynamicBufferPtr;
		}

		for( int i=unixDataPtr->size ; i>0 ;i--)
		{
			if( *unixDataPtr->asciiPtr1 !='='&& *unixDataPtr->asciiPtr1 !='+'&& *unixDataPtr->asciiPtr1 != ',' && *unixDataPtr->asciiPtr1 !='.' && *unixDataPtr->asciiPtr1 !='/'&&  *unixDataPtr->asciiPtr1 != '"'&& *unixDataPtr->asciiPtr1 != '!' && *unixDataPtr->asciiPtr1 !='-'&& *unixDataPtr->asciiPtr1 !=';'&& *unixDataPtr->asciiPtr1 !='('&& *unixDataPtr->asciiPtr1 !=')')
			{
				fprintf(unixDataPtr->nextFilePtr ,"%c", *unixDataPtr->asciiPtr1);
				unixDataPtr->asciiPtr1++;
			}
			else
			{
				unixDataPtr->asciiPtr1++;
			}
		}

		fclose(unixDataPtr->filePtr);
		fclose(unixDataPtr->nextFilePtr);
	}
	system("pause");

	return 1;
}
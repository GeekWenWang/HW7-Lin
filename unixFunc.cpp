#include <iostream>
#include <cstdlib>
#include <string.h>

#include "unixCmd.h"

extern UNIX_DATA* unixDataPtr;

void readCmd(UNIX_DATA *unixDataPtr)
{
	unixDataPtr->dynamicBufferPtr1 = (char*)malloc(10);
	
	scanf("%s", unixDataPtr->cmdName);

	strcpy(unixDataPtr->dynamicBufferPtr1 , unixDataPtr->cmdName);

	return;
}

int openFile(UNIX_DATA *unixDataPtr)
{
	if (NULL ==( unixDataPtr->filePtr = fopen(unixDataPtr->dynamicBufferPtr2, "rb")))
	{
		//printf("�䤣����|");
		return 0;
	}

	unixDataPtr->filePtr = fopen(unixDataPtr->dynamicBufferPtr2, "r");

	if(unixDataPtr->filePtr != NULL)
	{
		fseek(unixDataPtr->filePtr, 0, SEEK_END);
		unixDataPtr->size = ftell(unixDataPtr->filePtr);
		fseek(unixDataPtr->filePtr, 0, SEEK_SET);

		unixDataPtr->dynamicBufferPtr = (char*)malloc(unixDataPtr->size+1);

		for( int i=0;i<unixDataPtr->size;i++)
		{
			unixDataPtr->dynamicBufferPtr[i] = '\0';
		}
	}


	return 1;
}
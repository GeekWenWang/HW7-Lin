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
	bool run;
	run = true;
	
	while(run == true)
	{
		readCmd(unixDataPtr);

		argv[0] = unixDataPtr->dynamicBufferPtr1;

		//free(dynamicBufferPtr1);

		if ( unixDataPtr->cmdName[0] == 'c' && unixDataPtr->cmdName[1] == 'a' && unixDataPtr->cmdName[2]== 't')
		{
			unixDataPtr->unixCmd = cat; 
		}

		else if ( unixDataPtr->cmdName[0] == 'r' && unixDataPtr->cmdName[1] == 'e' && unixDataPtr->cmdName[2] == 'm' &&unixDataPtr->cmdName[3] =='o'&& unixDataPtr->cmdName[4] == 'v'&& unixDataPtr->cmdName[5] == 'e' && unixDataPtr->cmdName[6] == 't' && unixDataPtr->cmdName[7] == 'a' &&unixDataPtr->cmdName[8]=='g')
		{
			unixDataPtr->unixCmd = removetag; 
		}

		else if ( unixDataPtr->cmdName[0] == 'e' && unixDataPtr->cmdName[1] == 'x' && unixDataPtr->cmdName[2] == 'i' &&unixDataPtr->cmdName[3] =='t')
		{
			run = false;
			return 1;
		}
		else
		{
			unixDataPtr->unixCmd = notdefined;
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

		case notdefined:
			cout << "unknown Command" <<endl;

			continue;

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

		free(unixDataPtr->dynamicBufferPtr);
		free(unixDataPtr->dynamicBufferPtr1);
		free(unixDataPtr->dynamicBufferPtr2);
		free(unixDataPtr->dynamicBufferPtr3);

	}
	//system("pause");

	return 1;
}

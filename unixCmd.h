#ifndef _UNIX_H
#define _UNIX_H


enum UNIXCMD{cat,removetag};

struct UNIX_DATA
{
	char cmdName[10];

	char* dynamicBufferPtr;

	char* dynamicBufferPtr1;

	char* dynamicBufferPtr2;

	char* dynamicBufferPtr3;

	char* dynamicBufferPtr4;

	int size;
	char fileName[40];

	char* asciiPtr;

	char* asciiPtr1;

	char nextFileName[40];
	

	UNIXCMD unixCmd;

	FILE *filePtr;
	FILE *nextFilePtr;



	
};

	int openFile(UNIX_DATA *unixDataPtr);
	void readCmd(UNIX_DATA *unixDataPtr);
	int readFile( int argc, char argv[]);




#endif
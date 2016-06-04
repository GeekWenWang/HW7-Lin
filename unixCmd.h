#ifndef _UNIX_H
#define _UNIX_H


enum UNIXCMD{cat,removetag};

struct UNIX_DATA
{
	char* cmdName;

	char* dynamicBufferPtr;

	UNIXCMD unixCmd;



	
};

	int openFile(UNIX_DATA *unixDataPtr);
	int readCmd(UNIX_DATA *unixDataPtr);
	int readFile( int argc, char argv[]);




#endif
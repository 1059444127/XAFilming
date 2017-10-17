#include "XAFilmingFile.h"
#include <ctime>
#include "XAFilmingConst.h"

using namespace  std;



char * rand_str(char *str, const int len)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	for (int i=0; i<len; i++)
	{
		str[i] = rand()%2 ? 'a'+rand()%26 : '0'+rand()%10;
	}
	return str;
}


string CreateDicomFilePath()
{
	char fileName[20];
	return string(XA_FILMING_TEMP_DIRECTORY) + rand_str(fileName, 20);
}

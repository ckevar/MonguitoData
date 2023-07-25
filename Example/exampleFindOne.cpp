#include <iostream>
#include <cstring>
#include <PapayitaWC.h>

#include "monguitodata.h"

#define BUFF_CAPACTIY 22000 

int main(int argc, char const *argv[])
{
	PapayitaWC papayita;
	papayita_buffer buff;
	MonguitoData myMongo(&papayita, "<APP_ID>", "<TOKEN>");
	char buff_core[BUFF_CAPACTIY];
	buff.capacity = BUFF_CAPACTIY;
	buff.head = buff;

	char collection[] = "<COLLECTION>";
	char itemTag[] = "<YOUR_FILTER>";

	int buff.size = sprintf(buff.head, "{\
\"dataSource\":\"<DATA_SOURCE>\",\
\"collection\":\"%s\",\
\"database\":\"<DATABASE>\",\
\"filter\":{\
\"<YOUR_FILTER>\":\"%s\"\
}}", collection, itemTag);

	buff_io = myMongo.findOne(&buff);
	std::cout << buff << std::endl;
	/* code */
	return 0;
}
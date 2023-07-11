#include <iostream>
#include <cstring>
#include <PapayitaWC.h>

#include "monguitodata.h"

int main(int argc, char const *argv[])
{
	PapayitaWC papayita;
	MonguitoData myMongo(&papayita, "<APP_ID>", "<TOKEN>");
	int buff_size = 22000;
	char buff[buff_size];

	char collection[] = "<COLLECTION>";
	char itemTag[] = "<YOUR_FILTER>";

	int buff_io = sprintf(buff, "{\
\"dataSource\":\"<DATA_SOURCE>\",\
\"collection\":\"%s\",\
\"database\":\"<DATABASE>\",\
\"filter\":{\
\"<YOUR_FILTER>\":\"%s\"\
}}", collection, itemTag);

	buff_io = myMongo.findOne(buff, buff_io, buff_size);
	std::cout << buff << std::endl;
	/* code */
	return 0;
}
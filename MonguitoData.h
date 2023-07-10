#ifndef MONGUITO_DATA_H
#define MONGUITO_DATA_H 

#include <PapayitaWC.h>

#define MDB_ACTION_FINDONE 		"/action/findOne"
#define MDB_ACTION_FINDONE_LEN 	15

class MonguitoData
{
public:
	MonguitoData(PapayitaWC *pa2ya, const char *APP_ID, const char *API_KEY);

	int findOne(char *payload, int buff_in, int buff_out);

	~MonguitoData();

private:
	char m_resource[70];
	char m_host[20];
	char m_API_KEY_header[80];
	char *m_resource_it;

	/* Ppointer to the Web Client */
	PapayitaWC *m_pa2ya;
	
	void settings();
};
#endif
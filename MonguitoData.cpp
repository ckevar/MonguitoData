#include "MonguitoData.h"
#include <cstring>
#include <iostream>

MonguitoData::MonguitoData(PapayitaWC *pa2ya, const char *APP_ID, const char *API_KEY) {
	sprintf(m_API_KEY_header, "Api-Key: %s", API_KEY);
	m_resource_it = m_resource + sprintf(m_resource, "/app/%s/endpoint/data/v1", APP_ID);
	m_pa2ya = pa2ya;
}

void MonguitoData::settings() {	
	m_pa2ya->set_header("Content-Type: application/json");
	m_pa2ya->set_header(m_API_KEY_header);
}

int MonguitoData::findOne(char *payload, int buff_in, int buff_out) {

	m_pa2ya->new_session("data.mongodb-api.com");	
	if (m_pa2ya->get_error() < 0)
		return -1;	

	memcpy(m_resource_it, MDB_ACTION_FINDONE, MDB_ACTION_FINDONE_LEN);
	
	settings();

	buff_out = m_pa2ya->post(m_resource, payload, buff_in, buff_out);
	
	if (buff_out <= 0)
		std::cerr << "[ERROR:] Nothing was return from server" << std::endl;

	m_pa2ya->terminate_session();
	
	return buff_out;
}

MonguitoData::~MonguitoData() {

}
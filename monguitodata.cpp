#include "monguitodata.h"
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

// int MonguitoData::callAPI(const char *action, const int action_size, char *payload, int buff_in, int buff_out) {
void MonguitoData::callAPI(const char *action, const int action_size, papayita_buffer *payload) {

	m_pa2ya->new_session("data.mongodb-api.com");	
	if (m_pa2ya->get_error() < 0) return;
		

	memcpy(m_resource_it, action, action_size);
	settings();

	payload->size = m_pa2ya->post(m_resource, payload->head, payload->size, payload->capacity);
	
	if (payload->size <= 0)
		std::cerr << "[ERROR:] Nothing was return from server" << std::endl;

	m_pa2ya->terminate_session();
	
}

void MonguitoData::findOne(papayita_buffer *payload) {
	callAPI(MDB_ACTION_FINDONE, MDB_ACTION_FINDONE_LEN, payload);	
}

void MonguitoData::updateOne(papayita_buffer *payload) {
	callAPI(MDB_ACTION_UPDATEONE, MDB_ACTION_UPDATEONE_LEN, payload);
}

MonguitoData::~MonguitoData() {

}
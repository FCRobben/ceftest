#include "simple_local_resource_handler.h"
#include "simple_tools.h"

SimpleLocalResourceHandler::SimpleLocalResourceHandler()
{

}

SimpleLocalResourceHandler::~SimpleLocalResourceHandler()
{
	if (m_pLocalFileReader)
		delete m_pLocalFileReader;
}

bool SimpleLocalResourceHandler::Open(CefRefPtr<CefRequest> request, bool& handle_request, CefRefPtr<CefCallback> callback)
{
	auto strUrl = request->GetURL().ToString();

	size_t index = strUrl.find("http://local.test.cn");
	if (index == 0)
	{
		auto apiPath = strUrl.substr(sizeof("http://local.test.cn"));
		m_pLocalFileReader = new SimpleTools::LocalFileReader();
		if(m_pLocalFileReader->PreRead(SimpleTools::GetResouceDir() + "/" + apiPath))
		{
			handle_request = true;
			return true;
		}
	}
	return false;
}

void SimpleLocalResourceHandler::GetResponseHeaders(CefRefPtr<CefResponse> response, int64& response_length, CefString& redirectUrl)
{
	response->SetMimeType(m_pLocalFileReader->MimeType());
	response_length = -1;
}

bool SimpleLocalResourceHandler::Skip(int64 bytes_to_skip, int64& bytes_skipped, CefRefPtr<CefResourceSkipCallback> callback)
{
	return false;
}

bool SimpleLocalResourceHandler::Read(void* data_out, int bytes_to_read, int& bytes_read, CefRefPtr<CefResourceReadCallback> callback)
{
	assert(m_pLocalFileReader);
	bytes_read = m_pLocalFileReader->Read(data_out, bytes_to_read);
	if (bytes_read == 0)
		return false;
	return true;
}

void SimpleLocalResourceHandler::Cancel()
{
}
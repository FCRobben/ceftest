#include "simple_scheme_handler.h"
#include <fstream>

#include "simple_tools.h"

static SimpleTools::LocalFileReader s_reader;

bool SimpleSchmeHandler::Open(CefRefPtr<CefRequest> request, bool& handle_request, CefRefPtr<CefCallback> callback)
{
	handle_request = true;

	s_reader.PreRead(SimpleTools::GetModuleDir() + "/local/img/" + "naruto.jpg");

	return true;
}

void SimpleSchmeHandler::GetResponseHeaders(CefRefPtr<CefResponse> response, int64& response_length, CefString& redirectUrl)
{
	response_length = -1;
	response->SetStatus(200);
}

bool SimpleSchmeHandler::Skip(int64 bytes_to_skip, int64& bytes_skipped, CefRefPtr<CefResourceSkipCallback> callback)
{
	return false;
}

bool SimpleSchmeHandler::Read(void* data_out, int bytes_to_read, int& bytes_read, CefRefPtr<CefResourceReadCallback> callback)
{
	bytes_read = s_reader.Read(data_out, bytes_to_read);
	if (bytes_read <= 0)
	{
		return false;
	}
	return true;
}

void SimpleSchmeHandler::Cancel()
{
}

#include "simple_scheme_handler_factory.h"
#include "simple_scheme_handler.h"

SimpleSchmeHandlerFactory::SimpleSchmeHandlerFactory()
{
}

SimpleSchmeHandlerFactory::~SimpleSchmeHandlerFactory()
{
}

CefRefPtr<CefResourceHandler> SimpleSchmeHandlerFactory::Create(
	CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, const CefString& scheme_name, CefRefPtr<CefRequest> request)
{
	if (scheme_name == "simple")
	{
		return new SimpleSchmeHandler();
	}
	return nullptr;
}

#ifndef CEF_TESTS_CEFSIMPLE_RESOURCE_REQUEST_HANDLER_H_
#define CEF_TESTS_CEFSIMPLE_RESOURCE_REQUEST_HANDLER_H_

#include "include/cef_resource_request_handler.h"
#include "include/cef_base.h"

class SimpleResourceRequestHandler :public CefResourceRequestHandler
{
public:

    SimpleResourceRequestHandler();

    virtual CefRefPtr<CefResourceHandler> GetResourceHandler(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        CefRefPtr<CefRequest> request) override;

private:
	IMPLEMENT_REFCOUNTING(SimpleResourceRequestHandler);
    CefRefPtr<CefResourceHandler> m_spLocalResouceHandler;
};

#endif // CEF_TESTS_CEFSIMPLE_RESOURCE_REQUEST_HANDLER_H_
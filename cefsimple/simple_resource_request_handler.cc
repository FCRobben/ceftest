#include "simple_resource_request_handler.h"

#include "simple_local_resource_handler.h"

SimpleResourceRequestHandler::SimpleResourceRequestHandler()
{

}

CefRefPtr<CefResourceHandler> SimpleResourceRequestHandler::GetResourceHandler(
    CefRefPtr<CefBrowser> browser,
    CefRefPtr<CefFrame> frame,
    CefRefPtr<CefRequest> request)
{
     return new SimpleLocalResourceHandler();
}


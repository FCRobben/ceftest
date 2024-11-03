#ifndef CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_FACTORY_H_
#define CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_FACTORY_H_

#include "include/cef_scheme.h"
#include "include/cef_base.h"

class SimpleSchmeHandlerFactory : public CefSchemeHandlerFactory
{
public:
	SimpleSchmeHandlerFactory();
	~SimpleSchmeHandlerFactory();

    virtual CefRefPtr<CefResourceHandler> Create(
        CefRefPtr<CefBrowser> browser,
        CefRefPtr<CefFrame> frame,
        const CefString& scheme_name,
        CefRefPtr<CefRequest> request) override;

private:
    IMPLEMENT_REFCOUNTING(SimpleSchmeHandlerFactory);
};


#endif //CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_FACTORY_H_
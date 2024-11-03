#ifndef CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_H_
#define CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_H_

#include "include/cef_resource_handler.h"
#include "include/cef_base.h"

class SimpleSchmeHandler:public CefResourceHandler
{
public:
    bool Open(CefRefPtr<CefRequest> request,
        bool& handle_request,
        CefRefPtr<CefCallback> callback)override;

    void GetResponseHeaders(CefRefPtr<CefResponse> response,
        int64& response_length,
        CefString& redirectUrl) override;

    bool Skip(int64 bytes_to_skip,
        int64& bytes_skipped,
        CefRefPtr<CefResourceSkipCallback> callback) override;

    bool Read(void* data_out,
        int bytes_to_read,
        int& bytes_read,
        CefRefPtr<CefResourceReadCallback> callback) override;

    void Cancel() override;
private:
    IMPLEMENT_REFCOUNTING(SimpleSchmeHandler);

};

#endif // CEF_TESTS_CEFSIMPLE_SCHME_HANDLER_H_
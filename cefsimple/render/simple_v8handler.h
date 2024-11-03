#ifndef CEF_TESTS_CEFSIMPLE_SIMPLE_V8_HANDLER_H_
#define CEF_TESTS_CEFSIMPLE_SIMPLE_V8_HANDLER_H_
#include "include/cef_v8.h"

class SimpleV8Handler:public CefV8Handler
{
public:
	virtual bool Execute(const CefString& name,
		CefRefPtr<CefV8Value> object,
		const CefV8ValueList& arguments,
		CefRefPtr<CefV8Value>& retval,
		CefString& exception) override;
private:
	IMPLEMENT_REFCOUNTING(SimpleV8Handler);
};

#endif //CEF_TESTS_CEFSIMPLE_SIMPLE_V8_HANDLER_H_
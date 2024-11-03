#ifndef CEF_TESTS_CEFSIMPLE_SIMPLE_RENDER_APP_H_
#define CEF_TESTS_CEFSIMPLE_SIMPLE_RENDER_APP_H_

#include "include/cef_app.h"

class SimpleRenderApp :public CefApp,
	public  CefRenderProcessHandler,
	public CefLifeSpanHandler,
	public CefLoadHandler
{
public:
	//CefApp
	virtual CefRefPtr<CefRenderProcessHandler> GetRenderProcessHandler() override { return this; }

	//CefRenderProcessHandler
	virtual void OnWebKitInitialized() override;
	virtual void OnBrowserCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefDictionaryValue> extra_info) override;
	virtual void OnContextCreated(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		CefRefPtr<CefV8Context> context) override;
	virtual CefRefPtr<CefLoadHandler> GetLoadHandler() override { return this; }

	//CefLoadHandler
	virtual void OnLoadStart(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		TransitionType transition_type) override;
	virtual void OnLoadEnd(CefRefPtr<CefBrowser> browser,
		CefRefPtr<CefFrame> frame,
		int httpStatusCode) override;
private:
	// Include the default reference counting implementation.
	IMPLEMENT_REFCOUNTING(SimpleRenderApp);
};

#endif //CEF_TESTS_CEFSIMPLE_SIMPLE_RENDER_APP_H_
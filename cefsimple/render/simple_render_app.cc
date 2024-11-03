#include "simple_render_app.h"
#include "simple_v8handler.h"

void SimpleRenderApp::OnWebKitInitialized()
{

}

void SimpleRenderApp::OnBrowserCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefDictionaryValue> extra_info)
{
	//int id = browser->GetIdentifier();
}

void SimpleRenderApp::OnContextCreated(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, CefRefPtr<CefV8Context> context)
{
	CefRefPtr<CefV8Value> object = context->GetGlobal();
	CefRefPtr<CefV8Handler> handler = new SimpleV8Handler();
	CefRefPtr<CefV8Value> func = CefV8Value::CreateFunction("sum", handler);
	object->SetValue("sum", func, V8_PROPERTY_ATTRIBUTE_NONE);
}

void SimpleRenderApp::OnLoadStart(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, TransitionType transition_type)
{

}

void SimpleRenderApp::OnLoadEnd(CefRefPtr<CefBrowser> browser, CefRefPtr<CefFrame> frame, int httpStatusCode)
{

}

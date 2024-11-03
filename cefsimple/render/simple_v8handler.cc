#include "simple_v8handler.h"

bool SimpleV8Handler::Execute(const CefString& name, CefRefPtr<CefV8Value> object, const CefV8ValueList& arguments, CefRefPtr<CefV8Value>& retval, CefString& exception)
{
	if (name == "sum")
	{
		int ret = 0;
		for (auto value : arguments)
		{
			if (!value->IsInt())
			{
				exception = "args type error: must int";
				break;
			}
			ret += value->GetIntValue();
		}
		retval = CefV8Value::CreateInt(ret);
		return true;
	}

	return false;
}


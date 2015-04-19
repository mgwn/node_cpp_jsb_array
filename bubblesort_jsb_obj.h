/********************************/
/*   NODE JSB接口类             */
/*******************************/
#ifndef _WAN_BUBBLESORT_JSB_OBJ_H
#define _WAN_BUBBLESORT_JSB_OBJ_H

#include <node.h>
#include <node_object_wrap.h>

class BubbleSortJSBObj : public node::ObjectWrap
{
public:
	static void Init(v8::Handle<v8::Object> exports);
private:
	explicit BubbleSortJSBObj();
	~BubbleSortJSBObj();
	
	static void Sort(const v8::FunctionCallbackInfo<v8::Value>& args);
};

#endif //_WAN_BUBBLESORT_JSB_OBJ_H
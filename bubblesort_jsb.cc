#include <node.h>
#include "bubblesort_jsb_obj.h"

using namespace v8;

void InitAll(Handle<Object> exports) {
	BubbleSortJSBObj::Init(exports);
}

NODE_MODULE(bubblesort,InitAll)
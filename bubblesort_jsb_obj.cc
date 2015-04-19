#include "bubblesort_jsb_obj.h"
#include "bubblesort.h"

using namespace v8;


void BubbleSortJSBObj::Init(Handle<Object> exports)
{
    //模块方法构造方式，对象方法参考node.js官方文档
    NODE_SET_METHOD(exports,"sort",Sort);
}

void BubbleSortJSBObj::Sort(const FunctionCallbackInfo<Value>& args)
{
    Isolate* isolate = Isolate::GetCurrent();
    HandleScope scope(isolate);
    
    //参数就检查
    if(args.Length()<1)
    {
        isolate->ThrowException(Exception::TypeError(
                                                     String::NewFromUtf8(isolate,"Wrong number of arguments")));
        return;
    }
    
    if(!args[0]->IsArray())
    {
        isolate->ThrowException(Exception::TypeError(
                                                     String::NewFromUtf8(isolate,"Wrong arguments")));
        return;
    }
    
    //将js数组转换为普通数组
    Local<Array> dataArray = Local<Array>::Cast(args[0]);
    double* tmpArray = new double[dataArray->Length()];
    for (uint32_t i=0; i<dataArray->Length(); i++) {
        tmpArray[i] = dataArray->Get(i)->NumberValue();
    }
    //调用c++方法处理数据
    wan::BubbleSort::Sort(tmpArray,dataArray->Length());
    
    
    //构造返回数组
    Local<Array> returnArray = Array::New(isolate,dataArray->Length());
    for (uint32_t i=0; i<dataArray->Length(); i++) {
        returnArray->Set(i,Number::New(isolate,tmpArray[i]));
    }
    
    
    //回调函数
    if (args.Length() >=2)
    {
        Local<Function> cb = Local<Function>::Cast(args[1]);
        const unsigned argc = 1;
        Local<Value> argv[argc] = {returnArray};
        cb -> Call(isolate->GetCurrentContext()->Global(),argc,argv);
    }
    
    //返回值
    args.GetReturnValue().Set(returnArray);
}

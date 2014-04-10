#include<iostream>
#include"jnihybridstack_JNIStackImplementation.h"
#include"HybridStack.h"

using namespace std;

JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_Stack_init(JNIEnv * env, jobject obj){
	stack* myStack = new stack();
	return (jbyteArray)env->NewDirectByteBuffer(myStack, 0);
}

JNIEXPORT void JNICALL Java_jnihybridstack_Stack_push(JNIEnv * env, jobject obj, jbyteArray data, jbyteArray handle){
	try{
		if(data == NULL){
			throw NewJavaException(env, "java/lang/NullPointerException", "data");
		}
		stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
		jbyte* buffer = env->GetByteArrayElements(data, NULL);
		myStack->push(buffer, (int)env->GetArrayLength(data));
	} catch(...){
		replace_cpp_exception_by_java_exception(env);
	}
}

JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_Stack_peek(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	try{
		jbyteArray arr = env->NewByteArray(myStack->peekSize());
		env->SetByteArrayRegion(arr, 0, myStack->peekSize(), myStack->peek());
		return arr;
	} catch(StackException){
		replace_cpp_exception_by_java_exception(env);
	}
}

JNIEXPORT jboolean JNICALL Java_jnihybridstack_Stack_isEmpty(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	return myStack->isEmpty();
}

JNIEXPORT void JNICALL Java_jnihybridstack_Stack_pop(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	try {
		if(myStack->isEmpty()){
			throw StackException();
		}
		myStack->pop();
	} catch(...){
		replace_cpp_exception_by_java_exception(env);
	}
}

JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_Stack_cloneBuffer(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = new stack((stack*)(env)->GetDirectBufferAddress(handle));
	return (jbyteArray)env->NewDirectByteBuffer(myStack, 0);
}

void replace_cpp_exception_by_java_exception(JNIEnv * env){
	try{
		throw;
	} catch(const ThrownJavaException&){
	} catch(const std::bad_alloc& handle){
		NewJavaException(env, "java/lang/OutOfMemoryError", handle.what());
	} catch(const std::ios_base::failure& handle){
		NewJavaException(env, "java/io/IOException", handle.what());
	} catch(const StackException& handle){
		NewJavaException(env, "jnihybridstack/StackMemoryOutOfBoundsException", handle.msg());
	} catch(const std::exception& e){
		NewJavaException(env, "Java/lang/Error", e.what());
	} catch(...){
		NewJavaException(env, "Java/lang/Error", "Unknown Exception");
	}
}
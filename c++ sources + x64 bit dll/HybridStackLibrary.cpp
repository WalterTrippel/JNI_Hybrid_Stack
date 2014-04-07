#include<iostream>
#include"jnihybridstack_JNIStackImplementation.h"
#include"HybridStack.h"

using namespace std;

JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_JNIStackImplementation_init(JNIEnv * env, jobject obj){
	stack* myStack = new stack();
	return (jbyteArray)env->NewDirectByteBuffer(myStack, 0);
}

JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_push(JNIEnv * env, jobject obj, jint input, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	myStack->push(input);
}

JNIEXPORT jint JNICALL Java_jnihybridstack_JNIStackImplementation_peek(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	return myStack->peek();
}

JNIEXPORT jboolean JNICALL Java_jnihybridstack_JNIStackImplementation_isEmpty(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	return myStack->isEmpty();
}

JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_pop(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = (stack*) env->GetDirectBufferAddress(handle);
	try {
		myStack->pop();
	} catch(StackException e){
		e.what();
		//exit(1);
	}
}

JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_JNIStackImplementation_cloneBuffer(JNIEnv * env, jobject obj, jbyteArray handle){
	stack* myStack = new stack((stack*)(env)->GetDirectBufferAddress(handle));
	return (jbyteArray)env->NewDirectByteBuffer(myStack, 0);
}
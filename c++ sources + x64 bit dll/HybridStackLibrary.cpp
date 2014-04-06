#include<iostream>
#include"jnihybridstack_JNIStackImplementation.h"
#include"HybridStack.h"

using namespace std;

stack a;

JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_push(JNIEnv * env, jobject, jint input){
	a.push(input);
}

JNIEXPORT jint JNICALL Java_jnihybridstack_JNIStackImplementation_peek(JNIEnv *env, jobject){
	return a.peek();
}

JNIEXPORT jboolean JNICALL Java_jnihybridstack_JNIStackImplementation_isEmpty(JNIEnv *, jobject){
	return a.isEmpty();
}

JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_show(JNIEnv *, jobject){
	cout<<a<<endl;
}

JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_remove(JNIEnv *, jobject){
	a.remove();
}
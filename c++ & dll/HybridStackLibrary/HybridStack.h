#ifndef STACK_H
#define	STACK_H
#include <iostream>
#include<exception>
#include <jni.h>

static const int ARRAY_SIZE = 5;

class StackException: public std::exception{
	public:
		const char* msg() const throw(){
			return "Cannot read from empty stack";
		}
};

class ThrownJavaException: std::runtime_error{
	public:
		ThrownJavaException(): std::runtime_error(""){};
		ThrownJavaException(const std::string& msg): std::runtime_error(msg){};
};

class NewJavaException: public ThrownJavaException{
	public:
		NewJavaException(JNIEnv * env, const char* type = "", const char* message = ""): ThrownJavaException(message){
			jclass newExitClass = env->FindClass(type);
			if(newExitClass != NULL){
				env->ThrowNew(newExitClass, message);
			}
		}
};

class stack {
	struct node {
		public:
			node &operator = (const node& obj);
			node(node* n);
			node();
			~node();
			int size_counter;
			node* prev;
			jbyte** data;
	};
    public:
        stack();
        stack(const stack &obj);
		stack(const stack* obj);
		stack(stack&& obj);
        ~stack();
        void push(jbyte*, int);
        void pop();
		jbyte* peek();
		int peekSize();
        bool isEmpty() const;
		void clear();
		int* SIZES;
		int byte_counter;
    private:
        node* top;
};

#endif STACK_H 
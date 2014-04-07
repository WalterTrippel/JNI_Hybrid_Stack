#ifndef STACK_H
#define	STACK_H
#include <iostream>
#include<exception>

static const int ARRAY_SIZE = 5;

class StackException: public std::exception{
	const char* msg() const throw(){
		return "Cannot read from empty stack";
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
			int* data;
	};
    public:
        stack();
        stack(const stack &obj);
		stack(const stack* obj);
		stack(stack&& obj);
        ~stack();
        void push(int);
        void pop();
		int peek();
        bool isEmpty() const;
		void clear();
    private:
        node* top;
};

#endif STACK_H 
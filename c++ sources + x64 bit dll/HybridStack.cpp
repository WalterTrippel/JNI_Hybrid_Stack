#include<iostream>
#include"HybridStack.h"

using namespace std;

stack::stack() {
    top = 0;
}

stack::stack(stack&& obj){
	*this = std::move(obj);
}

stack::stack(const stack &obj){
	if(obj.top == nullptr){
		top = nullptr;
	} else {
		top = new node;
		top->data = obj.top->data;
		top->size_counter = obj.top->size_counter;
		node* newPrev = top;
		for(node* current = obj.top->prev; current != nullptr; current = current->prev){
			newPrev->prev = new node;
			newPrev = newPrev->prev;
			newPrev->data = current->data;
			newPrev->size_counter = current->size_counter;
		}
		newPrev->prev = nullptr;
	}
}

stack::stack(const stack* obj){
	if(obj->top == nullptr){
		top = nullptr;
	} else {
		top = new node;
		top->data = obj->top->data;
		top->size_counter = obj->top->size_counter;
		node* newPrev = top;
		for(node* current = obj->top->prev; current != nullptr; current = current->prev){
			newPrev->prev = new node;
			newPrev = newPrev->prev;
			newPrev->data = current->data;
			newPrev->size_counter = current->size_counter;
		}
		newPrev->prev = nullptr;
	}
}

stack::~stack() {
	this->clear();
}

bool stack::isEmpty() const {
	return top == nullptr || top->size_counter == 0 && top->prev == nullptr;
}

void stack::push(int x) {
    if(top == nullptr){
        node* n = new node(top);
        n->data[0] = x;
        n->size_counter++;
        top = n;
    } else if(top->size_counter == ARRAY_SIZE){
        node* n = new node(top);
        n->data[0] = x;
        n->size_counter++;
        top = n;
    } else {
        top->data[top->size_counter] = x;
        top->size_counter++;
    }
}

void stack::pop() {
    if (!isEmpty()) {
		if(top->size_counter == 0){
			node r = *top;
			top = top->prev;
		} else {
			top->size_counter--;
		}
    }
    else {
		throw StackException();
    }
}

int stack::peek() {
	if(!isEmpty()){
		if(top->size_counter != 0){
			return top->data[top->size_counter - 1];
		} else {
			top = top->prev;
			return top->data[top->size_counter - 1];
		}
	} else {
		throw StackException();
	}
}

void stack::clear(){
	while(top){
		node *p = top;
		top = top->prev;
		delete p;
		p = 0;
	}
}

stack::node&stack::node::operator=(const node& obj){
	node r(obj.prev);
	return r;
}

stack::node::node(node* n): prev(n) {
	size_counter = 0;
	data = new int[ARRAY_SIZE];
}

stack::node::node(){
	size_counter = 0;
	prev = nullptr;
};

stack::node::~node(){
	prev = nullptr;
	delete prev;
	delete []data;
}
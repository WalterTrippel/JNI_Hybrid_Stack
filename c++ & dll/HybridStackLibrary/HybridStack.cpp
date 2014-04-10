#include<iostream>
#include"HybridStack.h"

using namespace std;

stack::stack() {
    top = 0;
	byte_counter = 0;
	SIZES = new int[100];
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
		SIZES = obj.SIZES;
		byte_counter = obj.byte_counter;
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
		SIZES = obj->SIZES;
		byte_counter = obj->byte_counter;
		//cout << SIZES << "\n";
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
	delete[] SIZES;
}

bool stack::isEmpty() const {
	return top == nullptr || top->size_counter == 0 && top->prev == nullptr;
}

void stack::push(jbyte *arr, int size) {
    if(top == nullptr){
        node* n = new node(top);
        n->data[0] = arr;
		SIZES[byte_counter] = size;
		n->size_counter++;
		byte_counter++;
        top = n;
    } else if(top->size_counter == ARRAY_SIZE){
        node* n = new node(top);
        n->data[0] = arr;
		SIZES[byte_counter] = size;
        n->size_counter++;
		byte_counter++;
        top = n;
    } else {
        top->data[top->size_counter] = arr;
		SIZES[byte_counter] = size;
        top->size_counter++;
		byte_counter++;
    }
}

void stack::pop() {
    if (!isEmpty()) {
		if(top->size_counter == 0){
			node r = *top;
			top = top->prev;
		} else {
			top->size_counter--;
			byte_counter--;
		}
    }
    else {
		throw StackException();
    }
}

jbyte* stack::peek() {
	if(!this->isEmpty()){
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

int stack::peekSize() {
	if(!this->isEmpty()){
		if(top->size_counter != 0){
			return SIZES[byte_counter - 1];
		} else {
			top = top->prev;
			return SIZES[byte_counter - 1];
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
	data = new jbyte*[ARRAY_SIZE];
}

stack::node::node(){
	size_counter = 0;
	prev = nullptr;
};

stack::node::~node(){
	prev = nullptr;
	delete prev;
	for(int i = 0; i < size_counter; ++i){
		delete data[i];
	}
	delete []data;
}


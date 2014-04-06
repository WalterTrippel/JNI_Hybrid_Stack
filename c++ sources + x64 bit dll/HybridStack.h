#define ARRAY_SIZE 5
#include <iostream>

using namespace std;

class node {
    public:
        node operator = (const node&);
        node(node* n): prev(n) {
            size_counter = 0;
            data = new int[ARRAY_SIZE];
        }
        node(){}
        int size_counter;
        node* prev;
        int* data;
};

node node::operator = (const node &n) {
    node r(n.prev);
    return r;
}

class stack {
    public:
        stack();
        stack(const stack &obj);
        virtual ~stack();
        void push(int);
        node pop();
		int peek();
        bool isEmpty();
		void remove();
        friend ostream& operator << (ostream &stream, stack &obj){
            while(!obj.isEmpty()) {
                node buffer = obj.pop();
				for(int i = buffer.size_counter-1; i >=0; --i){
					stream << buffer.data[i] << endl;
                }
            }
			return stream;
        };
    private:
        node* top;
};

stack::stack() {
    top = 0;
}

stack::stack(const stack &obj){
	if(obj.top == NULL){
		top = NULL;
	} else {
		top = new node;
		top->data = obj.top->data;
		top->size_counter = obj.top->size_counter;
		node* newPrev = top;
		for(node* current = obj.top->prev; current != NULL; current = current->prev){
			newPrev->prev = new node;
			newPrev = newPrev->prev;
			newPrev->data = current->data;
			newPrev->size_counter = current->size_counter;
		}
		newPrev->prev = NULL;
	}
}

stack::~stack() {
    while(!isEmpty()){
        node *local = top;
        top = top->prev;
        delete local;
    }
}

bool stack::isEmpty() {
	return top->size_counter == 0 && top->prev == NULL;
}

void stack::push(int x) {
    if(top == NULL){
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

node stack::pop() {
    if (!isEmpty()) {
        node r = *top;
        top = top->prev;
        return r;
    }
    else {
        cout << "ERROR : stack is empty!" << endl;
        return 0;
    }
}

int stack::peek(){
	if(!isEmpty()){
		if(top->size_counter != 0){
			return top->data[top->size_counter - 1];
		} else {
			top = top->prev;
			return top->data[top->size_counter - 1];
		}
	} else {
		cout << "ERROR : stack is empty!" << endl;
        return 0;
	}
}

void stack::remove(){
    if(!isEmpty()){
        top->size_counter--;
    } else {
            cout<< "ERROR: stack is empty!" << endl;
    }
}
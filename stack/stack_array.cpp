#include <iostream>
#include <string.h>
#include <stdlib.h>

class StackArray {
  public:
    void *data;
};

class Stack {
  public:
    int capacity;
    int top;
    StackArray *array;

    Stack() {
      capacity = 10;
      top = 0;
      array = new StackArray[capacity];
    }

    Stack(int capacity) {
      top = 0;
      this->capacity = capacity;
      array = new StackArray[capacity];
    }

    ~Stack() {
      std::cout << "destroctor called" << std::endl;
      for (int i=0; i<top; i++) {
        if (array[i].data)
          delete [] (char*)array[i].data;
      }
      if (array)
        delete []array;
    }

    void push(void *data);
    void pop();
    bool isEmpty();
    int size();
};

void Stack::push(void *data) {
  if (capacity == top) {
    std::cout << "stack has reached the maximum capacity." << std::endl;
    return;
  }

  char *newData = new char[strlen((char*)data) + 1];

  memcpy(newData, (char*)data, strlen((char*)data));
  newData[strlen((char*)data)] = '\0';

  array[top].data = newData;
  std::cout << "data: " << (char*)array[top].data << ", top: " << top << std::endl;
  top++;
}

void Stack::pop() {
  if (top -1 < 0) { 
    std::cout << "Stack is empty" << std::endl;	
    return;
  }
  if (array[top-1].data) {
    std::cout << "data: " << (char*)array[top-1].data << ", top: " << top << std::endl;
    delete [] (char*)array[top-1].data;
    array[top-1].data = NULL;
  }

  top--;
}

bool Stack::isEmpty() {
  return (top == 0);
}

int Stack::size() {
  return top;
};

int main() {

  Stack *stack = new Stack(3);

  stack->push((void *)"1");
  stack->push((void *)"2");
  stack->push((void *)"3");
  stack->push((void *)"4");

  std::cout << "isEmpty(): " << stack->isEmpty() << std::endl;
  std::cout << "size(): " << stack->size() << std::endl;

  stack->pop();
  stack->pop();
  stack->pop();
  stack->pop();

  std::cout << "isEmpty(): " << stack->isEmpty() << std::endl;
  std::cout << "size(): " << stack->size() << std::endl;

  delete stack;

  return 0;
}

#include <iostream>
#include "list.h"

class Stack {
  public:
    List *list;

    Stack() { 
      list = new List();
    }   

    void push(void *data);
    void pop();
    bool isEmpty();
    void *front();
    int size();
};

void Stack::push(void *data) {
  list->insertAfter(list->createNode(data));
}

void Stack::pop() {
  list->deleteLast();
}

bool Stack::isEmpty() {
  return (list->getSize() == 0); 
}

void* Stack::front() {
  void *data_ = NULL;

  if (list->getTail())
    data_ = list->getTail()->data;

  return data_;
}

int Stack::size() {
  return list->getSize();
}

int main() {

  Stack *stack = new Stack();

  stack->push((char*)"1");

  stack->pop();
  stack->push((char*)"2");
  stack->push((char*)"3");

  std::cout << "isEmpty(): " << stack->isEmpty() << std::endl;

  std::cout << "size(): " << stack->size() << std::endl;
  std::cout << "front : " << (char*) stack->front() << std::endl;


  return 0;
}

#ifndef __LIST__
#include <iostream>
#include <stdlib.h>
#include <string.h>

class Node {
  public:
    void *data;
    Node *next;

    Node(): data(NULL), next(NULL) { }
    Node(void *data) {
      if (data) {
        char *tmp = new char[strlen((char*)data) + 1];
        memcpy(tmp, data, strlen((char*)data));
        tmp[strlen((char*)data)] = '\0';
        this->data = tmp;
      } else {
        this->data = NULL;
      }
      next = NULL;
    }
    ~Node() {
      if (data) {
        delete [] (char*)data;
      }
    }
};

class List {
  private:
    int size;
    Node *head;
    Node  *tail;

  public:
    List(): size(0), head(NULL), tail(NULL) { }

    Node* createNode(void *data);
    bool insertAfter(Node *node);
    bool deleteLast();
    Node* getHead();
    Node* getTail();
    int getSize();
};

#endif


#include "list.h"

Node* List::createNode(void *data) {
  Node *newNode = new Node(data);
  return newNode;
}

bool List::insertAfter(Node *node) {
  if (!node) return false;

  if (head == NULL) {
    head = node;
    tail = node;
    size++;
    return true;
  }   
  Node *current = head;

  while (current->next != NULL) {
    current = current->next;
  }   

  current->next = node;
  tail = node;
  size++;

  return true;
}

bool List::deleteLast() {
  if (head == NULL) return false;

  if (head->next == NULL) {
    delete head;
    head = NULL;
    tail = NULL;
    size--;
    return true;
  }   

  Node *current = head;
  Node *priv = head;

  while (current->next != NULL) {
    priv = current;
    current = current->next;
  }

  if (priv) {
    priv->next = NULL;
    tail = priv;
  }
  if (current)
    delete current;

  size--;

  return true;
}

Node* List::getHead() {
  return head;
}

Node* List::getTail() {
  return tail;
}

int List::getSize() {
  return size;
}

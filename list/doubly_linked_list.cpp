#include <iostream>

class Node {
  private:
    int data;
    Node *next;
    Node *priv;

  public:
    Node(): data(0), next(NULL), priv(NULL) { }
    Node(int data): data(data), next(NULL), priv(NULL) { }

    int getData() const;
    void setData(int data);

    Node *getNext() const;
    void setNext(Node *next);

    Node *getPriv() const;
    void setPriv(Node *priv);
};

int Node::getData() const {
  return data;
}

void Node::setData(int data) {
  this->data = data;
}

Node* Node::getNext() const {
  return next;
}

void Node::setNext(Node *next) {
  this->next = next;
}

Node* Node::getPriv() const {
  return priv;
}

void Node::setPriv(Node *priv) {
  this->priv = priv;
}


class List {
  private:
    Node *head;
    int total_cnt;
  public:

    List(): head(NULL), total_cnt(0) { }

    Node *createNewNode(int data);
    void insertNode(Node *node);
    void deleteLastNode();
    void deleteNode(int idx);
    void printAllNodes();
    void destroyNode(Node *node);
};

Node* List::createNewNode(int data) {
  Node *newNode = new Node(data);
  return newNode;
}

void List::insertNode(Node *node) {
  if (head == NULL) {
    head = node;
    total_cnt++;
    return;
  }

  Node *current = head;
  while (current->getNext() != NULL) {
    current = current->getNext();
  }
  current->setNext(node);
  node->setPriv(current);
  total_cnt++;

  return;
}

void List::printAllNodes() {
  Node *current = head;

  if (head == NULL) {
    std::cout << "List is empty, total_cnt : " << total_cnt << std::endl;
    return;
  }

  while (current != NULL) {
    std::cout << current->getData() << ", ";
    current = current->getNext();
  }
  std::cout << " total_cnt : " << total_cnt << std::endl;
}

void List::deleteLastNode() {
  Node *current = head;

  if (head == NULL) {
    return;
  }

  if (head->getNext() == NULL) {
    head = NULL;
    total_cnt--;
    destroyNode(head);
    return;
  }

  while (current->getNext() != NULL) {
    current = current->getNext();
  }
  current->getPriv()->setNext(NULL);
  total_cnt--;

  destroyNode(current);
}

void List::deleteNode(int idx) {
  if (head == NULL) return;

  Node *current = head;
  while (current != NULL && (--idx) >= 0) {
    current = current->getNext();
  }

  if (idx > 0) { std::cout << "index node does not exist" << std::endl; return; }

  if (head == current) {
    head = current->getNext();
    if (head)
      head->setPriv(NULL);
    total_cnt--;
    destroyNode(current);
    return;
  }

  current->getPriv()->setNext(current->getNext());

  Node *nextNode = current->getNext();
  if (nextNode != NULL) {
    nextNode->setPriv(current->getPriv());
  }

  total_cnt--;

  destroyNode(current);

  return;
}

void List::destroyNode(Node *node) {
  if (node) {
    delete node;
  }
}

int main() {
  List *list = new List();
  Node *newNode = list->createNewNode(1);
  list->insertNode(newNode);

  newNode = list->createNewNode(2);
  list->insertNode(newNode);

  newNode = list->createNewNode(3);
  list->insertNode(newNode);

  list->printAllNodes();

  list->deleteLastNode();
  list->printAllNodes();

  list->deleteLastNode();
  list->printAllNodes();

  list->deleteLastNode();
  list->printAllNodes();

  std::cout << "===========" << std::endl;

  newNode = list->createNewNode(1);
  list->insertNode(newNode);
  newNode = list->createNewNode(2);
  list->insertNode(newNode);
  newNode = list->createNewNode(3);
  list->insertNode(newNode);

  list->printAllNodes();

  list->deleteNode(0);
  list->printAllNodes();

  list->deleteNode(1);
  list->printAllNodes();

  list->deleteNode(2);
  list->printAllNodes();

  list->deleteNode(0);
  list->printAllNodes();

  return 0;
}

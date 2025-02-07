#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int val;
  Node *next;
  Node(int val)
  {
    this->val = val;
    this->next = NULL;
  }
};
class MyLinkedList
{
public:
  Node *head;
  Node *tail;
  int size;
  MyLinkedList()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  int get(int index)
  {
    if (index >= size)
      return -1;
    Node *tmp = head;

    for (int i = 0; i < index; i++)
    {
      tmp = tmp->next;
    }
    return tmp->val;
  }

  void addAtHead(int val)
  {
    size++;
    Node *newNode = new Node(val);
    if (!head)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    newNode->next = head;
    head = newNode;
  }

  void addAtTail(int val)
  {
    size++;
    Node *newNode = new Node(val);
    if (!head)
    {
      head = newNode;
      tail = newNode;
      return;
    }
    tail->next = newNode;
    tail = newNode;
  }

  void addAtIndex(int index, int val)
  {
    if (index > size)
      return;
    if (index == 0)
    {
      addAtHead(val);
    }
    else if (index == size)
    {
      addAtTail(val);
    }
    else
    {
      size++;
      Node *tmp = head;
      Node *newNode = new Node(val);
      for (int i = 1; i < index; i++)
      {
        tmp = tmp->next;
      }
      newNode->next = tmp->next;
      tmp->next = newNode;
    }
  }

  void deleteAtIndex(int index)
  {
    if (!head)
      return;
    if (index >= size)
      return;
    if (index == 0)
    {
      size--;
      Node *dlt = head;
      head = head->next;
      delete dlt;
    }
    else if (index == size - 1)
    {
      size--;
      Node *tmp = head;
      while (tmp->next->next)
      {
        tmp = tmp->next;
      }
      Node *dlt = tmp->next;
      tmp->next = NULL;
      delete dlt;
      tail = tmp;
    }
    else
    {
      size--;
      Node *tmp = head;
      for (int i = 1; i < index; i++)
      {
        tmp = tmp->next;
      }
      Node *dlt = tmp->next;
      tmp->next = tmp->next->next;
      delete dlt;
    }
  }
};

int main()
{
  MyLinkedList *obj = new MyLinkedList();
  obj->addAtHead(1);
  obj->addAtTail(3);
  obj->addAtIndex(1, 2);
  cout << obj->get(1) << endl;
  obj->deleteAtIndex(1);
  cout << obj->get(1) << endl;

  return 0;
}
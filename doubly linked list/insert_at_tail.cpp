#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *next;
  Node *prev;

  Node(int val)
  {
    this->val = val;
    this->next = NULL;
    this->prev = NULL;
  }
};

void print_forward(Node *head)
{
  Node *tmp = head;
  while (tmp != NULL)
  {
    cout << tmp->val << endl;
    tmp = tmp->next;
  }
}

void print_backward(Node *tail)
{
  Node *tmp = tail;
  while (tmp != NULL)
  {
    cout << tmp->val << endl;
    tmp = tmp->prev;
  }
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{

  Node *new_node = new Node(val);
  if (head == NULL)
  {
    head = new_node;
    tail = new_node;
    return;
  }
  tail->next = new_node;
  new_node->prev = tail;
  tail = new_node;
}

int main()
{
  Node *head = new Node(10);
  Node *a = new Node(20);
  Node *tail = new Node(30);

  head->next = a;
  a->prev = head;

  a->next = tail;
  tail->prev = a;

  insert_at_tail(head, tail, 100);
  insert_at_tail(head, tail, 200);
  insert_at_tail(head, tail, 300);
  print_forward(head);
  return 0;
}
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

void reverse_doubly(Node *head, Node *tail)
{
  for (Node *i = head, *j = tail; i != j && i->prev != j; i = i->next, j = j->prev)
  {
    swap(i->val, j->val);
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
  Node *head = NULL;
  Node *tail = NULL;

  int val;
  while (true)
  {
    cin >> val;
    if (val == -1)
    {
      break;
    }
    insert_at_tail(head, tail, val);
  }

  reverse_doubly(head, tail);
  print_forward(head);
  return 0;
}
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

void insert_at_tail(Node *&head, Node *&tail, int val)
{
  Node *newNode = new Node(val);

  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
    return;
  }

  tail->next = newNode;
  tail = newNode;
}

void print_link_list(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->val << endl;
    temp = temp->next;
  }
}

void sort_link_list(Node *&head)
{

  for (Node *i = head; i->next != NULL; i = i->next)
  {
    for (Node *j = i->next; j->next != NULL; j = j->next)
    {
      if (i->val > j->val)
      {
        swap(i->val, j->val);
      }
    }
  }
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
  sort_link_list(head);
  print_link_list(head);

  return 0;
}










void delete_at_pos(Node *&head, Node *&tail, int idx)
{
  if (head == NULL) return;



  Node *cur = head;
  for (int i = 0; i < idx - 1; i++)
  {
    if (cur->next == NULL) return; // index out of bounds
    cur = cur->next;
  }

  Node *del = cur->next;
  if (del == NULL) return;

  cur->next = del->next;
  if (cur->next == NULL) tail = cur; // update tail
  delete del;
}

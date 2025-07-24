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

int main()
{
  Node *head = new Node(10);
  Node *a = new Node(20);
  Node *b = new Node(30);
  Node *c = new Node(40);
  Node *d = new Node(50);
  head->next = a;
  a->next = b;
  b->next = c;
  c->next = d;
  d->next = b;

  Node *fast = head;
  Node *slow = head;
  bool flag = false;
  while (fast != NULL && slow->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast)
    {
      flag = true;
      break;
    }
  }
  flag ? cout << "Cycle Detected" << endl : cout << "No Cycle";

  return 0;
}

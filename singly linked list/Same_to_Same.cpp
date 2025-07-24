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

int main()
{
  Node *head1 = NULL, *tail1 = NULL;
  Node *head2 = NULL, *tail2 = NULL;

  int val;

  while (true)
  {
    cin >> val;
    if (val == -1)
      break;
    insert_at_tail(head1, tail1, val);
  }

  while (true)
  {
    cin >> val;
    if (val == -1)
      break;
    insert_at_tail(head2, tail2, val);
  }

  Node *temp1 = head1;
  Node *temp2 = head2;

  bool isSame = true;

  while (temp1 != NULL && temp2 != NULL)
  {
    if (temp1->val != temp2->val)
    {
      isSame = false;
      break;
    }
    temp1 = temp1->next;
    temp2 = temp2->next;
  }

  if (temp1 != NULL || temp2 != NULL)
  {
    isSame = false;
  }

  if (isSame)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }

  return 0;
}

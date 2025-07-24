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

void insert_at_head(Node *&head, Node *&tail, int val)
{
  Node *newNode = new Node(val);
  if (head == NULL)
  {
    head = newNode;
    tail = newNode;
    return;
  }
  newNode->next = head;
  head = newNode;
}

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

void delete_at_head(Node *&head, Node *&tail)
{
  if (head == NULL)
  {
    return;
  }
  Node *temp = head;
  head = head->next;
  delete temp;
  if (head == NULL)
    tail = NULL;
}

void delete_at_pos(Node *&head, Node *&tail, int idx)
{
  if (head == NULL)
    return;

  Node *temp = head;
  for (int i = 1; i < idx; i++)
  {
    if (temp == NULL || temp->next == NULL)
      return;
    temp = temp->next;
  }

  if (temp->next == NULL)
    return;

  Node *deleteNode = temp->next;
  temp->next = temp->next->next;

  if (temp->next == NULL)
    tail = temp;
  delete deleteNode;
}

void print_link_list(Node *head)
{
  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;
}

int main()
{
  Node *head = NULL;
  Node *tail = NULL;
  int q;
  cin >> q;
  while (q--)
  {
    int x;
    long long v;
    cin >> x >> v;

    if (x == 0)
    {
      insert_at_head(head, tail, v);
    }
    else if (x == 1)
    {
      insert_at_tail(head, tail, v);
    }
    else if (x == 2)
    {
      if (v == 0)
      {
        delete_at_head(head, tail);
      }
      else
      {
        delete_at_pos(head, tail, v);
      }
    }

    print_link_list(head);
  }

  return 0;
}

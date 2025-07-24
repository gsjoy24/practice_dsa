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

void delete_at_pos(Node *&head, int idx)
{
  if (idx == 0)
  {
    Node *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  Node *temp = head;
  for (int i = 1; i < idx; i++)
  {
    temp = temp->next;
  }
  if (temp->next == NULL)
    return;

  Node *deletedNode = temp->next;
  temp->next = temp->next->next;
  delete deletedNode;
}

int main()
{
  Node *head = NULL, *tail = NULL;
  int val;
  while (true)
  {
    cin >> val;
    if (val == -1)
      break;
    insert_at_tail(head, tail, val);
  }

  for (Node *i = head; i != NULL; i = i->next)
  {
    int idx_i = 0;
    Node *tmp_i = head;
    while (tmp_i != i)
    {
      tmp_i = tmp_i->next;
      idx_i++;
    }

    Node *j = i->next;
    int idx_j = idx_i + 1;

    while (j != NULL)
    {
      if (j->val == i->val)
      {
        delete_at_pos(head, idx_j);
        j = i->next;
        idx_j = idx_i + 1;
      }
      else
      {
        j = j->next;
        idx_j++;
      }
    }
  }

  print_link_list(head);
  return 0;
}

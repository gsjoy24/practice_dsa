#include <iostream>
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

int getLength(Node *head)
{
  int count = 0;
  while (head)
  {
    count++;
    head = head->next;
  }
  return count;
}

void printLeftToRight(Node *head)
{
  cout << "L -> ";
  while (head)
  {
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

void printRightToLeft(Node *tail)
{
  cout << "R -> ";
  while (tail)
  {
    cout << tail->val << " ";
    tail = tail->prev;
  }
  cout << endl;
}

void insert_at_position(Node *&head, Node *&tail, int pos, int val)
{
  int len = getLength(head);

  if (pos < 0 || pos > len)
  {
    cout << "Invalid" << endl;
    return;
  }

  Node *new_node = new Node(val);

  if (!head)
  {
    if (pos == 0)
    {
      head = new_node;
      tail = new_node;
      printLeftToRight(head);
      printRightToLeft(tail);
    }
    else
    {
      cout << "Invalid" << endl;
      delete new_node;
    }
    return;
  }

  if (pos == 0)
  {
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
  }
  else if (pos == len)
  {
    tail->next = new_node;
    new_node->prev = tail;
    tail = new_node;
  }
  else
  {
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
      temp = temp->next;
    }

    Node *nextNode = temp->next;
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = nextNode;
    nextNode->prev = new_node;
  }

  printLeftToRight(head);
  printRightToLeft(tail);
}

int main()
{
  Node *head = NULL;
  Node *tail = NULL;

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i)
  {
    int x, v;
    cin >> x >> v;
    insert_at_position(head, tail, x, v);
  }

  return 0;
}

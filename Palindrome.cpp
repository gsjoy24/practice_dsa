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

bool isPalindrome(Node *head, Node *tail)
{
  while (head != tail && head->next != tail)
  {
    if (head->val != tail->val)
      return false;
    head = head->next;
    tail = tail->prev;
  }

  if (head->val != tail->val)
    return false;

  return true;
}

int main()
{
  Node *head = NULL;
  Node *tail = NULL;

  int value;
  while (cin >> value && value != -1)
  {
    insert_at_tail(head, tail, value);
  }

  bool is_palindrome = isPalindrome(head, tail);

  cout << (is_palindrome ? "YES" : "NO") << endl;

  return 0;
}

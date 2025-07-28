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

class myStack
{
public:
  vector<int> v;

  void push(int val)
  {
    v.push_back(val);
  }

  void pop()
  {
    v.pop_back();
  }

  int top()
  {
    return v.back();
  }

  int size()
  {
    return v.size();
  }

  bool isEmpty()
  {
    return v.empty();
  }
};

class myQueue
{
public:
  Node *head = NULL;
  Node *tail = NULL;

  void push(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = newNode;
      tail = newNode;
    }

    tail->next = newNode;
    tail = newNode;
  }

  void pop()
  {
    if (head == NULL)
      return;

    Node *deletedNode = head;
    head = head->next;
    delete deletedNode;
    if (head == NULL)
    {
      tail = NULL;
    }
  }

  int front()
  {
    return head->val;
  }

  int back()
  {
    return tail->val;
  }
};

int main()
{
  int n, m;
  cin >> n >> m;

  if (n != m)
  {
    cout << "NO" << endl;
    return 0;
  }

  myStack st;
  myQueue q;
  bool flag = true;

  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;

    st.push(val);
  }

  for (int i = 0; i < m; i++)
  {
    int val;
    cin >> val;

    q.push(val);
  }

  while (n--)
  {
    if (st.top() != q.front())
    {
      flag = false;
      break;
    }
    st.pop();
    q.pop();
  }

  cout << (flag ? "YES" : "NO") << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
  int val;
  Node *left;
  Node *right;

  Node(int val)
  {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *input_tree()
{
  int val;
  cin >> val;

  Node *root;

  if (val == -1)
  {
    root = NULL;
    return root;
  }
  else
  {
    root = new Node(val);
  }

  queue<Node *> q;
  q.push(root);

  while (!q.empty())
  {
    // ber kore ana
    Node *p = q.front();
    q.pop();

    // work with that node.
    int l, r;
    cin >> l >> r;

    Node *myLeft, *myRight;

    if (l == -1)
      myLeft = NULL;
    else
      myLeft = new Node(l);

    if (r == -1)
      myRight = NULL;
    else
      myRight = new Node(r);

    p->left = myLeft;
    p->right = myRight;

    // push the childrens
    if (p->left)
      q.push(p->left);

    if (p->right)
      q.push(p->right);
  }
  return root;
}

int max_height(Node *root)
{
  if (!root)
    return 0;

  if (!root->left && !root->right)
    return 0;

  int l = max_height(root->left);
  int r = max_height(root->right);
  return max(l, r) + 1;
}

int main()
{

  Node *root = input_tree();

  int count = max_height(root);
  cout << count << endl;

  return 0;
}
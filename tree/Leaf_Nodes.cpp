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
    Node *p = q.front();
    q.pop();

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

    if (p->left)
      q.push(p->left);

    if (p->right)
      q.push(p->right);
  }
  return root;
}

vector<int> getLeafNodes(Node *root)
{
  vector<int> v;

  if (!root)
  {
    return v;
  }

  if (!root->left && !root->right)
  {
    v.push_back(root->val);
    return v;
  }

  vector<int> l = getLeafNodes(root->left);
  vector<int> r = getLeafNodes(root->right);

  v.insert(v.end(), l.begin(), l.end());
  v.insert(v.end(), r.begin(), r.end());

  return v;
}

int main()
{

  Node *root = input_tree();

  vector<int> res = getLeafNodes(root);

  sort(res.begin(), res.end(), greater<int>());

  for (int num : res)
  {
    cout << num << " ";
  }
  return 0;
}
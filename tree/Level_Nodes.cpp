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

int max_depth(Node *root)
{
  if (root == NULL)
    return 0;

  int l = max_depth(root->left);
  int r = max_depth(root->right);

  return max(l, r) + 1;
}

void get_nodes_at_level(Node *root, int targetLevel, int currentLevel)
{
  if (!root)
    return;
  if (currentLevel == targetLevel)
  {
    cout << root->val << " ";
    return;
  }
  get_nodes_at_level(root->left, targetLevel, currentLevel + 1);
  get_nodes_at_level(root->right, targetLevel, currentLevel + 1);
}

int main()
{

  Node *root = input_tree();

  int maxDepth = max_depth(root);

  int x;
  cin >> x;

  if (x > maxDepth - 1 || x < 0)
  {
    cout << "Invalid" << endl;
    return 0;
  }

  get_nodes_at_level(root, x, 0);
  return 0;
}

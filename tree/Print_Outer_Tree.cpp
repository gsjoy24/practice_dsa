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

  void get_left_path(Node *root)
  {
    if (!root)
      return;

    if (!root->left && !root->right)
    {
      cout << root->val << " ";
      return;
    }

    if (root->left)
      get_left_path(root->left);
    else if (root->right)
      get_left_path(root->right);

    cout << root->val << " ";
  }

  void get_right_path(Node *root)
  {
    if (!root)
      return;

    cout << root->val << " ";

    if (root->right)
      get_right_path(root->right);
    else if (root->left)
      get_right_path(root->left);
  }

  int main()
  {
    Node *root = input_tree();

    get_left_path(root->left);
    cout << root->val << " ";
    get_right_path(root->right);

    return 0;
  }

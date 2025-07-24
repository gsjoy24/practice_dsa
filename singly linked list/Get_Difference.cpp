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
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while (true)
    {
      cin >> val;
      if (val == -1)
      {
        break;
      }
      insert_at_tail(head, tail, val);
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;

    if (head->next == NULL)
    {
      cout << "0" << endl;
      return 0;
    }

    for (Node *i = head; i != NULL; i = i->next)
    {
      min_val = min(min_val, i->val);
      max_val = max(max_val, i->val);
    }
    cout << max_val - min_val << endl;

    return 0;
  }
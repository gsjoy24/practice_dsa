#include <bits/stdc++.h>
using namespace std;

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

int main()
{
  myStack nums;
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    nums.push(x);
  }

  cout << nums.top() << endl;

  return 0;
};
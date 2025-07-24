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

  nums.push(10);
  nums.push(20);
  nums.push(30);
  // nums.push(40);

  cout << nums.top() << endl;

  return 0;
};
#include <bits/stdc++.h>
using namespace std;

int main()
{
  stack<int> s;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    s.push(val);
  }

  while (!s.empty())
  {
    cout << s.top() << endl;
    s.pop();
  }

  return 0;
}
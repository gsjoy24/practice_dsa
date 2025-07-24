#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int> l1;
  int value;
  while (cin >> value && value != -1)
  {
    l1.push_back(value);
  }
  l1.sort();
  l1.unique();

  for (auto i : l1)
  {
    cout << i << " ";
  }

  return 0;
}
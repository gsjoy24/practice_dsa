#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int> l1 = {1, 2, 3, 4, 5, 6};
  list<int> l2 = {20, 30, 40};

  // l1.insert(next(l1.begin(), 2), l2.begin(), l2.end());

  // for (auto i = l1.begin(); i != l1.end(); i++)
  // {
  //   cout << *i << endl;
  // }
  auto it = find(l1.begin(), l1.end(), 6);
  if (it == l1.end())
  {
    cout << "No" << endl;
  }
  else
  {
    cout << "yes" << endl;
  }

  // for (auto i : l1)
  // {
  //   cout << i << endl;
  // }

  return 0;
}
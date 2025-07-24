#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;

  list<int> lst;

  for (int i = 0; i < q; ++i)
  {
    int x, v;
    cin >> x >> v;

    if (x == 0)
    {
      lst.push_front(v);
    }
    else if (x == 1)
    {
      lst.push_back(v);
    }
    else if (x == 2)
    {
      if (v >= 0 && v < lst.size())
      {
        auto it = lst.begin();
        advance(it, v);
        lst.erase(it);
      }
    }

    cout << "L -> ";
    for (int val : lst)
    {
      cout << val << " ";
    }
    cout << endl;

    cout << "R -> ";
    for (auto it = lst.rbegin(); it != lst.rend(); ++it)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}

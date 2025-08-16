#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  vector<int> v(n);

  for (int i = 0; i < n; i++)
    cin >> v[i];

  int val;
  cin >> val;

  v.push_back(val);

  int current_idx = v.size() - 1;

  while (current_idx != 0)
  {
    int parent_idx = (current_idx - 1) / 2;
    if (v[parent_idx] < v[current_idx])
      swap(v[parent_idx], v[current_idx]);
    else
      break;
    current_idx = parent_idx;
  }

  for (int x : v)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}

// 10
// 23 15 21 13 9 19 8 2 4 7
// 18
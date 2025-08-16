#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
  v.push_back(val);
  int cur_idx = v.size() - 1;

  while (cur_idx != 0)
  {
    int par_idx = (cur_idx - 1) / 2;
    if (v[par_idx] < v[cur_idx])
      swap(v[par_idx], v[cur_idx]);
    else
      break;
    cur_idx = par_idx;
  }
}

void print_heap(vector<int> v)
{
  for (int x : v)
    cout << x << " ";
  cout << endl;
}

void delete_heap(vector<int> &v)
{
  v[0] = v.back();
  v.pop_back();

}

int main()
{
  vector<int> v;

  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int val;
    cin >> val;
    insert_heap(v, val);
  }

  // print_heap(v);
  delete_heap(v);

  return 0;
}
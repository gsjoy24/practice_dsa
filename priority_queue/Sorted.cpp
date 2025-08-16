#include <bits/stdc++.h>
using namespace std;

int main()
{

  int t;
  cin >> t;

  while (t--)
  {
    set<int> st;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
      int val;
      cin >> val;
      st.insert(val);
    }
    for (auto it = st.begin(); it != st.end(); it++)
    {
      cout << *it << " ";
    }
    cout << endl;
  }

  return 0;
}
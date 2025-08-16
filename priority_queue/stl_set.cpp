#include <bits/stdc++.h>
using namespace std;

int main()
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
    cout << *it << endl;
  }
  return 0;
}
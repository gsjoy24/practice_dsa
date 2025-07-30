#include <bits/stdc++.h>
using namespace std;

bool isStringEmpty(string &s)
{
  stack<char> st;

  for (char ch : s)
  {
    if (ch == '1')
    {
      if (!st.empty() && st.top() == '0')
      {
        st.pop();
      }
      else
      {
        st.push(ch);
      }
    }
    else
    {
      st.push(ch);
    }
  }

  return st.empty();
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    string s;
    cin >> s;
    cout << (isStringEmpty(s) ? "YES" : "NO") << endl;
  }
  return 0;
}

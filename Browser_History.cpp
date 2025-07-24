#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<string> browserHistory;
  string address;

  while (cin >> address && address != "end")
  {
    browserHistory.push_back(address);
  }

  int q;
  cin >> q;
  cin.ignore();

  auto current = browserHistory.begin();

  while (q--)
  {
    string cmd;
    getline(cin, cmd);

    if (cmd.substr(0, 5) == "visit")
    {
      string toVisit = cmd.substr(6);
      auto it = find(browserHistory.begin(), browserHistory.end(), toVisit);

      if (it != browserHistory.end())
      {
        current = it;
        cout << *current << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }

    else if (cmd == "next")
    {
      auto temp = current;
      ++temp;

      if (temp != browserHistory.end())
      {
        current = temp;
        cout << *current << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }

    else if (cmd == "prev")
    {
      if (current != browserHistory.begin())
      {
        --current;
        cout << *current << endl;
      }
      else
      {
        cout << "Not Available" << endl;
      }
    }
  }

  return 0;
}
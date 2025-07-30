#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;

  queue<string> ticketLine;

  while (q--)
  {
    int cmd;
    cin >> cmd;

    if (cmd == 0)
    {
      string name;
      cin >> name;
      ticketLine.push(name);
    }
    else if (cmd == 1)
    {
      if (ticketLine.empty())
      {
        cout << "Invalid\n";
      }
      else
      {
        cout << ticketLine.front() << '\n';
        ticketLine.pop();
      }
    }
  }

  return 0;
}

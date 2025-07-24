#include <bits/stdc++.h>
using namespace std;

int main()
{
  list<int> newList = {1, 2, 3, 4, 5, 4, 1, 67, 89, 2, 3, 6};

  newList.sort();

  for (auto i : newList)
  {
    cout << i << endl;
  }
  return 0;
}
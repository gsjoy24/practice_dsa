#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;
  cin.ignore();

  while (n--)
  {
    string line;
    getline(cin, line);
    stringstream ss(line);

    string word;
    map<string, int> mp;
    string maxWord;
    int maxCount = 0;

    while (ss >> word)
    {
      mp[word]++;

      if (mp[word] > maxCount)
      {
        maxCount = mp[word];
        maxWord = word;
      }
    }

    cout << maxWord << " " << maxCount << endl;
  }

  return 0;
}

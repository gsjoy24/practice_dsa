#include <bits/stdc++.h>
using namespace std;

int main()
{
  // !max priority
  priority_queue<int> pq;
  pq.push(10);
  pq.push(5);
  pq.push(30);
  pq.push(100);
  cout << pq.top() << endl;

  // !min priority
  priority_queue<int, vector<int>, greater<int>> min_pq;
  min_pq.push(10);
  min_pq.push(5);
  min_pq.push(30);
  min_pq.push(100);
  cout << min_pq.top() << endl;
  return 0;
}
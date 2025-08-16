#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
  string name;
  int roll;
  int marks;

  Student(string name, int roll, int marks)
  {
    this->name = name;
    this->roll = roll;
    this->marks = marks;
  }
};

class cmp
{
public:
  bool operator()(const Student &a, const Student &b)
  {
    if (a.marks != b.marks)
      return a.marks < b.marks;
    return a.roll > b.roll;
  }
};

int main()
{
  int n;
  cin >> n;

  priority_queue<Student, vector<Student>, cmp> pq;

  while (n--)
  {
    string name;
    int roll, marks;
    cin >> name >> roll >> marks;
    pq.push(Student(name, roll, marks));
  }

  int q;
  cin >> q;
  while (q--)
  {
    int cmd;
    cin >> cmd;
    if (cmd == 0)
    {
      string name;
      int roll, marks;
      cin >> name >> roll >> marks;
      pq.push(Student(name, roll, marks));
    }

    if (pq.empty())
    {
      cout << "Empty\n";
      continue;
    }

    if (cmd == 1 || cmd == 0)
    {
      Student s = pq.top();
      cout << s.name << " " << s.roll << " " << s.marks << '\n';
    }
    else if (cmd == 2)
    {
      pq.pop();
      if (pq.empty())
      {
        cout << "Empty\n";
      }
      else
      {
        Student s = pq.top();
        cout << s.name << " " << s.roll << " " << s.marks << '\n';
      }
    }
  }

  return 0;
}

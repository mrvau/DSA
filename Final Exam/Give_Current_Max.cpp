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
    bool operator()(Student a, Student b)
    {
      if(a.marks == b.marks)
      {
        return a.roll > b.roll;
      }
      else
      {
        return a.marks < b.marks;
      }
    }
};

int main()
{
  priority_queue<Student, vector<Student>, cmp> pq;
  int n;
  cin >> n;
  while(n--)
  {
    string s;
    int r, m;
    cin >> s >> r >> m;
    Student a(s, r, m);
    pq.push(a);
  }

  int q;
  cin >> q;
  while(q--)
  {
    int x;
    cin >> x;
    if(x == 0)
    {
      string s;
      int r, m;
      cin >> s >> r >> m;
      Student a(s, r, m);
      pq.push(a);
    }
    else if(x == 2)
    {
      if(!pq.empty())
      {
        pq.pop();
      }
    }
    if(!pq.empty())
    {
      cout << pq.top().name << " " << pq.top().roll << " " << pq.top().marks << endl;
    }
    else
    {
      cout << "Empty" << endl;
    }
  }

  return 0;
}
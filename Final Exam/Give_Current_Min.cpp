#include <bits/stdc++.h>
using namespace std;

int main()
{
  priority_queue<int, vector<int>, greater<int>> pq;
  int n;
  cin >> n;
  while(n--)
  {
    int x;
    cin >> x;
    pq.push(x);
  }

  int q;
  cin >> q;
  while(q--)
  {
    int y;
    cin >> y;
    if(y == 0)
    {
      int z;
      cin >> z;
      pq.push(z);
    }
    else if(y == 2)
    {
      if(!pq.empty())
        pq.pop();
    }
    if (!pq.empty())
    {
      cout << pq.top() << endl;
    }
    else
    {
      cout << "Empty" << endl;
    }
  }

  return 0;
}
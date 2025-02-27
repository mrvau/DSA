#include <bits/stdc++.h>

using namespace std;
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> h(n);
    for(int i = 0; i < n; i++)
    {
      cin >> h[i];
    }
    priority_queue<int> q;
    for (auto i : h)
    {
      q.push(i);
    }

    int m1 = q.top();
    q.pop();
    int m2 = q.top();
    q.pop();

    int i1, i2;
    for(int i = 0; i < n; i++)
    {
      if(h[i] == m1) i1 = i;
      if(h[i] == m2) i2 = i;
    }

    if(i1 < i2)
    {
      cout << i1 << " " << i2 << endl;
    }
    else
    {
      cout << i2 << " " << i1 << endl;
    }
    
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int q;
  cin >> q;
  while(q--)
  {
    int n;
    cin >> n;
    set<int> l;
    while(n--)
    {
      int m;
      cin >> m;
      l.insert(m);
    }
    for(auto i : l)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  return 0;
}
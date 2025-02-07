#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;

  vector<int> adjList[n];
  while(e--)
  {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  int q;
  cin >> q;
  while(q--)
  {
    int x;
    cin >> x;
    if(!adjList[x].empty())
    {
      sort(adjList[x].begin(), adjList[x].end(), greater<int>());
      for(int i : adjList[x])
      {
        cout << i << " ";
      }
      cout << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }

  return 0;
}
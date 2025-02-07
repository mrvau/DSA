#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;

  vector<int> adjList[n];
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
  }

  for (int i = 0; i < n; i++)
  {
    cout << i << " -> ";
    // for(int j = 0; j < adjList[i].size(); j++)
    // {
    //   cout << adjList[i][j] << " ";
    // }
    for (int x : adjList[i])
      cout << x << " ";
    cout << endl;
  }

  return 0;
}
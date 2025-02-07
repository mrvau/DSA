#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];

int main()
{
  int n, e;
  cin >> n >> e;
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  int node;
  cin >> node;
  cout << adjList[node].size() << endl;

  return 0;
}
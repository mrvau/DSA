#include <bits/stdc++.h>
using namespace std;

void dfs(int src, vector<vector<int>> list, vector<bool>& vis)
{
  cout << src << " ";
  vis[src] = true;
  for(auto child : list[src])
  {
    if(!vis[child])
    {
      dfs(child, list, vis);
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<int>> adjList(n);
  vector<bool> vis(n, false);

  while(e--)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }
  dfs(0, adjList, vis);

  return 0;
}
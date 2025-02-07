#include <bits/stdc++.h>
using namespace std;

void bfs(int src, vector<int> net[], vector<bool>& vis, vector<int>& lvl, vector<int>& par)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  lvl[src] = 1;

  while(!q.empty())
  {
    int parent = q.front();
    q.pop();
    
    for(auto child : net[parent])
    {
      if(!vis[child])
      {
        q.push(child);
        vis[child] = true;
        lvl[child] = lvl[parent] + 1;
        par[child] = parent;
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;

  vector<int> adjList[n + 1];
  vector<bool> vis(n + 1, false);
  vector<int> level(n + 1, -1);
  vector<int> parent(n + 1, -1);

  while(e--)
  {
    int u, v;
    cin >> u >> v;
    adjList[u].push_back(v);
    adjList[v].push_back(u);
  }

  bfs(1, adjList, vis, level, parent);

  if(vis[n])
  {
    vector<int> path;
    int node = n;
    while (node != -1)
    {
      path.push_back(node);
      node = parent[node];
    }
    reverse(path.begin(), path.end());
    cout << level[n] << endl;
    for (int i : path)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  else
  {
    cout << "IMPOSSIBLE" << endl;
  }
  return 0;
}
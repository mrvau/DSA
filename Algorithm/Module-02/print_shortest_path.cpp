#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];
int level[1005];
int parent[1005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  level[src] = 0;

  while(!q.empty())
  {
    int par = q.front();
    q.pop();
    for(auto child : adjList[par])
    {
      if(!vis[child])
      {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1;
        parent[child] = par;
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;
  
  while(e--)
  {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }

  memset(vis, false, sizeof(vis));
  memset(level, -1, sizeof(level));
  memset(parent, -1, sizeof(parent));
  int src, dst;
  cin >> src >> dst;
  bfs(src);

  vector<int> path;
  int node = dst;
  while(node != -1)
  {
    path.push_back(node);
    node = parent[node];
  }
  reverse(path.begin(), path.end());
  for(auto i : path)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
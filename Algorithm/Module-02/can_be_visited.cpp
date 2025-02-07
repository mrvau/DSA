#include <bits/stdc++.h>
using namespace std;
vector<int> adjList[1005];
bool vis[1005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;

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
  int src, dst;
  cin >> src >> dst;
  bfs(src);

  if(vis[dst])
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
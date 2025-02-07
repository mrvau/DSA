#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];
vector<int> level(1005, -1);

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

  int q;
  cin >> q;
  while(q--)
  {
    int sr, ds;
    cin >> sr >> ds;

    memset(vis, false, sizeof(vis));
    bfs(sr);

    if(vis[ds])
    {
      cout << level[ds] << endl;
    }
    else
    {
      cout << -1 << endl;
    }
  }

  return 0;
}
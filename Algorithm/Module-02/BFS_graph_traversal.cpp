#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];

void bfs(int src)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  while (!q.empty())
  {
    int f = q.front();
    q.pop();

    cout << f << " ";

    for (int child : adjList[f])
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
  bfs(0);
  return 0;
}
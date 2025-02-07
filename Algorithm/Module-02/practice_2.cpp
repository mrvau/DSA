#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];
vector<int> level(1005, -1);
vector<int> levelNodes;

void bfs(int src, int l)
{
  queue<int> q;
  q.push(src);
  vis[src] = true;
  level[src] = 0;

  while (!q.empty())
  {
    int par = q.front();
    q.pop();
    for (auto child : adjList[par])
    {
      if (!vis[child])
      {
        q.push(child);
        vis[child] = true;
        level[child] = level[par] + 1;
        if(level[child] == l)
        {
          levelNodes.push_back(child);
        }
      }
    }
  }
}

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

  int l;
  cin >> l;
  bfs(0, l);

  sort(levelNodes.begin(), levelNodes.end(), greater<int>());
  for(int i : levelNodes)
  {
    cout << i << " ";
  }
  return 0;
}
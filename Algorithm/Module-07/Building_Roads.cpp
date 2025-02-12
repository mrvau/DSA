#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> adjList(100005);
vector<bool> vis(100005, false);

void dfs(int src)
{
  vis[src] = true;
  
  for(int child : adjList[src])
  {
    if(!vis[child])
    {
      dfs(child);
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;
  int cnt = 0;
  while(e--)
  {
    int a, b;
    cin >> a >> b;
    adjList[a].push_back(b);
    adjList[b].push_back(a);
  }
  vector<pair<int, int>> path;
  for(int i = 1; i <= n; i++)
  {
    if(!vis[i])
    {
      if(i - 1 != 0)
      {
        cnt++;
        adjList[i].push_back(i - 1);
        adjList[i - 1].push_back(i);
        path.push_back({i - 1, i});
      }
      dfs(i);
    }
  }
  cout << cnt << endl;
  for(auto i : path)
  {
    cout << i.first << " " << i.second << endl;
  }

  return 0;
}
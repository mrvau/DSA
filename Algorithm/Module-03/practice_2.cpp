#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
vector<bool> vis(1005, false);

void dfs(int src)
{
  vis[src] = true;
  for(int i : adjList[src])
    if(!vis[i]) dfs(i);
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
  int count = 0;
  for(int i = 0; i < n; i++)
  {
    if(!vis[i])
    {
      count++;
      dfs(i);
    }
  }

  cout << count << endl;

  return 0;
}
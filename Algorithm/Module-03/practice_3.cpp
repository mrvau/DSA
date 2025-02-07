#include <bits/stdc++.h>
using namespace std;

vector<int> adjList[1005];
bool vis[1005];
int cnt;

void dfs(int src)
{
  vis[src] = true;
  cnt++;
  for(int i : adjList[src])
  {
    if(!vis[i]) dfs(i);
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

  vector<int> count;
  for(int i = 0; i < n; i++)
  {
    if(!vis[i])
    {
      cnt = 0;
      dfs(i);
      count.push_back(cnt);
    }
  }

  sort(count.begin(), count.end());
  for(int i : count)
  {
    cout << i << " ";
  }
  cout << endl;

  return 0;
}
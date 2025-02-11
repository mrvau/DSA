#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjList[105];
vector<int> dis(105, INT_MAX);
int cnt;
void bfs(int src)
{
  queue<pair<int, int>> q;
  dis[src] = 0;
  q.push({src, dis[src]});
  
  while(!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    cnt++;
    for(auto child : adjList[par.first])
    {
      if(dis[child.first] > (par.second + child.second))
      {
        dis[child.first] = par.second + child.second;
        q.push({child.first, dis[child.first]});
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
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }
  int src, dst;
  cin >> src >> dst;
  cnt = 0;
  bfs(src);
  cout << dis[dst] << " " << cnt << endl;
  return 0;
}

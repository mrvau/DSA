#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> adjList[105];
vector<int> dis(105, INT_MAX);

class cmp
{
  public:
    bool operator()(pair<int, int> l, pair<int, int> r)
    {
      return l.second > r.second;
    }
};

void dijkstra(int src)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
  dis[src] = 0;
  q.push({src, dis[src]});
  
  while (!q.empty())
  {
    pair<int, int> par = q.top();
    q.pop();
    for (auto child : adjList[par.first])
    {
      if (dis[child.first] > (par.second + child.second))
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
  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    adjList[a].push_back({b, c});
    adjList[b].push_back({a, c});
  }
  int src, dst;
  cin >> src >> dst;
  dijkstra(src);
  return 0;
}

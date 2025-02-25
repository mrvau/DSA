#include <bits/stdc++.h>
using namespace std;

void dijkstra(int src,vector<vector<pair<int, int>>> lists,vector<int> &parent,vector<int> &dis)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  dis[src] = 0;
  q.push({dis[src], src});
  while (!q.empty())
  {
    pair<int, int> par = q.top();
    q.pop();
    int parDis = par.first;
    int parNode = par.second;
    for (auto child : lists[parNode])
    {
      int childNode = child.first;
      int childDis = child.second;

      if (parDis + childDis < dis[childNode])
      {
        dis[childNode] = parDis + childDis;
        parent[childNode] = parNode;
        q.push({dis[childNode], childNode});
      }
    }
  }
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<vector<pair<int, int>>> lists(n + 1);
  vector<int> parent(n + 1, -1);
  vector<int> dis(n + 1, INT_MAX);
  
  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    lists[a].push_back({b, c});
    lists[b].push_back({a, c});
  }

  

  dijkstra(1, lists, parent, dis);
  if (dis[n] != INT_MAX)
  {
    vector<int> path;
    int d = n;
    while (true)
    {
      if (d == 1)
      {
        path.push_back(d);
        break;
      }
      path.push_back(d);
      d = parent[d];
    }
    reverse(path.begin(), path.end());
    for (auto i : path)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  else
  {
    cout << -1 << endl;
  }

  return 0;
}

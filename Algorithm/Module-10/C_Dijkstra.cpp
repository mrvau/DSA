#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> lists(1e5);
vector<int> parent(1e5, -1);
vector<int> dis(1e5, INT_MAX);

void dijkstra(int src)
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
  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    lists[a].push_back({b, c});
    lists[b].push_back({a, c});
  }

  dijkstra(1);
  if (dis[n] != INT_MAX)
  {
    vector<int> path;
    int d = n;
    while (true)
    {
      if (d == 1)
      {
        cout << d << " ";
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
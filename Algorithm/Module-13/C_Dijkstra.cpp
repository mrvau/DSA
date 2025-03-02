#include <bits/stdc++.h>
using namespace std;

#define ll long long int

vector<vector<pair<ll, ll>>> lists(1e5+1);
vector<int> parent(1e5+1, -1);
vector<ll> dis(1e5+1, LLONG_MAX);

void dijkstra(int src)
{
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;
  dis[src] = 0;
  q.push({dis[src], src});
  while (!q.empty())
  {
    pair<ll, ll> par = q.top();
    q.pop();
    ll parDis = par.first;
    ll parNode = par.second;
    for (auto child : lists[parNode])
    {
      ll childNode = child.first;
      ll childDis = child.second;

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
  if (dis[n] != LLONG_MAX)
  {
    vector<int> path;
    int d = n;
    while (d != -1)
    {
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

#include <bits/stdc++.h>
using namespace std;

class Edge
{
  public:
    int a, b, c;
    Edge(int a, int b, int c)
    {
      this->a = a;
      this->b = b;
      this->c = c;
    }

};

vector<Edge> edge;
int dis[1001];
int n, e;

void bellman_ford()
{
  dis[0] = 0;
  for(int i = 1; i < n; i++)
  {
    for(auto e : edge)
    {
      int a, b, c;
      a = e.a;
      b = e.b;
      c = e.c;
      if(dis[a] != INT_MAX && dis[a] + c < dis[b])
      {
        dis[b] = dis[a] + c;
      }
    }
  }

  bool cycle = false;
  for (auto e : edge)
  {
    int a, b, c;
    a = e.a;
    b = e.b;
    c = e.c;
    if (dis[a] != INT_MAX && dis[a] + c < dis[b])
    {
      cycle = true;
      break;
    }
  }
  if(cycle)
  {
    cout << "Negative cycle detected" << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      cout << i << " -> " << dis[i] << endl;
    }
  }
}
int main()
{
  cin >> n >> e;
  while(e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    edge.push_back(Edge(a, b, c));
  }
  for(int i = 0; i < n; i++)
  {
    dis[i] = INT_MAX;
  }

  bellman_ford();
  

  return 0;
}
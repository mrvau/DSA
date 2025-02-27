#include <bits/stdc++.h>
using namespace std;

class Edge
{
  public:
    long long int a, b, c;
    Edge(long long int a, long long int b, long long int c)
    {
      this->a = a;
      this->b = b;
      this->c = c;
    }
};

vector<Edge> edge;
long long int dis[1001];
int n, e, s;
bool cycle;

void bellmanford()
{
  dis[s] = 0;
  for(int i = 1; i < n; i++)
  {
    for(auto e : edge)
    {
      int a = e.a, b = e.b, c= e.c;
      if(dis[a] != LLONG_MAX && dis[a] + c < dis[b])
      {
        dis[b] = dis[a] + c;
      }
    }
  }
  for (auto e : edge)
  {
    int a = e.a, b = e.b, c = e.c;
    if (dis[a] != LLONG_MAX && dis[a] + c < dis[b])
    {
      cycle = true;
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

  for(int i = 1; i <= n; i++)
  {
    dis[i] = LLONG_MAX;
  }

  cycle = false;
  cin >> s;
  bellmanford();

  if(cycle)
  {
    cout << "Negative Cycle Detected" <<endl;
  }
  else
  {
    int t;
    cin >> t;
    while(t--)
    {
      int d;
      cin >> d;
      if(dis[d] == LLONG_MAX)
      {
        cout << "Not Possible" << endl;
      }
      else
      {
        cout << dis[d] << endl;
      }
    }
  }
  return 0;
}
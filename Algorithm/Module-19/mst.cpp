#include <bits/stdc++.h>
using namespace std;

int par[1001];
int group_size[1001];

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

int find(int node)
{
  if (par[node] == -1)
    return node;
  int leader = find(par[node]);
  par[node] = leader;
  return leader;
}

void dsu_union(int n, int m)
{
  int leader1 = find(n);
  int leader2 = find(m);

  if (group_size[leader1] >= group_size[leader2])
  {
    par[leader2] = leader1;
    group_size[leader1] += group_size[leader2];
  }
  else
  {
    par[leader1] = leader2;
    group_size[leader2] += group_size[leader1];
  }
}

bool cmp(Edge l, Edge r)
{
  return l.c < r.c;
}

int main()
{
  int n, e;
  cin >> n >> e;
  vector<Edge> edge;
  for(int i = 0; i < e; i++)
  {
    int a, b, c;
    cin>> a  >> b >> c;
    edge.push_back(Edge(a, b, c));
  }

  sort(edge.begin(), edge.end(), cmp);

  memset(par, -1, sizeof(par));
  memset(group_size, 1, sizeof(group_size));

  int totalCost = 0;
  for(auto i : edge)
  {
    if (find(i.a) != find(i.b))
    {
      dsu_union(i.a, i.b);
      totalCost += i.c;
    }
  }

  cout << totalCost << endl;

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int par[1001];
int group_size[1001];

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

int main()
{
  memset(par, -1, sizeof(par));
  memset(group_size, 1, sizeof(group_size));

  int n, e;
  cin >> n >> e;

  bool cycle = false;
  while(e--)
  {
    int a, b;
    cin >> a >> b;
    int leaderA = find(a);
    int leaderB = find(b);

    if(leaderA == leaderB) cycle = true;
    else dsu_union(a, b);
  }
  
  cout << (cycle ? "Cycle Detected" : "No Cycle") << endl;
  return 0;
}
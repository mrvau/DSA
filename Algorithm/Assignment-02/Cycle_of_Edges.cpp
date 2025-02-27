#include <bits/stdc++.h>
using namespace std;

int par[100001];
int group_size[100001];

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

  int cnt = 0;
  while (e--)
  {
    int a, b;
    cin >> a >> b;
    int leaderA = find(a);
    int leaderB = find(b);

    if (leaderA == leaderB)
      cnt++;
    else
      dsu_union(a, b);
  }

  cout << cnt << endl;
  return 0;
}
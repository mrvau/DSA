#include <bits/stdc++.h>
using namespace std;
int par[100001];
int group_size[100001];

void dsu_init(int n)
{
  for (int i = 0; i <= n; i++)
  {
    par[i] = -1;
    group_size[i] = 1;
  }
}

int find(int node)
{
  if (par[node] == -1)
    return node;
  int leader = find(par[node]);
  par[node] = leader;
  return leader;
}

void dsu_union(int node1, int node2)
{
  int leader1 = find(node1);
  int leader2 = find(node2);

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
  int n, m;
  cin >> n >> m;
  dsu_init(n);

  while (m--)
  {
    int a, b;
    cin >> a >> b;

    int ledA = find(a);
    int ledB = find(b);

    if (ledA != ledB)
    {
      dsu_union(a, b);
    }
  }

  int cnt = 0;
  vector<int> path;
  for (int i = 1; i <= n; i++)
  {
    int p1 = find(1);
    int pi = find(i);

    if (pi != p1)
    {
      cnt++;
      dsu_union(1, i);
      path.push_back(i);
    }
  }

  cout << cnt << endl;
  for (auto i : path)
  {
    cout << '1' << " "<< i << " ";
  }

  return 0;
}
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

  if(group_size[leader1] >= group_size[leader2])
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
  
  dsu_union(1, 2);
  dsu_union(1, 3);
  dsu_union(2, 4);
  dsu_union(3, 5);
  dsu_union(4, 6);



  cout << find(4) << endl;
  for (int i = 0; i <= 6; i++)
  {
    cout << i << " -> " << par[i] << endl;
  }
  return 0;
}
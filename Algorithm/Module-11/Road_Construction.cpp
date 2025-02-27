#include <bits/stdc++.h>
using namespace std;
int par[100001];
int group_size[100001];

void dsu_init(int n)
{
  for(int i = 0; i <=n ; i++)
  {
    par[i] = -1;
    group_size[i] = 1;
  }
}

int find(int node)
{
  if(par[node] == -1) return node;
  int leader = find(par[node]);
  par[node] = leader;
  return leader;
}

int mx;

void dsu_union(int node1, int node2)
{
  int leader1 = find(node1);
  int leader2 = find(node2);

  if(group_size[leader1] >= group_size[leader2])
  {
    par[leader2] = leader1;
    group_size[leader1] += group_size[leader2];
    mx = max(group_size[leader1], mx);
  }
  else
  {
    par[leader1] = leader2;
    group_size[leader2] += group_size[leader1];
    mx = max(group_size[leader2], mx);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  dsu_init(n);
  
  int comps = n;
  mx = 0;
  while(m--)
  {
    int a, b;
    cin >> a >> b;

    
    int ledA = find(a);
    int ledB = find(b);

    if(ledA != ledB)
    {
      dsu_union(a, b);
      comps--;
    }

    cout << comps << " " << mx << endl;
  }
  return 0;
}
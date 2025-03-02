#include <bits/stdc++.h>
using namespace std;

int par[1001];
int group_size[1001];

int find(int node)
{
  if(par[node] == -1) return node;
  int leader = find(par[node]);
  par[node] = leader;
  return leader;
}

void dsu_union(int a, int b)
{
  int leaderA = find(a);
  int leaderB = find(b);

  if(group_size[leaderA] >= group_size[leaderB])
  {
    par[leaderB] = leaderA;
    group_size[leaderA] += group_size[leaderB];
  }
  else
  {
    par[leaderA] = leaderB;
    group_size[leaderB] += group_size[leaderA];
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++)
  {
    par[i] = -1;
    group_size[i] = 1;
  }

  vector<pair<int, int>> rmv;
  vector<pair<int, int>> con;
  
  for(int i = 0;i < n -1; i++)
  {
    int a, b;
    cin >> a >> b;

    int leaderA = find(a);
    int leaderB = find(b);

    if(leaderA  == leaderB)
    {
      rmv.push_back({a, b});
    }
    else
    {
      dsu_union(a, b);
    }
  }

  for(int i = 2; i <= n; i++)
  {
    int leader1 = find(1);
    int leaderI = find(i);

    if(leader1 != leaderI)
    {
      dsu_union(1, i);
      con.push_back({1, i});
    }
  }

  cout << con.size() << endl;

  for(int i = 0; i<con.size(); i++)
  {
    cout << rmv[i].first << " " << rmv[i].second << " " << con[i].first << " " << con[i].second << endl;
  }
  
  return 0;
}
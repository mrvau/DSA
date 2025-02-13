#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
int level[1001][1001];
int n, m;

vector<pair<int, int>> d = {{2, -1}, {2, 1}, {1, -2}, {-1, -2}, {-2, -1}, {-2, 1}, {1, 2}, {-1, 2}};
bool valid(int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= m)
    return false;
  return true;
}

void bfs(int sr, int sc)
{
  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = true;
  level[sr][sc] = 0;
  while(!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    int par_i = par.first;
    int par_j = par.second;
    for(int i = 0; i < 8; i++)
    {
      int ci = par_i + d[i].first;
      int cj = par_j + d[i].second;
      if(valid(ci, cj) && !vis[ci][cj])
      {
        q.push({ci, cj});
        vis[ci][cj] = true;
        level[ci][cj] = level[par_i][par_j] + 1;
      }
      
    }
  }
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    cin >> n >> m;
    int ki, kj, qi, qj;
    cin >> ki >> kj >> qi >> qj;
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    bfs(ki, kj);
    cout << level[qi][qj] << endl;
  }

  return 0;
}
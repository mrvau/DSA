#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
int n, e;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool valid(int x, int y)
{
  if(x < 0 || x >= n || y < 0 || y >= e) return false;
  return true;
}

void dfs(int sr, int sc)
{
  vis[sr][sc] = true;
  for(int i = 0; i < 4; i++)
  {
    int cr = sr + d[i].first;
    int cc = sc + d[i].second;
    if(valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] == '.')
    {
      dfs(cr ,cc);
    }
  }
}

int main()
{
  cin >> n >> e;
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < e; j++)
    {
      cin >> grid[i][j];
    }
  }
  int sr, sc, dr, dc;
  cin >> sr >> sc >> dr >> dc;

  dfs(sr, sc);

  if(vis[dr][dc])
    cout << "YES" << endl;
  else
    cout << "NO" << endl;

  return 0;
}
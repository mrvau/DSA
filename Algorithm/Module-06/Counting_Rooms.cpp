#include <bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, e;

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool isValid(int x, int y)
{
  if(x < 0 || x >= n || y < 0 || y >= e || grid[x][y] == '#') return false;
  else return true;
}

void dfs(int sr, int sc)
{
  vis[sr][sc] = true;
  for(int i = 0; i < 4; i++)
  {
    int cr = sr + moves[i].first;
    int cc = sc + moves[i].second;
    if(isValid(cr, cc) && !vis[cr][cc])
    {
      dfs(cr, cc);
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
  memset(vis, false, sizeof(vis));
  int cnt = 0;
  for (int i = 0; i < n; i++)
  {
    for(int j = 0; j < e; j++)
    {
      if(!vis[i][j] && grid[i][j] == '.')
      {
        cnt++;
        dfs(i, j);
      }
    }
  }
  cout << cnt << endl;

  return 0;
}
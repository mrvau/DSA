#include <bits/stdc++.h>
using namespace std;
char grid[1001][1001];
bool vis[1001][1001];
pair<int, int> parent[1001][1001];
int n, e;

vector<pair<int, int>> d = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
bool valid(int x, int y)
{
  if (x < 0 || x >= n || y < 0 || y >= e)
    return false;
  return true;
}

void bfs(int sr, int sc)
{
  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = true;
  while (!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    int par_i = par.first;
    int par_j = par.second;
    for (int i = 0; i < 4; i++)
    {
      int ci = par_i + d[i].first;
      int cj = par_j + d[i].second;
      if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'R' || grid[ci][cj] == 'D'))
      {
        q.push({ci, cj});
        vis[ci][cj] = true;
        parent[ci][cj] = {par_i, par_j};
      }
    }
  }
}

int main()
{
  cin >> n >> e;
  int sr, sc, dr, dc;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < e; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'R')
      {
        sr = i;
        sc = j;
      }
      if (grid[i][j] == 'D')
      {
        dr = i;
        dc = j;
      }
    }
  }

  memset(vis, false, sizeof(vis));
  memset(parent, -1, sizeof(parent));

  bfs(sr, sc);
  if (vis[dr][dc])
  {
    int x = dr, y = dc;
    while (true)
    {
      pair<int, int> par = parent[x][y];
      x = par.first;
      y = par.second;
      if(grid[x][y] == 'R') break;
      grid[x][y] = 'X';
    }
  }

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < e; j++)
    {
      cout << grid[i][j];
    }
    cout << endl;
  }

  return 0;
}
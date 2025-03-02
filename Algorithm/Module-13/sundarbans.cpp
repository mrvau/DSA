#include <bits/stdc++.h>
using namespace std;

char grid[30][30];
bool vis[30][30];
int level[30][30];
vector<pair<int, int> > m;

int n;
bool valid(int sr, int sc)
{
  if (sr < 0 || sr >= n || sc < 0 || sc >= n)
    return false;
  else
    return true;
}

void bfs(int sr, int sc)
{
  queue<pair<int, int> > q;
  q.push({sr, sc});
  vis[sr][sc] = true;
  level[sr][sc] = 0;
  while (!q.empty())
  {
    pair<int, int> par = q.front();
    q.pop();
    int pr = par.first;
    int pc = par.second;

    for (int i = 0; i < 4; i++)
    {
      int cr = pr + m[i].first;
      int cc = pc + m[i].second;

      if (valid(cr, cc) && !vis[cr][cc] && grid[cr][cc] != 'T')
      {
        q.push({cr, cc});
        vis[cr][cc] = true;
        level[cr][cc] = level[pr][pc] + 1;
      }
    }
  }
}

int main()
{
  m.push_back({0, 1});
  m.push_back({0, -1});
  m.push_back({1, 0});
  m.push_back({-1, 0});
  
  int sr, sc, dr, dc;
  while (cin >> n)
  {
    memset(vis, false, sizeof(vis));
    memset(level, -1, sizeof(level));
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        cin >> grid[i][j];
        if (grid[i][j] == 'S')
        {
          sr = i;
          sc = j;
        }
        if (grid[i][j] == 'E')
        {
          dr = i;
          dc = j;
        }
      }
    }

    bfs(sr, sc);
    cout << level[dr][dc] << endl;
  }
  return 0;
}
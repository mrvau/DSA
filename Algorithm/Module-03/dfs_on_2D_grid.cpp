#include <bits/stdc++.h>
using namespace std;

int r, c;
char grid[105][105];
bool vis[105][105];
vector<pair<int, int>> moves = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

bool isValid(int row, int col)
{
  if(row < 0 || row >= r || col < 0 || col >= c)
    return false;
  return true;
}

void dfs(int si, int sj)
{
  cout << si << " " << sj << endl;
  vis[si][sj] = true;

  for(int i = 0; i < 4; i++)
  {
    int ci = si + moves[i].first;
    int cj = sj + moves[i].second;
    if(isValid(ci, cj) && !vis[ci][cj])
      dfs(ci, cj);
  }
}

int main()
{
  cin >> r >> c;
  
  for(int i = 0; i < r; i++)
  {
    for(int j = 0; j < c; j++)
    {
      cin >> grid[i][j];
    }
  }
  
  memset(vis, false, sizeof(vis));
  int si, sj;
  cin >> si >> sj;
  dfs(si, sj);

  return 0;
}
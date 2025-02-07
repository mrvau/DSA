#include <bits/stdc++.h>
using namespace std;

int n, m;

char mat[1001][1001];
bool vis[1001][1001];

vector<pair<int, int>> moves = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int cnt;

bool isValid(int r, int c)
{
  if (r < 0 || r >= n || c < 0 || c >= m)
    return false;
  return true;
}

void dfs(int sr, int sc)
{
  vis[sr][sc] = true;
  cnt++;
  for (int i = 0; i < 4; i++)
  {
    int cr = sr + moves[i].first;
    int cc = sc + moves[i].second;
    if (isValid(cr, cc) && !vis[cr][cc] && mat[cr][cc] == '.')
    {
      dfs(cr, cc);
    }
  }
}

int main()
{
  memset(vis, false, sizeof(vis));
  cin >> n >> m;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> mat[i][j];
    }
  }

  int count = 0;
  vector<int> numberOfRooms;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (mat[i][j] == '.')
      {
        if (!vis[i][j])
        {
          cnt = 0;
          dfs(i, j);
          count++;
          numberOfRooms.push_back(cnt);
        }
      }
    }
  }
  sort(numberOfRooms.begin(), numberOfRooms.end());
  if(!numberOfRooms.empty())
  {
    for (int i : numberOfRooms)
    {
      cout << i << " ";
    }
    cout << endl;
  }
  else
  {
    cout << 0 << endl;
  }
  return 0;
}
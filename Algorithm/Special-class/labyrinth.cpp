#include <bits/stdc++.h>
using namespace std;

int n, m;
char grid[1001][1001];
bool vis[1001][1001];
int dis[1001][1001];
pair<int, int> par[1001][1001];
vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool valid(int i, int j)
{
  if (i < 0 || i >= n || j < 0 || j >= m)
    return false;
  return true;
}

void bfs(int sr, int sc)
{
  queue<pair<int, int>> q;
  q.push({sr, sc});
  vis[sr][sc] = true;
  par[sr][sc] = {-1, -1};
  dis[sr][sc] = 0;

  while (!q.empty())
  {
    pair<int, int> parent = q.front();
    q.pop();
    int par_i = parent.first, par_j = parent.second;

    for (int i = 0; i < 4; i++)
    {
      int ci = par_i + dir[i].first;
      int cj = par_j + dir[i].second;

      if (valid(ci, cj) && !vis[ci][cj] && (grid[ci][cj] == '.' || grid[ci][cj] == 'A' || grid[ci][cj] == 'B'))
      {
        q.push({ci, cj});
        vis[ci][cj] = true;
        dis[ci][cj] = dis[par_i][par_j] + 1;
        par[ci][cj] = {par_i, par_j};
      }
    }
  }
}

int main()
{
  cin >> n >> m;
  int si, sj, di, dj;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
      if (grid[i][j] == 'A')
      {
        si = i;
        sj = j;
      }
      if (grid[i][j] == 'B')
      {
        di = i;
        dj = j;
      }
    }
  }
  memset(vis, false, sizeof(vis));
  memset(dis, -1, sizeof(dis));
  bfs(si, sj);
  vector<char> path;
  if (vis[di][dj])
  {
    cout << "YES" << endl;
    cout << dis[di][dj] << endl;

    int ci = di, cj = dj;
    while (true)
    {
      if (grid[ci][cj] == 'A')
        break;
      pair<int, int> p = par[ci][cj];
      int pi = p.first, pj = p.second;
      if (pi - ci == 0 && pj - cj == -1)
      {
        path.push_back('R');
      }
      if (pi - ci == 0 && pj - cj == 1)
      {
        path.push_back('L');
      }
      if (pi - ci == 1 && pj - cj == 0)
      {
        path.push_back('U');
      }
      if (pi - ci == -1 && pj - cj == 0)
      {
        path.push_back('D');
      }
      ci = pi;
      cj = pj;
    }
    reverse(path.begin(), path.end());
    for(char i : path)
    {
      cout << i;
    }
    cout << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
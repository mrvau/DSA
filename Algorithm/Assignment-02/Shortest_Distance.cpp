#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;
  long long int mat[n + 1][n + 1];

  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == j)
      {
        mat[i][j] = 0;
      }
      else
      {
        mat[i][j] = LLONG_MAX;
      }
    }
  }

  while (e--)
  {
    long long int a, b, c;
    cin >> a >> b >> c;

    mat[a][b] = min(mat[a][b], c);
  }

  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (mat[i][k] != LLONG_MAX && mat[k][j] != LLONG_MAX && mat[i][k] + mat[k][j] < mat[i][j])
        {
          mat[i][j] = mat[i][k] + mat[k][j];
        }
      }
    }
  }

  int t;
  cin >> t;
  while (t--)
  {
    int s, d;
    cin >> s >> d;
    if (mat[s][d] == LLONG_MAX)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << mat[s][d] << endl;
    }
  }
}

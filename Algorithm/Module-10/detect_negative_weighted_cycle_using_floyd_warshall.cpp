#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;
  int mat[n][n];
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (i == j)
      {
        mat[i][j] = 0;
      }
      else
      {
        mat[i][j] = INT_MAX;
      }
    }
  }
  while (e--)
  {
    int a, b, c;
    cin >> a >> b >> c;
    mat[a][b] = c;
  }

  for (int k = 0; k < n; k++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mat[i][k] != INT_MAX && mat[k][j] != INT_MAX && mat[i][k] + mat[k][j] < mat[i][j])
        {
          mat[i][j] = mat[i][k] + mat[k][j];
        }
      }
    }
  }

  bool cycle = false;
  for (int i = 0; i < n; i++)
  {
    if (mat[i][i] < 0)
    {
      cycle = true;
    }
  }

  if(cycle)
  {
    cout << "Negative Weighted Cycle Detected!" << endl;
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (mat[i][j] == INT_MAX)
        {
          cout << "INF ";
        }
        else
        {
          cout << mat[i][j] << " ";
        }
      }
      cout << endl;
    }
  }

  return 0;
}
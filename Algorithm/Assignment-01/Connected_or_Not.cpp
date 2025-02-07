#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, e;
  cin >> n >> e;

  int adjMat[n][n];
  memset(adjMat, 0, sizeof(adjMat));
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      if(i == j) adjMat[i][j] = 1;
    }
  }

  while(e--)
  {
    int a, b;
    cin >> a >> b;
    adjMat[a][b] = 1;
  }
  int q;
  cin >> q;
  while(q--)
  {
    int src, dst;
    cin >> src >> dst;

    if(adjMat[src][dst] == 1)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
}
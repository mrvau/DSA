#include <bits/stdc++.h>
using namespace std;

int grid[11][11];
int n, m;

int knapsack(int i, int j)
{
  if (i == n - 1 && j == m - 1)
    return grid[i][j];
  else if (i == n || j == m)
    return -1000000;

  int op1 = grid[i][j] + knapsack(i + 1, j);
  int op2 = grid[i][j] + knapsack(i, j + 1);
  return max(op1, op2);git 
}

int main()
{
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      cin >> grid[i][j];

  cout << knapsack(0, 0) << endl;
  return 0;
}
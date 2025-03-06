#include <bits/stdc++.h>
using namespace std;

int val[1001], weight[1001];
int dp[1001][1001];

int knapsack(int i, int w)
{
  if(i < 0 || w <= 0) return 0;
  if(dp[i][w] != -1) return dp[i][w];
  if(weight[i] <= w)
  {
    int op1 = knapsack(i - 1, w - weight[i]) + val[i];
    int op2 = knapsack(i - 1, w);
    dp[i][w] = max(op1, op2);
    return dp[i][w];
  }
  else
  {
    dp[i][w] = knapsack(i - 1, w);
    return dp[i][w];
  }
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n, w;
    cin >> n >> w;
    for(int i = 0; i < n; i++)
    {
      cin >> weight[i];
    }
    for(int i = 0; i < n; i++)
    {
      cin >> val[i];
    }
    memset(dp, -1, sizeof(dp));
    cout << knapsack(n - 1, w) << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int val[1001];
int dp[1001][1001];

int subsetSum(int i, int sum)
{
  if (i < 0)
  {
    if (sum == 0)
      return 1;
    else
      return 0;
  }

  if (dp[i][sum] != -1)
    return dp[i][sum];

  if (val[i] <= sum)
  {
    dp[i][sum] = subsetSum(i - 1, sum - val[i]) + subsetSum(i - 1, sum);
    return dp[i][sum];
  }
  else
  {
    dp[i][sum] = subsetSum(i - 1, sum);
    return dp[i][sum];
  }
}

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> val[i];
  int sum;
  cin >> sum;
  memset(dp, -1, sizeof(dp));
  cout << subsetSum(n - 1, sum) << endl;
  return 0;
}
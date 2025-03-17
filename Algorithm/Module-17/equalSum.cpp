#include <bits/stdc++.h>
using namespace std;

int val[1001];
int dp[1001][1001];

bool subsetSum(int i, int sum)
{
  if (i < 0)
  {
    if (sum == 0)
      return true;
    else
      return false;
  }

  if (dp[i][sum] != -1)
    return dp[i][sum];

  if (val[i] <= sum)
  {
    dp[i][sum] = subsetSum(i - 1, sum - val[i]) || subsetSum(i - 1, sum);
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
  int sum = 0;
  for (int i = 0; i < n; i++)
  {
    cin >> val[i];
    sum += val[i];
  }
  if(sum % 2 == 0)
  {
    memset(dp, -1, sizeof(dp));
    cout << (subsetSum(n - 1, sum / 2) ? "YES" : "NO") << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
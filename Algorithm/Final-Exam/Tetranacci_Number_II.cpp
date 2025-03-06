#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin >> n;

  long long int dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 2;
  for (int i = 4; i <= n; i++)
  {
    dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
  }
  cout << dp[n] << endl;
  return 0;
}
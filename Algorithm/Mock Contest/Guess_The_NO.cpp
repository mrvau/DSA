#include <bits/stdc++.h>
using namespace std;

bool canReach(long long int n, long long int t, long long int dp[])
{
  if (n > t)
    return false;
  if (n == t)
    return true;
  if (dp[n] != -1)
    return dp[n];
  dp[n] = canReach(n + 3, t, dp) || canReach(n + 4, t, dp);
  return dp[n];
}

int main()
{
  long long int t;
  cin >> t;
  if (t >= 10000000)
  {
    cout << "YES" << endl;
    return 0;
  }
  long long int dp[t + 1];
  for (int i = 0; i <= t; i++)
  {
    dp[i] = -1;
  }
  if (canReach(0, t, dp))
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
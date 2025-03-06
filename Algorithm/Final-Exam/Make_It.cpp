#include <bits/stdc++.h>
using namespace std;

int dp[100001];

bool canReach(int i, int n)
{
  if(i > n) return false;
  if(i == n) return true;
  if(dp[i] != -1) return dp[i];

  dp[i] = canReach(i + 3, n) || canReach(i * 2, n);
  return dp[i];
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    if(canReach(1, n))
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}
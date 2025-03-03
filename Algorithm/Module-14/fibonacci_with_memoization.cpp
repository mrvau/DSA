#include <bits/stdc++.h>
using namespace std;

long long int dp[1001];

long long int fib(long long int n)
{
  if(n == 0 || n == 1) return n;
  if(dp[n] != -1) return dp[n];
  dp[n] = fib(n - 1) + fib(n - 2);
  return dp[n];
}

int main()
{
  memset(dp, -1, sizeof(dp));

  int n;
  cin >> n;
  cout  << fib(n) << endl;
  return 0;
}
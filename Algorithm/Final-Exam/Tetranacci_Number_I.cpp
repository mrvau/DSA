#include <bits/stdc++.h>
using namespace std;

int dp[31];

int fib(int n)
{
  if (n == 0 || n == 1)
    return n;
  if (n == 2)
    return 1;
  if (n == 3)
    return 2;

  if(dp[n] != -1) return dp[n];

  dp[n] = fib(n - 1) + fib(n - 2) + fib(n - 3) + fib(n - 4);
  return dp[n];
}

int main()
{
  int n;
  cin >> n;

  memset(dp, -1, sizeof(dp));
  cout << fib(n) << endl;
  return 0;
}
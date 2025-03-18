#include <bits/stdc++.h>
using namespace std;

string a, b;
int dp[1001][1001];
int lcs(int i, int j)
{
  if (i < 0 || j < 0)
    return 0;

  if(dp[i][j] != -1)
    return dp[i][j];
  if (a[i] == b[j])
  {
    dp[i][j] = lcs(i - 1, j - 1) + 1;
    return dp[i][j];
  }
  else
  {
    int op1 = lcs(i - 1, j);
    int op2 = lcs(i, j - 1);
    dp[i][j] = max(op1, op2);
    return dp[i][j];
  }
}

int main()
{
  cin >> a >> b;
  int n = a.size();
  int m = b.size();
  memset(dp, -1, sizeof(dp));
  cout << lcs(n - 1, m - 1);

  return 0;
}
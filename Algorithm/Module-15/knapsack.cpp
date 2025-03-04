#include <bits/stdc++.h>
using namespace std;
int val[1001], weight[1001];

int knapsack(int i, int mx_w)
{
  if(i < 0 || mx_w <= 0) return 0;
  if (weight[i] <= mx_w)
  {
    int op1 = knapsack(i - 1, mx_w - weight[i]) + val[i];
    int op2 = knapsack(i - 1, mx_w);

    return max(op1, op2);
  }
  else
  {
    return knapsack(i - 1, mx_w);
  }
}

int main()
{
  int n, mx_w;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> val[i];
  for (int i = 0; i < n; i++)
    cin >> weight[i];

  cin >> mx_w;

  cout << knapsack(n - 1, mx_w) << endl;
  return 0;
}
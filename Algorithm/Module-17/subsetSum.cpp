#include <bits/stdc++.h>
using namespace std;

int val[1001];

bool subsetSum(int i, int sum)
{
  if(i < 0)
  {
    if(sum == 0) return true;
    else return false;
  }

  if(val[i] <= sum)
  {
    return subsetSum(i-1, sum - val[i]) || subsetSum(i-1, sum);
  }
  else
  {
    return subsetSum(i - 1, sum);
  }
}

int main()
{
  int n;
  cin >> n;
  for(int i = 0; i < n; i++)
    cin >> val[i];
  int sum;
  cin >> sum;
  cout << (subsetSum(n-1, sum) ? "YES" : "NO") << endl;
  return 0;
}
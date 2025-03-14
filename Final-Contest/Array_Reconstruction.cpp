#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;
    int a[n - 2];
    long long int currSum = 0;
    for (int i = 0; i < n - 2; i++)
    {
      cin >> a[i];
      currSum += a[i];
    }
    long long int sum;
    cin >> sum;
    long long int remains = sum - currSum;
    cout << remains + 1 << endl;
  }
  return 0;
}
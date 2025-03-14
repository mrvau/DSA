#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> a(n);
  for(int i = 0;i < n;i++)
  {
    cin >> a[i];
  }
  long long int sum = 0;
  int t = -1;

  sort(a.begin(), a.end(), greater<int>());

  for(int i = 0; i < n; i++)
  {
    if(a[i] != t)
    {
      sum += a[i];
      t = a[i];
    }
  }
  cout << sum << endl;
  return 0;
}
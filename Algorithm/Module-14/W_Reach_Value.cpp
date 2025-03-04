#include <bits/stdc++.h>
using namespace std;

bool check(long long int v, long long int n)
{
  if(v > n) return false;
  if(v == n) return true;
  return check(v * 10, n) || check(v * 20, n);
}

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    long long int n;
    cin >> n;
    cout << (check(1, n) ? "YES" : "NO") << endl;
  }
  return 0;
}
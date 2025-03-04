#include <bits/stdc++.h>
using namespace std;

long long int fact(int n)
{
  if(n == 1) return n;
  return n * fact(n - 1);
}

int main()
{
  int n;
  cin >> n;
  if(n == 0)
  {
    cout << 1 << endl;
  }
  else cout << fact(n) << endl;
  return 0;
}
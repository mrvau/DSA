#include <bits/stdc++.h>
using namespace std;

void digit(unsigned long long int n)
{
  if (n < 10)
  {
    cout << n << " ";
    return;
  }
  digit(n / 10);
  cout << n % 10 << " ";
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    unsigned long long int n;
    cin >> n;
    if (n == 0)
    {
      cout << n << endl;
    }
    else
    {
      digit(n);
      cout << endl;
    }
  }
  return 0;
}
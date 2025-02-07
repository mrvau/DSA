#include <bits/stdc++.h>
using namespace std;

void printDigit(int n)
{
  if(n < 0)
    return;
  printDigit(n % 10);
  cout << n << endl;
}

int main()
{
  int n;
  cin >> n;
  printDigit(n);

  return 0;
}
#include <bits/stdc++.h>
using namespace std;

void rec(int n)
{
  if (n > 5)
    return;
  rec(n + 1);
  cout << n << endl;
}

int add(int n)
{
  if(n == 1)
    return 1;
  return n + add(n-1);
}

int main()
{
  // rec(1);
  cout << add(5) << endl;
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    for(int i = 0 ; i < n; i++)
    {
      for(int j = i + 1; i < n ;i++)
      {
        if(a[i] > a[j]) swap(a[i], a[j]);
      }
    }
    int missing = 0;
    if (a[n - 1] != n)
    {
      missing++;
    }
    if (a[0] > 1)
    {
      missing += a[0] - 1;
    }

    for (int i = 0; i < n; i++)
    {
      if (i != n - 1)
      {
        if (abs(a[i] - a[i + 1]) > 1)
          missing++;
      }
    }
    cout << missing << endl;
  }

  return 0;
}
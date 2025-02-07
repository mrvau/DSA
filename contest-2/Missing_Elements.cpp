#include <bits/stdc++.h>
using namespace std;

int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
      cin >> a[i];
    }
    sort(a.begin(), a.end());

    int missing = 0;
    if(a[n - 1] != n)
    {
      missing++;
    }
    if(a[0] > 1)
    {
      missing += a[0] - 1;
    }

    for(int i = 0; i < n; i++)
    {
      if(i != n - 1)
      {
        if (abs(a[i] - a[i + 1]) > 1)
          missing += (abs(a[i] - a[i + 1]) - 1);
      }
      
    }
    cout << missing << endl;
  }


  return 0;
}
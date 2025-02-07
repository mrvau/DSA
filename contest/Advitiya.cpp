#include <bits/stdc++.h>

using namespace std;

int main()
{
  // your code goes here
  string s = "ADVITIYA";
  int n;
  cin >> n;
  while (n--)
  {
    string a;
    cin >> a;
    int count = 0;

    int j = 0;

    while (s != a)
    {
      int i = j;
      if (s[i] == a[i])
      {
        j++;
      }
      else if (s[i] != a[i])
      {
        if (a[i] == 'Z')
          a[i] = 'A';
        else
          a[i] = a[i] + 1;
        count++;
      }
    }

    cout << count << endl;
  }
} 
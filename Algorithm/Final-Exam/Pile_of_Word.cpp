#include <bits/stdc++.h>
using namespace std;
int main()
{
  int t;
  cin >> t;
  while(t--)
  {
    string s1, s2;
    cin >> s1 >> s2;
    bool flag = true;
    if(s1.size() != s2.size()) flag = false;
    else
    {
      sort(s1.begin(), s1.end());
      sort(s2.begin(), s2.end());

      if(s1 != s2) flag = false;
    }
    if(flag)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }
  return 0;
}
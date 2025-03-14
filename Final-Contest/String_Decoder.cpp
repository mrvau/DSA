#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while(t--)
  {
    string a;
    cin >> a;
    string s;

    for (int i = 1; i < a.size(); i += 2)
    {
      int n = a[i] - '0';
      for (int j = 0; j < n; j++)
      {
        s.push_back(a[i - 1]);
      }
    }

    cout << s << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  int s = n / 3;
  int a[s];
  for (int i = s - 1; i >= 0; i--)
  {
    a[i] = n;
    n -= 3;
  }

  int pref[s];
  pref[0] = a[0];
  for (int i = 1; i < s; i++)
  {
    pref[i] = pref[i - 1] + a[i];
  }
  while(q--)
  {
    int l, r;
    cin >> l >> r;
    l = l - 1;
    r = r - 1;
    int left = abs(pref[l / 3] - l);
    int right = abs(pref[r / 3] - r);
    cout << (left + right) - abs(l - r) << endl;
  }
  return 0;
}
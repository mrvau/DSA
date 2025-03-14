#include <bits/stdc++.h>
using namespace std;
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;
  vector<int> a(n);
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }
  long long int pref[n];
  pref[0] = a[0];
  for(int i = 1; i<n; i++)
  {
    pref[i] = pref[i - 1] + a[i];
  }
  while(q--)
  {
    int l, r;
    cin >> l >> r;
    l = l-1;
    r = r -1;
    if(l==r) cout << a[l] << endl;
    else if(l == 0) cout << pref[r] << endl;
    else cout << pref[r] - pref[l-1] << endl;
  }
  return 0;
}
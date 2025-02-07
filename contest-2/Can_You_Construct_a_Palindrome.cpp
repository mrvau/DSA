#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  map<char, int> mp;
  for(auto i : s)
  {
    mp[i]++;
  }
  int missing = 0;
  bool palindrome = true;
  for(auto i = mp.begin(); i != mp.end(); i++)
  {
    if(i->second == n) break;
    if(i->second % 2 != 0) missing++;
  }
  if(missing > k) palindrome = false;
  if(palindrome) cout << "YES" << endl;
  else cout << "NO" << endl;
  return 0;
}
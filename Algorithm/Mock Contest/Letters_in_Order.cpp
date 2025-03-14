#include <bits/stdc++.h>
using namespace std;
int main()
{
  string s;
  cin >> s;
  sort(s.begin(), s.end());
  int freq[26] = {0};
  for(int i = 0; i < s.size(); i++)
  {
    int c = s[i] - 'a';
    freq[c]++;
  }

  string b;

  for(int i = 0; i < 26; i++)
  {
    if(freq[i] != 0)
    {
      b.push_back(i + 'a');
    }
  }
  sort(b.begin(), b.end());
  cout << b << endl;
  return 0;
}
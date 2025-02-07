#include <bits/stdc++.h>
using namespace std;

int mx(string s)
{
  map<string, int> m;
  stringstream ss(s);
  string word;

  while (ss >> word)
  {
    m[word]++;
  }

  int maxWord = 0;
  for (auto i = m.begin(); i != m.end(); i++)
  {
    maxWord = max(maxWord, i->second);
  }
  return maxWord;
}

int main()
{
  int n;
  cin >> n;
  cin.ignore();
  while(n--)
  {
    map<string, int> m;

    string s;
    getline(cin, s);
    
    int maxWord = mx(s);

    stringstream ss(s);
    string word;
    while(ss >> word)
    {
      m[word]++;
      if(m[word] == maxWord)
      {
        cout << word << " " << m[word] << endl;
        break;
      }
    }
  }

  

  return 0;
}
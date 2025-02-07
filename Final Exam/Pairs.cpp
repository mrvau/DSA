#include <bits/stdc++.h>
using namespace std;

class cmp
{
  public:
    bool operator()(pair<string, int> a, pair<string, int> b)
    {
      if(a.first == b.first)
      {
        return a.second < b.second;
      }
      else
      {
        return a.first > b.first;
      }
    }
};

int main()
{
  int n;
  cin >> n;
  priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;

  while(n--)
  {
    int x;
    string s;
    cin >> s >> x;
    pq.push({s, x});
  }
  while(!pq.empty())
  {
    cout << pq.top().first << " " << pq.top().second << endl;
    pq.pop();
  }

  return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> bookCode(n);
  for(int i = 0; i < n; i++)
  {
    cin >> bookCode[i];
  }
  int target;
  cin >> target;
  
  int in = -1;
  for(int i = 0; i < n; i++)
  {
    if(bookCode[i] == target)
    {
      in = i;
    }
  }
  cout << in << endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <climits>

using namespace std;

void find_possible_n()
{
  int K;
  cin >> K;
  string S;
  cin >> S;
  int M = S.length();
  int s = 0;
  for (char ch : S)
  {
    if (ch == 'S')
      s++;
  }

  vector<int> prefix(M + 1, 0);
  for (int i = 0; i < M; i++)
  {
    prefix[i + 1] = prefix[i] + (S[i] == 'S' ? 1 : 0);
  }

  set<int> valid;

  // Check N = M case
  bool possible_N_M = true;
  for (int m = 1; m < M; m++)
  {
    int current_s = prefix[m];
    int remaining = M - m;
    if (current_s + remaining < K)
    {
      possible_N_M = false;
      break;
    }
  }
  if (possible_N_M)
  {
    valid.insert(M);
  }

  // Check N > M case
  if (s < K)
  {
    int max_lower = INT_MIN;
    for (int m = 1; m < M; m++)
    {
      int current_s_m = prefix[m];
      int candidate = K - current_s_m + m;
      if (candidate > max_lower)
      {
        max_lower = candidate;
      }
    }
    int upper = (K - s) + (M - 1);
    int lower = max(max_lower, M + 1);
    if (lower <= upper)
    {
      for (int n = lower; n <= upper; n++)
      {
        valid.insert(n);
      }
    }
  }

  // Output the sorted list
  if (valid.empty())
  {
    cout << -1 << endl;
  }
  else
  {
    for (auto it = valid.begin(); it != valid.end(); it++)
    {
      if (it != valid.begin())
        cout << " ";
      cout << *it;
    }
    cout << endl;
  }
}

int main()
{
  find_possible_n();
  return 0;
}
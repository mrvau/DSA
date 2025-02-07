#include <bits/stdc++.h>
using namespace std;

void insert_heap(vector<int> &v, int val)
{
  v.push_back(val);

  int child_idx = v.size() - 1;

  while (child_idx != 0)
  {
    int parent_idx = (child_idx - 1) / 2;
    if (v[parent_idx] < v[child_idx])
      swap(v[parent_idx], v[child_idx]);
    else
      break;
    child_idx = parent_idx;
  }
}

void delete_heap(vector<int> &v)
{
  cout << v[0] << " Deleted -> ";
  v[0] = v.back();
  v.pop_back();
  int curr_idx = 0;

  while (true)
  {
    int left_idx = (curr_idx * 2) + 1;
    int right_idx = (curr_idx * 2) + 2;
    int left_val = INT_MIN, right_val = INT_MIN;
    if (left_idx < v.size())
      left_val = v[left_idx];
    if (right_idx < v.size())
      right_val = v[right_idx];

    if (left_val >= right_val && left_val > v[curr_idx])
    {
      swap(v[left_idx], v[curr_idx]);
      curr_idx = left_idx;
    }
    else if (right_val > left_val && right_val > v[curr_idx])
    {
      swap(v[right_idx], v[curr_idx]);
      curr_idx = right_idx;
    }
    else
    {
      break;
    }
  }
}

void print(vector<int> v)
{
  for (int i : v)
  {
    cout << i << " ";
  }
  cout << endl;
}

int main()
{
  int n;
  cin >> n;
  vector<int> v;
  for(int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    insert_heap(v, x);
  }

  print(v);
  delete_heap(v);
  print(v);
  delete_heap(v);
  print(v);
  delete_heap(v);
  print(v);
  delete_heap(v);
  print(v);
  delete_heap(v);
  print(v);
  return 0;
}
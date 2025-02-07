#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int val;
  Node *left;
  Node *right;
  Node(int val)
  {
    this->val = val;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *input()
{
  int val;
  cin >> val;

  Node *root;

  if (val == -1)
    root = NULL;
  else
    root = new Node(val);

  queue<Node *> q;
  if (root)
    q.push(root);
  while (!q.empty())
  {
    Node *p = q.front();
    q.pop();

    int l, r;
    cin >> l >> r;

    Node *newLeft, *newRight;
    if (l == -1)
      newLeft = NULL;
    else
      newLeft = new Node(l);
    if (r == -1)
      newRight = NULL;
    else
      newRight = new Node(r);

    p->left = newLeft;
    p->right = newRight;

    if (p->left)
      q.push(p->left);
    if (p->right)
      q.push(p->right);
  }
  return root;
}

void leafNodes(Node* root, vector<int> &v)
{
  if(!root) return;
  if(!root->left && !root->right)
  {
    v.push_back(root->val);
    return;
  }
  leafNodes(root->left, v);
  leafNodes(root->right, v);
}

bool comp(int a, int b)
{
  return a > b;
}

int main()
{
  Node *root = input();
  vector<int> v;
  leafNodes(root, v);
  sort(v.begin(), v.end(), comp);
  for(int i : v)
  {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}
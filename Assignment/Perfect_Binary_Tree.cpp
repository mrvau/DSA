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

// using recursive function

bool isPerfect(Node *root)
{
  if (!root)
    return true;
  if ((root->left && !root->right) || (!root->left && root->right))
    return false;

  bool l = isPerfect(root->left);
  bool r = isPerfect(root->right);

  return l && r;
}

// using formula (2^maxDepth - 1) == number of nodes

int height(Node *root)
{
  if (!root)
    return 0;
  if (!root->left && !root->right)
    return 1;

  int l = height(root->left);
  int r = height(root->right);

  return max(l, r) + 1;
}

int nodeCount(Node *root)
{
  if (!root)
    return 0;
  int l = nodeCount(root->left);
  int r = nodeCount(root->right);

  return l + r + 1;
}

int main()
{
  Node *root = input();
  int h = height(root);

  int n = nodeCount(root);

  if (pow(2, h) - 1 == n)
  {
    cout << "YES" << endl;
  }
  else
  {
    cout << "NO" << endl;
  }
  return 0;
}
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

void print_level_value(Node* root, int x)
{
  queue<pair<Node*, int>> q;
  if(root) q.push({root, 0});
  while(!q.empty())
  {
    pair<Node*,int> p = q.front();
    q.pop();
    Node* node = p.first;
    int level = p.second;

    if(level == x)
    {
      cout << node->val << " ";
    }
    else if(level > x)
    {
      return;
    }

    if(node->left) q.push({node->left, level + 1});
    if(node->right) q.push({node->right, level + 1});
  }
}

int height(Node* root)
{
  if(!root) return 0;
  if(!root->left && !root->right) return 0;

  int l = height(root->left);
  int r = height(root->right);

  return max(l, r) + 1;
}

int main()
{
  Node *root = input();
  int x;
  cin >> x;
  if(x > height(root))
  {
    cout << "Invalid" << endl;
  }
  else
  {
    print_level_value(root, x);
  }
  return 0;
}
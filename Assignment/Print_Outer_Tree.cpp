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

void print_left(Node* root)
{
  if(!root) return;
  if(root->left) print_left(root->left);
  else if(root->right) print_left(root->right);

  cout << root->val << " ";
}
void print_right(Node *root)
{
  if (!root)
    return;
  cout << root->val << " ";
  if (root->right)
    print_right(root->right);
  else if (root->left)
    print_right(root->left);
}

int main()
{
  Node* root = input();
  if(root->left)
    print_left(root->left);
  cout << root->val << " ";
  if(root->right)
    print_right(root->right);
  return 0;
}
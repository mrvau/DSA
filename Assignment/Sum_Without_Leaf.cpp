#include <bits/stdc++.h>
using namespace std;

class Node
{
  public:
    int val;
    Node * left;
    Node * right;
  Node(int val)
  {
    this -> val = val;
    this -> left = NULL;
    this -> right = NULL;
  }
};

Node* input()
{
  int val;
  cin >> val;

  Node* root;

  if(val == -1) root = NULL;
  else root = new Node(val);

  queue<Node*> q;
  if(root) q.push(root);
  while(!q.empty())
  {
    Node* p = q.front();
    q.pop();

    int l, r;
    cin >> l >> r;

    Node* newLeft, *newRight;
    if(l == -1) newLeft = NULL;
    else newLeft = new Node(l);
    if(r == -1) newRight =  NULL;
    else newRight = new Node(r);

    p->left = newLeft;
    p->right = newRight;

    if(p->left) q.push(p->left);
    if(p->right) q.push(p->right);
  }
  return root;
}

int sum_without_leaf(Node* root)
{
  if(!root) return 0;
  if(!root->left && !root->right) return 0;

  int l = sum_without_leaf(root->left);
  int r = sum_without_leaf(root->right);

  return l + r + root->val;
}

int main()
{
  Node* root = input();
  cout << sum_without_leaf(root) << endl;
  return 0;
}
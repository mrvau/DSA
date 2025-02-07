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

  Node* root = NULL;
  if(val != -1) root = new Node(val);

  if(!root) return NULL;

  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node* p = q.front();
    q.pop();

    int l, r;
    cin >> l >> r;

    Node* newLeft = (l == -1) ? NULL : new Node(l);
    Node* newRight = (r == -1) ? NULL : new Node(r);

    p->left = newLeft;
    p->right = newRight;

    if(p->left) q.push(p->left);
    if(p->right) q.push(p->right);
  }

  return root;
}

void print(Node* root)
{
  queue<Node*> q;
  if(root) q.push(root);
  while(!q.empty())
  {
    Node* p = q.front();
    q.pop();

    cout << p->val << " ";

    if(p->left) q.push(p->left);
    if(p->right) q.push(p->right);
  }
}

bool isFound(Node* root, int val)
{
  if(!root) return false;
  if(val == root->val) return true;
  if(val < root->val) return isFound(root->left, val);
  if(val > root->val) return isFound(root->right, val);
}

void insert(Node* &root, int val)
{
  if(!root)
  {
    root = new Node(val);
    return;
  }
  if(root->val > val)
  {
    if(!root->left)
      root->left = new Node(val);
    else
      insert(root->left, val);
  }
  else
  {
    if(!root->right)
      root->right = new Node(val);
    else
      insert(root->right, val);
  }
}

Node* array_to_BST(int a[], int l, int r)
{
  if(l > r) return NULL;
  int mid = (l + r) / 2;
  Node* root = new Node(a[mid]);

  Node* leftRoot = array_to_BST(a, l, mid - 1);
  Node* rightRoot = array_to_BST(a, mid + 1, r);

  root->left = leftRoot;
  root->right = rightRoot;

  return root;
}

int main()
{
  int n;
  cin >> n;
  int a[n];
  for(int i = 0; i < n; i++)
  {
    cin >> a[i];
  }

  Node* root = array_to_BST(a, 0, n - 1);
  print(root);
  return 0;
}
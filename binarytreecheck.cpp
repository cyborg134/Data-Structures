#include<iostream>
using namespace std;
#define COUNT 10  
struct Node
{
  int data;
  Node* left;
  Node* right;
}*root=NULL;

Node*  getNewNode(int x)
{
  Node* temp = (Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->left = NULL;
  temp->right = NULL;
  return temp;
}

Node* insert(Node* root,int x)
{
  
  if(root==NULL)
  {
    return getNewNode(x);
  }
  if(x < root->data)
  {
    root->left = insert(root->left,x);
  }
  if(x > root->data)
  {
    root->right = insert(root->right,x);
  }
  return root;
}

bool IsBstUtil(Node* root,int minvalue, int maxvalue)
{
  if(root==NULL)
    return true;
  //cout<<minvalue<<" "<<root->data<<" "<<maxvalue;
  if(root->data > minvalue && root->data < maxvalue && IsBstUtil(root->left,minvalue,root->data) && IsBstUtil(root->right,root->data,maxvalue))
  {
    return true;
  }
  else
    return false;
}

bool IsbinarysearchTree(Node* root)
{
  return IsBstUtil(root,INT_MIN,INT_MAX);
}

int main()
{
  root = insert(root,20);
  insert(root,10);
  insert(root,30);
  insert(root,15);
  insert(root,25);
  insert(root,7);
  insert(root,4);
  insert(root,2);
  cout<<"Isbinary search Tree: "<<IsbinarysearchTree(root);
}

#include<iostream>
#include<stdlib.h>
#include<queue>
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

int FindMin(Node* root)
{
  if(root==NULL)
  {
    return -1;
  }
  Node* temp = root;
  while(temp->left!=NULL)
  {
    temp=temp->left;
  }
  return temp->data;
}

int FindMax(Node* root)
{
  if(root==NULL)
  {
    return -1;
  }
  Node* temp = root;
  while(temp->right!=NULL)
  {
    temp=temp->right;
  }
  return temp->data;
}

int height(Node* root)
{
  if(root==NULL)
    return -1;
  
  return max(height(root->left),height(root->right))+1;
}

void levelorder(Node* root)
{
  if(root==NULL)
    return;
  queue<Node*> q;
  q.push(root);
  while(!q.empty())
  {
    Node* current = q.front();
    cout<<current->data<<"\t";
    if(current->left!=NULL) q.push(current->left);
    if(current->right!=NULL) q.push(current->right);
    q.pop();
  }
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
  //print2D(root);
  int min = FindMin(root);
  cout<<min<<"\n";
  int max = FindMax(root);
  cout<<max<<"\n";
  int h = height(root);
  cout<<"height of the tree: "<<h<<"\n";
  levelorder(root);
}


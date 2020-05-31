#include<iostream>
#include<stdlib.h>
#include<queue>
#include<bits/stdc++.h>
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

Node* FindMin(Node* root)
{
  if(root==NULL)
  {
    return NULL;
  }
  Node* temp = root;
  while(temp->left!=NULL)
  {
    temp=temp->left;
    //cout<<temp->data<<"\n";
  }

  return temp;
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
Node* FindNode(Node* root,int x)
{
  if(root==NULL)
    return NULL;
  else if(x < root->data) root= FindNode(root->left,x);
  else if(x > root->data) root= FindNode(root->right,x);
  return root;
  
}

Node* getsuccessor(Node* root, int data)
{
  Node* current = FindNode(root,data);
  if(current->right !=NULL)
  {
    return FindMin(current->right);
  }
  else
  {
    Node* successor = NULL;
    Node* ancestor = root;
    while(current!=ancestor)
    {
      if(current->data < ancestor->data)
      {
        successor = ancestor;
        ancestor = ancestor->left;
      }
      else
      {
        ancestor = ancestor->right;
      }
    }
    return successor;
  }
  
}
int main()
{
  root = insert(root,20);
  insert(root,16);
  insert(root,7);
  insert(root,30);
  insert(root,19);
  insert(root,5);
  insert(root,8);
  insert(root,17);
  insert(root,24);
  insert(root,32);
  insert(root,31);
  //insert(root,39);
  //print2D(root);
  //int min = FindMin(root);
  //cout<<min<<"\n";
  int max = FindMax(root);
  //cout<<max<<"\n";
  int h = height(root);
  //cout<<"height of the tree: "<<h<<"\n";
  //levelorder(root);
  //cout<<"Isbinary search Tree: "<<IsbinarysearchTree(root);
  levelorder(root);
  cout<<"\n";
  //Delete(root,10);
  //levelorder(root);
  Node* node = getsuccessor(root,32);
  if(node==NULL)
  {
    cout<<"no inorder successor\n";
  }
  else
    cout<<node->data;
}


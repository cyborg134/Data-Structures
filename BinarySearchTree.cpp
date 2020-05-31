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
void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
  
    // Increase distance between levels  
    space += COUNT;  
  
    // Process right child first  
    print2DUtil(root->right, space);  
  
    // Print current node after space  
    // count  
    cout<<endl;  
    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    cout<<root->data<<"\n";  
  
    // Process left child  
    print2DUtil(root->left, space);  
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{  
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}

int main()
{
  root = insert(root,20);
  insert(root,10);
  insert(root,30);
  insert(root,15);
  insert(root,25);
  print2D(root);
  
}


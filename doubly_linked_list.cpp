#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
    Node* prev;
}*head=NULL;

Node* create_newnode(int x)
{
  Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  temp->prev = NULL;
  return temp;
}
void insert_athead(int x)
{
  Node* temp = create_newnode(x);
  if(head==NULL)
  {
    head = temp;
    return;
  }
  temp->next = head;
  head->prev = temp;
  head = temp;
}
void insert_attail(int x)
{
  Node* temp = create_newnode(x);
  if(head==NULL)
  {
    head=temp;
    return;
  }
  Node* temp1= head;
  while(temp1->next!=NULL)
  {
    temp1=temp1->next;
  }
  temp1->next=temp;
  temp->prev=temp1;
  
}
void print()
{
  Node* temp = head;
  while(temp!=NULL)
  {
    cout<<temp->data;
    temp=temp->next;
  }
}

int main()
{
  int i,n;
  cout<<"enter 5 inputs:";
  for(i=0;i<5;i++)
  {
    cin>>n;
    insert_attail(n);
  }
  print();
}

#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
}*head=NULL;

void insert_begin(int d)
{
    Node* temp=(Node*)malloc(sizeof(struct Node));
    /*if(*head==NULL)
    {
        temp->data=d;
        temp->next=NULL;
    }*/
    temp->data=d;
    temp->next=head;
    head=temp;
}

void print()
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data;
        temp=temp->next;
    }
    cout<<"\n";
}

void recusrsive_reverse_print(Node *temp)
{
  if(temp == NULL)
    return;
  recusrsive_reverse_print(temp->next);
  cout<<temp->data;
}

int main()
{
  int n,value;
  cout<<"Number of input variables are ";
  cin>>n;
  for(int i=0;i<n;i++)
  {
      cin>>value;
      insert_begin(value);
  }
  print();
  recusrsive_reverse_print(head);
}

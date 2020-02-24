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
void insert_n_position(int p,int d)
{
    int i=2;
    Node* temp=head;
    Node* temp1=(Node*)malloc(sizeof(struct Node));
    temp1->data=d;
    temp1->next=NULL;
    while(i!=p)
    {
        i++;
        temp=temp->next;

    }
    temp1->next=temp->next;
    temp->next=temp1;
}
void delete_node_n_position(int p)
{
    int i=2;
    Node* temp=head;
    while(i!=p)
    {
        i++;
        temp=temp->next;
    }
    Node* temp2=temp;
    temp=temp->next;
    temp2->next=temp->next;
    delete(temp);
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
  insert_n_position(4,9);
  print();
  delete_node_n_position(3);
  print();
}

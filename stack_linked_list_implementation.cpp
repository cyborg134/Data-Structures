#include<iostream>
#include<stdlib.h>
using namespace std;
struct Node
{
    int data;
    Node* next;
}*head=NULL;

void push(int x)
{
  struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = head;
  head = temp;
}
void pop()
{
  struct Node* temp = head;
  head = head->next;
  delete(temp);
}
int Top()
{
  return head->data;
}

bool isempty()
{
  if(head==NULL)
    return true;
  return false;
}
int main()
{
  cout<<"IS stack empty:"<< isempty()<<"\n";
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  pop();
  cout<<"Top of the stack is:"<< Top()<<"\n";
  cout<<"IS stack empty: "<<isempty();
}

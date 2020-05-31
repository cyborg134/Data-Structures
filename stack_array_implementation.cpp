#include<iostream>
#include<stdlib.h>
#define MAX_SIZE 4
using namespace std;

int arr[MAX_SIZE];
int top = -1;

void push(int n)
{
  if(top==MAX_SIZE-1)
  {
    cout<<"stack is full:overflow condition";
    return;
  }
  arr[++top]=n;
}
void pop()
{
  if(top==-1)
  {
    cout<<"stack is empty:underflow condition";
    return;
  }
  top--;
}
int Top()
{
  return arr[top];
}
int main()
{
  push(1);
  push(2);
  push(3);
  push(4);
  //push(5);
  pop();
  int n = Top();
  cout<<n;
}

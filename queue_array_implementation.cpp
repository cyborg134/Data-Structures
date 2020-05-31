#include<iostream>
#define N 5
using namespace std;

int arr[N];
int front=-1;
int rear=-1; 

void push(int x)
{
  if((rear+1)%N == front)
  {
    cout<<"queue is full\n";
    return;
  }
  if(front==-1&&rear==-1)
  {
    front=rear=0;
  }
  arr[rear] = x;
  rear = (rear+1)%N;
  
}
void pop()
{
  if(front==-1 && rear==-1)
  {
    cout<<"\nQueue is empty\n";
    return;
  }
  else if(front==rear)
  {
    front=rear=-1;
  }
  else
  {
    front = (front+1)%N;
  }
    
}
int Front()
{
  if(front == -1)
		{
			cout<<"Error: cannot return front from empty queue\n";
			return -1; 
		}
  return arr[front];
}
int main()
{ 
  push(1);
  push(2);
  cout<<"rear value is "<<rear<<"\n";
  pop();
  int a = Front();
  cout<<"front of the queue is: "<<a<<"\n";
  pop();
  int b = Front();
  cout<<"front of the queue is: "<<b<<"\n";
  push(3);
  int d = Front();
  cout<<"front of the queue is: "<<d;

}

#include<iostream>
#include<stdlib.h>
#include<string>
#include<stack>
using namespace std;

bool validate_pair(char a, char b)
{
  if(a=='{'&&b=='}') return true;
  else if(a=='['&&b==']') return true;
  else if(a=='('&&b==')') return true;
  else
    return false;
}

bool validate_balance(string exp)
{
  stack<char> s;
  for(int i=0;i<exp.length();i++)
  {
    if(exp[i]=='{'||exp[i]=='['||exp[i]=='(')
    {
      s.push(exp[i]);
    }
    else if(exp[i]=='}'||exp[i]==']'||exp[i]==')')
    {
      if(s.empty() || !validate_pair(s.top(),exp[i]))
      {
        return false;
      }
      else
        s.pop();
    }
  }
  return s.empty()?true:false;

}

int main()
{
  string expression;
  cout<<"Enter an expression\n";
  cin>>expression;
  if(validate_balance(expression))
    cout<<"Balanced\n";
  else
    cout<<"Unbalanced";

}

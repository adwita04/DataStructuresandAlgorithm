/*
Name: Adwita Deshpande
Roll no: 2203303

Name: Lakshay Khurana
Roll no: 2203312

Name: Aditya Sehra
Roll no: 2203302

Name: Arnav Sadhwani
Roll no: 2204207
*/

#include <iostream>
#include <string>
#define _MAXSIZE_ 20
using namespace std;

class Stack //class stack
{
    //private variables
    int top; 
    char* stack;
    public:
    Stack()
    {
        top = -1;
        stack = new char[_MAXSIZE_];
    }
    
    bool IsFull()
    {
        if(top+1 == _MAXSIZE_)
            return true;
        return false;
    }

    void push (char item)
    {
        if(IsFull())
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        top = top+1;
        stack[top]=item;
    }
    bool IsEmpty ()
    {
        if(top == -1)
            return true;
        return false;
    }
    char pop ()
    {
        if(IsEmpty())
        {
            cout<<"Stack underflow"<<endl;
            return -1;
        }
        char ans = stack[top];
        top--;
        return ans;
    }
    char peek ()
    {
        if(IsEmpty())
        {
            cout<<"Stack Empty"<<endl;
            return -1;
        }
        return stack[top];
    }
};

int main()
{
    string s;
    cout<<"Enter expression: "; 
    cin>>s;
    Stack stack;
    for(int i=0; i<s.length();i++) //parenthisis checker
    {
        if(s[i]=='{' || s[i]=='(' || s[i]=='<' || s[i]=='[')
        {
            stack.push(s[i]);
        }
        else if(s[i]== '}' || s[i]== ')' || s[i]== '>' || s[i]==']')
        {
            if(stack.IsEmpty())
            {
                cout<<"Not a valid parenthesis"<<endl;
                return 0;
            }
            char popped = stack.pop();
            if((s[i] == '}' && popped == '{' ) || (s[i] == ']' && popped == '[' ) || (s[i] == ')' && popped == '(' ) || (s[i] == '>' && popped == '<' ))
            {
                continue;
            }
            else
            {
                cout<<"Not a valid parenthesis"<<endl;
                return 0;
            }
        }
    }
    if(stack.IsEmpty())
        cout<<"Valid parenthesis"<<endl;
}
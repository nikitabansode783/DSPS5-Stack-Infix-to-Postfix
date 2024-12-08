#include<iostream>
#include<string>
#include<stack>
using namespace std;

int pre(char op)
{
    if(op == '+'|| op== '-') return 1;
    if(op == '*'||op== '/') return 2;
    if(op == '^') return 3;
    return 0;
}

string ITP(string infix)
{
    stack<char>s;
    string postfix;
    for(char c: infix)
    {
        if(isalnum(c))
        {
            postfix+=c;
        }
        else if (c=='(')
        {
            s.push(c);
        }
        else if(c==')')
        {
            while(s.top()!='(')
            {
                postfix+=s.top();
                s.pop();
            }s.pop();
        }
        else
        {
            while(!s.empty() && pre(s.top())>= pre(c))
            {
               postfix+=s.top();
                s.pop(); 
            }s.push(c);
        }
    }
    while(!s.empty())
    {
      postfix+=s.top();
       s.pop();   
    }
    return postfix;
}

int main()
{
    string infix;
    cout<<"Enter the infix expression: ";
    cin>>infix;
    cout<<"Postfix expression: "<<ITP(infix)<<endl;
    return 0;
}

#include<iostream>
#include<stack>
#include<string>
using namespace std;

int prec(char op)
{
if (op=='+' || op == '-')
{
  return 1; 
}
else if  (op=='*' || op == '/')
{
  return 2; 
}
else if(op=='^')
{
  return 3; 
}
return 0;
}

bool isOp(char c)
{
return ( c=='+'|| c=='-'||c=='*'||c=='/'||c=='^');
}

string infixToPostfix(string infix)
{
    stack<char> s;
    string Postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        char c = infix[i];
        if (isalnum(c))
        {
            Postfix += c;
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')') 
        {
            while (!s.empty() && s.top() != '(')
            {
                Postfix += s.top();
                s.pop();
            }
            if (!s.empty()) 
            {
                s.pop(); 
            }
        }
        else if (isOp(c))
        {
            while (!s.empty() && prec(s.top()) >= prec(c))
            {
                Postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty())
    {
        Postfix += s.top();
        s.pop();
    }
    return Postfix;
}

int main()
{
  string infix;
  cout<< "Enter an infix expression : ";
  cin>> infix;
  string Postfix =infixToPostfix(infix);
  cout<< "Postfix Expression : "<< Postfix<<endl;
  return 0;
}

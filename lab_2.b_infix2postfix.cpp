#include<iostream>
#include<string.h>
#define Max 20

using namespace std;

class Stack
{
    public:
        char arr[Max];
        int top;

        Stack()
        {
            top = -1;
        }

        bool isEmpty()
        {
            if (top < 0)
                return 1;
            else
                return 0;
        }

        bool isFull()
        {
            if (top == Max - 1)
                return 1;
            else
                return 0;
        }

        void push( char c)
        {
            // if (!isFull)
            arr[++top] = c;                
        }

        char pop()
        {
            // if (!isEmpty)
            // {
                return arr[top--];
            // }
            // else 
            // {
            //     cout << "stack empty" << endl;
            //     return '0';
            // }        
        }
            
};

bool isoperator(char c)
{
    if (c == '$' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')')
        return 1;
    else
        return 0;
}
            

int precedency(char c)
{
    if ( c == '$')
        return 3;
    else if ( c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;    
}

int main()
{
    Stack s;
    string infix, postfix;
    cout << "Enter infix expression: " << endl;
    cin >> infix;
    int i =  infix.length();

    for ( int j = 0; j < i; j++)
    {
        if ((infix[j] >= 'a' && infix[j] <= 'z') || (infix[j] >= 'A' && infix[j] <= 'Z'))
        {
            postfix += infix[j];
        }

        if (isoperator(infix[j]))
        {
            if (s.isEmpty() || infix[j] == '(' || infix[j] == '$')
                s.push(infix[j]);
            
            else if (infix[j] == ')')
            {
                while (s.arr[s.top] != '(')
                    postfix += s.pop();

                s.pop();
            }

            else if (precedency( infix[j] ) <= precedency ( s.arr[s.top] ) )
            {
                postfix += s.pop();
            }

            else
                s.push(infix[j]);
        }

    }

    while (!s.isEmpty())
    {
        postfix += s.pop();
    }

    cout << "Postfix expression is: " << endl;
    cout << postfix << endl;

    return 0;

}



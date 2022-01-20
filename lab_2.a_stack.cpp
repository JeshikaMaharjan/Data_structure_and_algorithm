// Array implementation of stack

#include <iostream>
#define Max 6
using namespace std;

class Stack
{
    int top;

    public:
        int items[Max];

        Stack()
        {
           top = -1;
           for ( int i = 0; i < Max; i ++)
           {
               items[i] = 0;
           }
        }

        
        void push()
        {
            if ( top >= (Max -1))
                cout << "Stack overflow" << endl;
            else
            {
                cout << "Enter elements: " << endl;
                cin >>  items[ ++top ];
                
            }
            
        }

        void pop()
        {
            if ( top < 0)
                cout << "Stack underflow" << endl;

            else
            {
                cout << "Popped item is: " <<  items[top--] << endl;
                items[top+1] = 0;
            }
                
            
        }

        void traverse()
        {
            if(top < 0)
                cout << "Stack is empty." << endl;
            else
            {
                cout << "The contents of stack are: " << endl;                     
                int i = 0;
                while  (i < Max)
                {
                    if ( items[i] != 0)
                    {
                        cout << "Stack [" << i << "]: " << this-> items[i] << endl;
                    }
                    i++;
                }
            }
        }
};

int main()
{
    class Stack s;
    int choice;
    do
    {

        cout << "Enter your choice: " << endl;
        cout << "1. PUSH " <<"\t 2. POP " << "\t 3.TRAVERSE" << "\t 4.Exit" << endl;
        cin >> choice;
        
        if (choice == 1)
            s.push();

        else if (choice == 2)
           s.pop();

        else if (choice == 3)
            s.traverse();

        else if (choice == 4)
            break;
        else
            cout << "Invalid choice!! " << endl;
    }while (choice != 4);
    
    return 0;
}




            


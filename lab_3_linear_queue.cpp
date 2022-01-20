//Array implementation of linear queue

#include<iostream>
#define Max 20
using namespace std;

class Queue
{
    public:
        int front,rear,item[Max];

    Queue()
    {
        rear = -1;
        front = 0;
        
        for( int i = 0; i < Max-1; i++ )
        {
            item[i] = '\0';
        }
    }

    bool isEmpty()
    {
        if( rear < front)
            return 1;
        else
            return 0;
    }

    bool isFull()
    {
        if ( rear == Max-1)
            return 1;
        else
            return 0;
    }

    void enqueue(int new_item)
    {
        if (isFull())
        {
            cout << "Queue Full" << endl;
            exit(1);
        }

        else
        {
            item[++rear] = new_item;
        }
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue empty" << endl;
            exit(1);
        }

        else
        {
            int x = item[front++];
            item[front-1] = '\0';
            return x;

        }
    }

    void traverse()
    {
        for (int i = front; i <= rear; i++ )
        {
            cout << item[i] << endl;
        }
    }
};         

int main()
{
    int choice, new_item;
    Queue q;
    do
    {
        cout << "Enter choice:" << endl
            << "1.Enqueue" << "\t2.Dequeue" << "\t3.Traverse" << "\t4.Exit" << endl;
        cin >> choice;
        
        switch( choice )
        {
            case 1:
            {
                cout << "Enter item:" << endl;
                cin >>new_item;
                q.enqueue(new_item);
                break;
            }

            case 2:
            {
                cout << "The dequeued item is: " << q.dequeue() << endl;
                break;
            }

            case 3:
            {
                if (q.isEmpty())
                {
                    cout << "Empty." << endl;
                    break;
                }

                else
                {
                    cout << "Contents of queue: " << endl;
                    q.traverse();
                    break;

                }
            }

            default:
            {
                cout << "Invalid choice." << endl;
                break;
            }
        }
    }while( choice != 4);

    return 0;
}
    
   
//Array implementation of circular queue

#include<iostream>
#define Max 6
using namespace std;

class Queue
{
    public:
        int front,rear,item[Max];

    Queue()
    {
        rear = front = Max -1;     
                
    }

    bool isEmpty()
    {
        if( rear == front)
            return 1;
        else
            return 0;
    }

    bool isFull()
    {
        if ( front == (rear +1) % Max)
            return 1;
        else
            return 0;
    }

    void enqueue(int new_item)
    {      
        rear = ((rear +1) % Max);
        item[rear] = new_item;        
    }

    int dequeue()
    {       
        front = ((front + 1) % Max);            
        return item[front];     
    }
        

    void traverse()
    {        
        int i = front;
        while ( i != rear)
        {
            i = (i + 1) % Max;
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
                if (q.isFull())
                    cout << "Queue full." << endl;
                else
                    q.enqueue(new_item);
                break;
            }

            case 2:
            {
                if (q.isEmpty())
                    cout << "Queue empty" << endl;
                else
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
    
   
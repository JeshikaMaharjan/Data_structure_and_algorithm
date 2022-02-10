//Doubly linked list

#include<iostream>
// #define NULL 0
using namespace std;

struct Node
{
    int info;
    struct Node *next;
    struct Node *prev;
};
Node *head = NULL;


Node* getNode()
{
    Node *newnode = new Node;
    return newnode;
}

void insert_beginning( int data )
{
    Node *new_node = getNode();
    if (head == NULL)
    {
        new_node -> next = NULL;
        new_node -> prev = NULL;
        new_node -> info = data;
        head = new_node;
        return;

    }
    new_node -> info = data;
    new_node -> next = head;
    head->prev=new_node;    
    new_node->prev=NULL;
    head = new_node;
}

void insert_sp_pos( int pos, int data )
{
    if ( head == NULL)
    {
        cout << "VOID INSERTION." << endl;
    }
    else
    {
        Node *new_node = getNode();
        new_node -> info =data;
        Node *temp = head;
        for (int i = 1; i < pos-1; i++)
        {
            temp = temp -> next;

        }
        new_node -> next = temp -> next;
        temp->next = new_node;
        new_node -> prev = temp;
        new_node -> next -> prev = new_node;
    }
}


void insert_end ( int data )
{
    Node *new_node = getNode();
    new_node -> info = data;
    new_node -> next = NULL;
    if ( head == NULL)
    {
        new_node -> prev = NULL;
        head = new_node;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp->next!=NULL)
        {
            temp = temp->next; // increment temp
        }
        new_node -> prev = temp;
        temp -> next = new_node;
    }  
}

int total_nodes()
{
    int i = 0;
    if (head == NULL)
    {
        return 0;
    }
    else
    {
        Node *temp = head;
        while ( temp->next != NULL)
        {
            i++;
            temp = temp->next;
        }

        return i;
    }
}       


void delete_beginning()
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY" << endl;
        return;
    }
    else
    {
        Node *temp = head;
        cout << "Info of deleted node: " << head->info << endl;
        head = head -> next;
        head->prev = NULL;
        delete (temp);
    }
}

void delete_sp_pos( int pos)
{
    Node *temp = head;
    Node *t = head;
    int total = total_nodes();
    if (head == NULL)
    {
        cout << "VOID DELETION." << endl;
        return;
    }
    else if ( pos > total ) 
    {
        cout << "POSITION SHOULD BE SMALLER THAN TOTAL NUMBER OF NODES PRESENT." << endl;
    }
    else
    {
        for (int i = 1; i < pos; i++)
        {
            t = temp;
            temp = temp -> next;
        }
        cout << "Info in deleted node is: " << temp -> info << endl;        
        t -> next = temp -> next;
        temp -> next -> prev = t;
        delete (temp);
    }
}

void delete_end()
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "VOID DELETION" << endl;
    }
    else if( head -> next == NULL)
    {
        cout << "Info of deleted item is: " << head->info << endl;
        delete  (temp);
        head = NULL;
    }
    else
    {
        while( temp -> next -> next != NULL)
        {
            temp = temp -> next;
        }
        cout << "Info of deleted node is: " << temp ->next -> info << endl;
        delete (temp -> next);
        temp -> next = NULL; 
    } 
}

void display()
{
    Node *temp = head;
    if ( head == NULL)
    {
        cout << "Empty" << endl;
    }
    else
    {
        int i = total_nodes();
        cout << "The contents are: " << endl;
        for ( int j = 0; j <= i; j++)
        {
            cout << "[" << j+1 << "]" << temp->info << endl;
            temp = temp -> next;
        }
        cout << endl;
    }
}

int main()
{
    int choice , data , pos;
    do
    {
        cout << "Enter your choice: " << endl;
        cout << "1. Insert at beginning." << "\n2. Insert at specific position." << "\n3. Insert at end."
             << "\n4. Delete at beginning." << "\n5. Delete at specific position." << "\n6. Delete at end." 
             <<"\n7. Display" << "\n8. Exit" << endl;
        cin >>choice;
        if (choice == 1 || choice == 2 || choice == 3)
        {
            cout << "Enter data to insert: ";
            cin >> data;
        }

        switch (choice)
        {
            case 1:
            {
                insert_beginning(data);
                break;
            }

            case 2:
            {
                cout << "Enter position: ";
                cin >> pos;
                insert_sp_pos( pos, data);
                break;
            }

            case 3:
            {
                insert_end( data );
                break;
            }

            case 4:
            {
                delete_beginning();
                break;
            }

            case 5:
            {
                cout << "Enter position: ";
                cin >> pos;
                delete_sp_pos(pos);
                break;
            }

            case 6:
            {
                delete_end();
                break;
            }

            case 7:
            {
                display();
                break;
            }

            case 8:
            {
                exit(0);
            }              
                
            default:
            {
                cout << "Invalid choice!!" << endl;
                exit(0);
            }
            
        }
        
    }while( true );

    return 1;
}





















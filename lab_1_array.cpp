//Array manipulations

#include<iostream>
#define Max 6

using namespace std;
int arr_1[Max], arr_2[Max], arr_3[20];
int size_1, size_2;

void Insert(int x)
{
    int i , n;
    cout << "\n Enter the no. of elements to insert: ";
    cin >> n;
    size_2 = n;
    if (n >= Max)
        cout << " \n Exceeds the array size!! ";
    else
    {
        cout << "\n Enter elements: ";
        if (x == 1)
        {
            for (i = 0; i < n; i++)
            {
                cin >> arr_1[i];
            }
        }
        if (x == 2)
        {
            for (i = 0; i < n; i++)
            {
                cin >> arr_2[i];
            }

        }

    }
}

void Delete(int x)
{
    cout << "\n The contents of array are: " << endl;
    int i ,j ,  pos;
    if (x == 1)
    {
        for (i = 0; i < size_1 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_1[i] << "\t";
        }
        cout << endl;
    }
    if ( x == 2)
    {
        for (i = 0; i < size_2 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_2[i] << "\t";
        }
        cout << endl;
    }

    cout << "\n Enter the position you want to delete: ";
    cin >> pos;
    if (x == 1)
    {
        while ( pos < size_1)
        {
            arr_1[pos -1] = arr_1[ pos];
            pos++; 
        }
        size_1--;

    }
       
    if ( x == 2)  
    {
        while ( pos < size_2)
        {
            arr_2[pos -1] = arr_2[ pos];
            pos++; 
        }
        size_2--;
    }     
    
    cout << "\n The contents after deletion are: " << endl;
    if (x == 1)
    {
        for (i = 0; i < size_1 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_1[i] << "\t";
        }
        cout << endl;
    }
    if ( x == 2)
    {
        for (i = 0; i < size_2 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_2[i] << "\t";
        }
        cout << endl;
    }

}

    
void Update(int x)
{
    cout << "\n The contents of array are: " <<endl;
    int i , pos;

    if ( x == 1)
    {
        for (i = 0; i < size_1 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_1[i] << "\t";
        }
        cout << endl;
    }
    if ( x == 2)
    {
        for (i = 0; i < size_2 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_2[i] << "\t";
        }
        cout << endl;
    }

    cout << "\n Enter the position you want to update: " << endl;
    cin >> pos;
    cout << " Enter the new element: " << endl;
    if ( x == 1)
        cin >> arr_1[pos];
    if ( x == 2)
        cin >> arr_2[pos];

    cout << " The contents after updating are: " << endl;
    if (x == 1)
    {
        for (i = 0; i < size_1 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_1[i] << "\t";
        }
        cout << endl;
    }
    if (x == 2)
    {
        for (i = 0; i < size_2 ; i ++)
        {
            cout << " arr[" << i << "]: " << arr_2[i] << "\t";
        }
        cout << endl;

    }

}

void Traverse(int x)
{
    int i;
    cout << " The contents of array are: " << endl;
    if (x == 1)
    {
        for (i = 0; i < size_1; i++ )
        {
            cout << arr_1[i] << "\t"; 
        }
        cout << endl;
    }
    if ( x == 2)
    {
        for (i = 0; i < size_2; i++ )
        {
            cout << arr_2[i] << "\t"; 
        }
        cout << endl;
    }

}

void Merge()
{
    int i  ,j ,k = size_1;
    for (i = 0; i < size_1; i++)
    {       
        arr_3[i] = arr_1[i];        
    }
    for ( j = 0; j < size_2; j++)
    {
        arr_3[k] = arr_2[j];
        k++;
    }     
  
    cout << " The merged array is :" << endl;
    for ( i = 0; i < (size_1 + size_2); i ++)
    {
        cout << " arr_3[" << i << "]: " << arr_3[i] << "\t"; 
    }
}    

int main()
{    
    int choice;
    int i , n, c;

    cout << "\n Creating first array i.e arr_1 " << endl;
    cout << " Enter the no. of elements to insert: " <<endl;
    cin >> n;
    size_1 = n;
    if (n >= Max)
        cout << " Exceeds the array size!! " << endl;
    else
    {
        cout << " Enter elements: " <<endl;
        for (i = 0; i < n; i++)
        {
            cin >> arr_1[i];
        }
    }

    do
    {
        cout << "\n Enter your choice: ";
        cout << "\n 1. Insert " << "\n 2. Delete" << "\n 3. Update" << "\n 4. Traverse" << "\n 5. Merge" << "\n 6. Exit" << endl;
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                cout << " Press 1 for arr_1" << "\n Press 2 for arr_2" << endl;
                cin >> c;
                Insert(c);
                break;
            }
            
            case 2:
            {
                cout << " Press 1 for arr_1" << "\n Press 2 for arr_2" << endl;
                cin >> c;
                Delete(c);
                break;
            }
            
            case 3:
            {
                cout << " Press 1 for arr_1" << "\n Press 2 for arr_2" << endl;
                cin >> c;
                Update(c);
                break;
            }

            case 4:
            {
                cout << " Press 1 for arr_1" << "\n Press 2 for arr_2" << endl;
                cin >> c;
                Traverse(c);
                break;
            }

            case 5:
            {
                Merge();
                break;
            }

            case 6:
                break;

            default:
            {
                cout << "Invalid input!!" <<endl;
                
            }
        }
    } 
    while (choice != 6);
    return 0;
}



    

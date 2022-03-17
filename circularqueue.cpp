#include <iostream>
using namespace std;
int cirq[100],front = -1, rear = -1, n=100;
void insert(int val) 
{
    if ((front == 0 && rear == n-1) || (front == rear+1)) 
    {
        cout<<"Queue Overflow \n";
        return;
    }
    if (front == -1) 
    {
        front = 0;
        rear = 0;
    } 
    else 
    {
        if (rear == n - 1)
        rear = 0;
        else
        rear = rear + 1;
    }
    cirq[rear] = val ;
}
void remove() 
{
    if (front == -1) 
    {
        cout<<"Queue Underflow\n";
        return ;
    }
    if (front == rear) 
    {
        front = -1;
        rear = -1;
    } 
    else 
    {
        if (front == n - 1)
        front = 0;
        else
        front = front + 1;
    }
}
void display() 
{
    int f = front, r = rear;
    if (front == -1) 
    {
        cout<<"\n\t***Queue is empty***\n";
        return;
    }
    if (f <= r) 
    {
        while (f <= r)
        {
            cout<<cirq[f]<<" ";
            f++;
        }
    } 
    else 
    {
        while (f <= n - 1) 
        {
            cout<<cirq[f]<<" ";
            f++;
        }
        f = 0;
        while (f <= r) 
        {
            cout<<cirq[f]<<" ";
            f++;
        }
    }
    cout<<endl;
}
int main() 
{

    int ch, val;
    cout<<"\n*******************************************\n";
    cout<<"1. Insert\n2. Delete\n3. Exit";
    cout<<"\n*******************************************\n";
    do 
    {
        cout<<"Enter your choice : ";
        cin>>ch;
        cout<<"*******************************************\n";
        switch(ch) 
        {
            case 1:
            cout << "***Circular Queue Before Insertion***\n"; 
            display();
            cout<<"\nEnter to insert in Circular Queue : ";
            cin>>val;
            insert(val);
            cout << "\n***Circular Queue After Insertion***\n";
            display();
            break;
            case 2:
            cout << "***Circular Queue Before Deletion***\n"; 
            display();
            remove();
            cout << "\n***Circular Queue After Deletion***\n";
            display();
            break;
            case 3: cout<<"\t*** Exit ***"<<endl;
            break;
            default: cout<<"Invalid choice"<<endl;
        }
        cout<<"*******************************************\n"; 
    } 
    while(ch != 3);
    return 0;
}
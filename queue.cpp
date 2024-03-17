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
#define _MAXSIZE_ 10
using namespace std;

class queue
{
    public:
    int *arr;
    int head,tail;
    int size;

    queue() //constructor
    {
        arr = new int[_MAXSIZE_];
        head = -1;
        tail = -1;
        size = 0;
    }
    bool isFull() //to check if queue is full
    {
        if(size == _MAXSIZE_)
            return true;
        return false;
    }

    void enqueue(int item) //insert element
    {
        if(isFull()){
            cout<<"Queue Full";
            return ;
        }
        tail=(tail+1)%_MAXSIZE_; 
        arr[tail]=item; 
        size++; 
        if(head==-1){
            head++;
        }
    }

    bool isEmpty() //to check if queue is empty
    { 
        return size==0;
    }

    int dequeue() //delete element from queue
    {
        if(isEmpty())
            return -1;
        int ans = arr[head];
        head = (head+1)%_MAXSIZE_;
        size--;
        return ans;
    }

    int peek() //return the topmost element
    {
        if(isEmpty())
            return -1;
        return arr[head];
    }

    void print() //print queue
    {
        for(int i=head; i<=tail; i++)
        {
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};

int main()
{
    queue q;
    while(true)
    {
        cout<<"Menu: \n";
        cout<<"1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit the program\n";
        int choice;
        cin>>choice;
        switch(choice)
        {
            case 1:
                int elem;
                cout<<"Enter number to be inserted: ";
                cin>>elem;
                q.enqueue(elem);
                q.print();
                break;
            case 2:
                cout<<"Item removed: "<<q.dequeue()<<endl;
                q.print();
                break;
            case 3:
                cout<<"Item on the top of the queue: "<<q.peek()<<endl;
                break;
            case 4:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
}
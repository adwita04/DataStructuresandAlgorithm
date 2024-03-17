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
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

void push (int item, Node ** head_ptr) //INSERT AT HEAD
{
    Node* temp = new Node(item);
    if (*head_ptr == NULL)
    {
        *head_ptr = temp;
        return;
    }
    temp->next = *head_ptr;
    *head_ptr = temp;
}

bool IsEmpty (Node ** head_ptr)
{
    return *head_ptr == NULL;
}

int pop (Node ** head_ptr) //delete at head
{
    if (IsEmpty(head_ptr))
        return -1;
    Node* temp = *head_ptr;
    int ans = (*head_ptr)->data;
    *head_ptr = (*head_ptr)->next;
    delete temp;
    return ans;
}

int peek (Node ** head)
{
    if (IsEmpty(head))
        return -1;
    return (*head)->data;
}

void print(Node **head) //to print stack
{
    Node* temp = *head;
    cout<<"Stack: ";
    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    int choice=0;
    while(true)
    {
        cout<<"Menu: \n";
        cout<<"1. Push\n2. Pop\n3. Peek\n4. Exit the program\n";
        cin>>choice;
        switch(choice)
        {
            case 1:
                int elem;
                cout<<"Enter number to be pushed: ";
                cin>>elem;
                push (elem, &head);
                print(&head);
                break;
            case 2:
                cout<<"Item popped : "<<pop(&head)<<endl;
                print(&head);
                break;
            case 3:
                cout<<"Item on the top of the stack: "<<peek(&head)<<endl;
                break;
            case 4:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
}
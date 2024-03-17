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

class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data = data;
        next = NULL;
    }
};

int linkedListLength(Node** head) //function to calculate length of linkedlist
{
    int length = 0;
    Node* temp = *head;
    while(temp != NULL)
    {
        temp = temp->next;
        length++;
    }
    return length;
}

bool InsertAtPosition(Node ** head, int index, int elem) //function to insert an element in linkedlist
{
    int length = linkedListLength(head);
    if(index == 0)
    {
        Node* temp = new Node(elem);
        temp->next = *head;
        *head = temp;
        return true;
    }
    if(index <= length)
    {
        Node* temp = *head;
        Node* insert = new Node(elem);
        int i=0;
        while(i != index-1)
        {
            temp=temp->next;
            i++;
        }
        insert->next = temp->next;
        temp->next = insert;
        return true;
    }
    else
        return false;
    
}

int DeleteAtPosition(Node ** head, int index)//function to delete an element in linkedlist
{
    int length = linkedListLength(head);
    if(index == 0)
    {
        Node* temp = *head;
        int ans = (*head)->data;
        *head = (*head)->next;
        delete temp;
        return ans;
    }
    if(index <= length)
    {
        Node* temp = *head;
        int i=0;
        while(i != index-1)
        {
            temp=temp->next;
            i++;
        }
        Node *del = temp->next;
        int ans = del->data;
        temp->next = del->next;
        delete del;
        return ans;
    }
    else
        return -1;
}

void CreateList(Node ** head) //function to create linkedlist
{
    int len;
    cout<<"Enter length of linked list: ";
    cin>>len;
    int i = 0,data;
    while(i<len)
    {
        cout<<"Element "<<i+1<<" : ";
        cin>>data;
        InsertAtPosition(head,i,data);
        i++;
    }
    return;
}
void display(Node* &head) //function to print linkedlist
{
    Node* temp = head;
    while(temp !=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

void reverse(Node** head) //function to reverse linkedlist
{
    Node* prev = NULL;
    Node* curr = *head;
    Node* next =NULL;
    while(curr !=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    *head = prev;
}

int main()
{
    Node* head = NULL;
    int n;
    CreateList(&head);
    cout<<"Original list : "<<endl;
    display(head);
    cout<<"Enter the index of element to be deleted: ";
    cin>>n;
    cout<<"Element deleted is: "<<DeleteAtPosition(&head, n-1)<<endl; //to display output of delete at position function..n-1 to convert 0 indexing to 1 indexing 
    display(head);
    reverse(&head);
    cout<<"Reversed list : "<<endl;
    display(head);
}
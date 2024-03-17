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
    Node* prev;

    Node(int data) {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};

void InsertAtPosition(Node** head, int index, int elem) //function to insert an element in linkedlist
{
    Node* newNode = new Node(elem);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
        return;
    }

    Node* temp = *head;

    int length = 0;
    do {
        temp = temp->next;
        length++;
    } while (temp != *head);

    if (index == 0) {
        newNode->next = *head;
        newNode->prev = temp->prev;
        temp->prev->next = newNode;
        temp->prev = newNode;
        *head = newNode;
    } else {
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
}

void CreateList(Node** head) //function to create linkedlist
{
    int len;
    cout << "Enter length of linked list: ";
    cin >> len;
    int i = 0, data;
    while (i < len) {
        cout << "Element " << i + 1 << " : ";
        cin >> data;
        InsertAtPosition(head, i, data);
        i++;
    }
}

void Print(Node** head) //function to print linkedlist
{
    Node* temp = *head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != *head);
    cout << endl;
}

int Visit (Node ** head, int distance) //Visit function
{
    Node* temp = *head;
    if (distance >= 0)
    {
        for(int i=0; i<distance;i++)
        {
            temp = temp->next;
        }
        *head = temp;
        return temp->data;
    }
    else 
    {
        for(int i=distance; i<0;i++)
        {
            temp = temp->prev;
        }
        *head = temp;
        return temp->data;
    }
}

int main() {
    Node* head = NULL;
    CreateList(&head);
    Print(&head);
    int n;
    cout<<"Current: "<<head->data<<endl;
    for(int i=0; i<5; i++)
    {
        cout<<"Enter the relative distance: ";
        cin>>n;
        cout<<endl<<"Current: "<<Visit(&head,n)<<endl;
    }
    return 0;
}
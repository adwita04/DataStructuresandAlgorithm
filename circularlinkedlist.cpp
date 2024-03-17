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

void InsertAtPosition(Node** head, int index, int elem) //function to insert an element in linkedlist
{
    Node* newNode = new Node(elem);

    if (*head == NULL) {
        *head = newNode;
        newNode->next = newNode;
        return;
    }

    Node* temp = *head;

    int length = 1;
    do {
        temp = temp->next;
        length++;
    } while (temp->next != *head);

    if (index < 0 || index > length) {
        cout << "Invalid index for insertion." << endl;
        delete newNode;
        return;
    }

    if (index == 0) {
        newNode->next = *head;
        temp->next = newNode;
        *head = newNode;
    } else {
        temp = *head;
        for (int i = 0; i < index - 1; ++i) {
            temp = temp->next;
        }
        newNode->next = temp->next;
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

int main() 
{
    Node* head = NULL;
    CreateList(&head);
    Print(&head);
    return 0;
}



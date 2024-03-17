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
    if (index == 0) {
        Node* temp = new Node(elem);
        temp->next = *head;
        if (*head != NULL) {
            (*head)->prev = temp;
        }
        *head = temp;
        } 
    else 
    {
        Node* temp = *head;
        Node* insert = new Node(elem);
        int i = 0;
        while (i != index - 1) {
            temp = temp->next;
            i++;
        }
        insert->next = temp->next;
        if (temp->next != nullptr) {
            temp->next->prev = insert;
        }
        temp->next = insert;
        insert->prev = temp;
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

void display(Node* head) //function to print linkedlist
{
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void sortedInsert(Node** head_ref, Node* newNode) //to insert an elemngt in a sorted manner
{
    Node* current;
    if (*head_ref == NULL)
        *head_ref = newNode;
    else if ((*head_ref)->data >= newNode->data)
        InsertAtPosition(head_ref, 0, newNode->data); 

    else 
    {
        current = *head_ref;
        int index = 0;
        while (current->next != NULL && current->next->data < newNode->data)
        {
            current = current->next;
            index++;
        } 
        InsertAtPosition(head_ref, index+1, newNode->data);
    }
}
 

void insertionSort(Node** head_ref) //insertion sort function
{
    Node* sorted = NULL; //to store the sorted linked list
    Node* current = *head_ref;
    while (current != NULL) {
        Node* next = current->next;
        current->prev = current->next = NULL; //separate a node from linked list
        sortedInsert(&sorted, current); //insert the node in a sorted manner
        current = next;
    }
    *head_ref = sorted;
}

int main() {
    Node* head = nullptr;
    CreateList(&head);
    cout << "Original list : " << endl;
    display(head);

    insertionSort(&head);
    cout << "Sorted list : " << endl;
    display(head);

    return 0;
}

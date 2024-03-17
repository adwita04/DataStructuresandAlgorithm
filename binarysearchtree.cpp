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

class Node
{
    public:
    Node* right;
    Node* left;
    int data;
    Node(int data)
    {
        this->data = data;
        right = NULL;
        left = NULL;
    }

};

Node* add (int item, Node* root)
{
    if(root==NULL)
    {
        Node* newnode = new Node(item);
        return newnode;
    }
    if(root->data > item)
        root->left =  add(item, root->left);
    else
        root->right = add(item, root->right);
    return root;
}

Node* search (int item, Node* root)
{
    if(root==NULL || root->data == item)
        return root;
    if(root->data > item)
        return search(item, root->left);
    else
        return search(item, root->right);
}

Node* deleteitem(int item, Node* root)
{
    if(root == NULL)
        return root;
    if(root->data > item)
        root->left =  deleteitem(item, root->left);
    else if(root->data < item)
        root->right = deleteitem(item, root->right);
    else
    {
        Node* temp;
        if(root->right == NULL)
        {
            temp = root->left;
            delete root;
            return temp;
        }
        else if(root->left == NULL)
        {
            temp = root->right;
            delete root;
            return temp;
        }
        else
        {
            temp = root->right;
            Node* temp1=root;
            while(temp->left != NULL){
                temp1= temp;
                temp = temp->left;
            }
            if (temp1 != root)
                temp1->left = temp->right;
            else
                temp1->right = temp->right;
            root->data = temp->data;
            delete temp;
        }
    }
    return root;
}

void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
    
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
    
}

void print(Node* root)
{
    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl;
    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl;
    cout<<"Postorder: "<<endl;
    postorder(root);
    cout<<endl;
}

int main()
{
    Node* root = NULL;
    while(true)
    {
        cout<<"Menu: \n";
        cout<<"1. Add\n2. Search\n3. Delete\n4. Print\n5. Exit the program\n";
        int choice,elem;
        cin>>choice;
        
        switch(choice)
        {
            case 1:
                cout<<"Enter number to be added: ";
                cin>>elem;
                root = add(elem,root);
                break;
            case 2:
                cout<<"Enter number to be searched: ";
                cin>>elem;
                if(search(elem,root))
                    cout<<"Item found at "<<search(elem,root)<<endl;
                else
                    cout<<"Item not found"<<endl;
                break;
            case 3:
                cout<<"Enter number to be deleted: ";
                cin>>elem;
                root = deleteitem(elem,root);
                break;
            case 4:
                print(root);
                break;
            case 5:
                return 0;
            default:
                cout<<"Enter a valid choice"<<endl;
                break;
        }
    }
}
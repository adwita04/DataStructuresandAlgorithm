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
  int key;
  Node *left;
  Node *right;
  int height;
};

// Calculate height
int height(Node *N) {
  if (N == NULL)
    return 0;
  return N->height;
}

// New node creation
Node *newNode(int key) {
  Node *node = new Node();
  node->key = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return (node);
}

// Rotate right
Node *rightRotate(Node *y) {
  Node *x = y->left;
  Node *T2 = x->right;
  x->right = y;
  y->left = T2;
  y->height = max(height(y->left), height(y->right)) +1;
  x->height = max(height(x->left),height(x->right)) +1;
  return x;
}

// Rotate left
Node *leftRotate(Node *x) {
  Node *y = x->right;
  Node *T2 = y->left;
  y->left = x;
  x->right = T2;
  x->height = max(height(x->left),height(x->right)) +1;
  y->height = max(height(y->left),height(y->right)) +1;
  return y;
}

// Get the balance factor of each node
int getBalanceFactor(Node *N) {
  if (N == NULL)
    return 0;
  return height(N->left) - height(N->right);
}

// Insert a node
Node *insertNode(Node *node, int key) {
  if (node == NULL)
    return (newNode(key));
  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  node->height = 1 + max(height(node->left),height(node->right));
  int balanceFactor = getBalanceFactor(node);
  if (balanceFactor > 1) {
    if (key < node->left->key) {
      return rightRotate(node);
    } else if (key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  }
  if (balanceFactor < -1) {
    if (key > node->right->key) {
      return leftRotate(node);
    } else if (key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  }
  return node;
}

//Search a node
Node* search (int item, Node* root)
{
    if(root==NULL || root->key == item)
        return root;
    if(root->key > item)
        return search(item, root->left);
    else
        return search(item, root->right);
}

// Delete a node
Node *deleteNode(Node *root, int key) {
  if (root == NULL)
    return root;
  if (key < root->key)
    root->left = deleteNode(root->left, key);
  else if (key > root->key)
    root->right = deleteNode(root->right, key);
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
            root->key = temp->key;
            delete temp;
        }
    }
  root->height = 1 + max(height(root->left),height(root->right));
  int balanceFactor = getBalanceFactor(root);
  if (balanceFactor > 1) {
    if (getBalanceFactor(root->left) >= 0) {
      return rightRotate(root);
    } else {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  if (balanceFactor < -1) {
    if (getBalanceFactor(root->right) <= 0) {
      return leftRotate(root);
    } else {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

// Print the tree
void inorder(Node* root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->key<<" ";
    inorder(root->right);
    
}

void preorder(Node* root)
{
    if(root == NULL)
        return;
    cout<<root->key<<" ";
    preorder(root->left);
    preorder(root->right);
    
}

void postorder(Node* root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->key<<" ";
    
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
    Node *root = NULL;
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
                root = insertNode(root,elem);
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
                root = deleteNode(root,elem);
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
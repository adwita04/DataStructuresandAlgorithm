/*
Name: Adwita Deshpande
Roll no.: 2203303
Branch: MnC 2022
*/

#include <stdio.h>
#include <stdbool.h>
#define MAX_SIZE 20 

void insertion_sort(char a[], int size);
void bubble_sort(char a[], int size);
void swap(char a[],int i, int j);
void printarray(char a[],int size);
void union_(char a[], char b[],char c[], int size1, int size2);
bool ispresent(char c[],char val, int pos);

int main()
{
    int size1,size2;
    printf("Enter size of array 1: "); //input size n1
    scanf("%d",&size1);
    char a[size1];
    if(size1<MAX_SIZE) //check if size is less than MAX_SIZE
    {
        printf("Enter elements: \n");
        for(int i=0; i<size1; i++) //taking character input in array 1
        {
            scanf(" %c",&a[i]);
        }
        printf("Sorting array 1 by bubble sort: \n");
        bubble_sort(a,size1); //calling bubble sort function
    }
    printf("\nEnter size of array 2: "); //input size n2
    scanf("%d",&size2);
    char b[size2];
    if(size2<MAX_SIZE) //check if size n2 is less than MAX_SIZE
    {
        printf("Enter elements: \n");
        for(int i=0; i<size2; i++) //taking character input in array 2
        {
            scanf(" %c",&b[i]);
        }
        printf("Sorting array 2 by insertion sort: \n");
        insertion_sort(b,size2); //calling insertion sort function
    }
    printf("\nUnion of two arrays:\n");
    char c[size1+size2]; //Array to store the union
    union_(a,b,c,size1,size2); //calling union function (since 'union' is a keyword in C, I have named the function 'union_')
}


void printarray(char a[],int size) //function to print array
{
    for(int i=0; i<size; i++)
    {
        printf("%c ",a[i]);
    }
}

void swap(char a[],int i, int j) //function to swap elements
{
    char temp= a[i];
    a[i] = a[j];
    a[j] = temp;
}

void bubble_sort(char a[], int size) //bubble sort algorithm
{
    for(int i=0;i<size-1;i++)
    {
        for(int j=0;j<size-i-1;j++)
        {
            if(a[j]>a[j+1])
                swap(a,j,j+1);
        }
        printarray(a,size);
        printf("\n");
    }
}

void insertion_sort(char a[], int size) //insertion sort algorithm
{
    int i, key, j;
    for (i = 1; i < size; i++) 
    {
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        printarray(a,size);
        printf("\n");
    }
}

void union_(char a[], char b[],char c[], int size1, int size2)
{
    int i=0,j=0,k=0,inp; //set all counters to 0;
    while(i<size1 && j<size2)
    {
        if(a[i]==b[j]) //check if the elements are equal
        {
            inp=a[i]; //store value in variable
            i++;j++; //increment both arrays
        }
        else if (a[i]<b[j]) //check inequality
        {
            inp=a[i]; //store the smaller value
            i++; //increment counter 
        }
        else if (a[i]>b[j])
        {
            inp=b[j];
            j++;
        }

        if(!ispresent(c,inp,k)) //check if input is already stored in array to avoid repeats
        {
            c[k]=inp;
            k++;
        }
    }
    while(i<size1) //for remaining elements
    {
        if(!ispresent(c,a[i],k))
        {
            c[k]=a[i];
            i++;k++;
        }
    }
    while(j<size2)
    {
        if(!ispresent(c,b[j],k))
        {
            c[k]=b[j];
            j++;k++;
        }
    }
    printarray(c,k); // print elements
    printf("\n");
}

bool ispresent(char c[],char val, int pos) //to check if the character is already present in array
{
    for(int i=0;i<pos;i++) 
    {
        if(c[i]== val)
            return true;
    }
    return false;
}

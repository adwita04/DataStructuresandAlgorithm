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
#include<cstdlib>
using namespace std;

class maxHeap {
private:
    int *items; 
    int size;   
    
    int sift_down(int index) {
        while (index <= (size - 1) / 2) 
        {
            int l_child = find_lchild(index);
            int r_child = find_rchild(index);
            int largest = index;

            // Find the largest among the current node and its children
            if (l_child <= size - 1 && items[l_child] > items[largest]) {
                largest = l_child;
            }

            if (r_child <= size - 1 && items[r_child] > items[largest]) {
                largest = r_child;
            }

            if (largest != index) {
                swap(items[index], items[largest]);
                index = largest;
            } else {
                break;
            }
        }

        return index;
    }

    int sift_up(int index) {
        while (index > 0) 
        {
            int parent = find_parent(index);
            if (items[parent] < items[index]) {
                swap(items[index], items[parent]);
                index = parent;
            } else {
                break;
            }
        }

        return index;
    }

    int find_parent(int index) {
        return (index - 1) / 2;
    }
    int find_lchild(int index) {
        return 2 * index + 1;
    }
    int find_rchild(int index) {
        return 2 * index + 2;
    }
    bool is_valid_index(int index) {
        return index >= 0 && index <= size - 1;
    }

public:
    void heapify() {
        for (int i = (size - 1) / 2; i >= 0; i--) {
            sift_down(i);
        }
    }

    int get_max() {
        if (size == 0) {
            throw runtime_error("Heap is empty");
        }
        return items[0];
    }

    void insert(int item) {
        items[size] = item;
        size++;
        sift_up(size - 1);
    }

    int delete_max() {
        if (size == 0) {
            throw runtime_error("Heap is empty");
        }

        int max = items[0];
        items[0] = items[size - 1];
        size--;
        sift_down(0);

        return max;
    }
    //Constructor
    maxHeap(int sz, int arr[]) {
        items = new int[sz]; 
        size = 0;            

        for (int i = 0; i < sz; i++) {
            insert(arr[i]);
        }
    }
};

//Perform heapsort
void heapSort(int arr[], int n) {
    maxHeap heap(n, arr); 

    for (int i = n - 1; i >= 0; i--) {
        arr[i] = heap.delete_max();
    }
}


int main() 
{
    int arr[20];
    for (int i = 0; i < 20; i++) {
        arr[i] = rand() % 100;
    }

    cout << "Unsorted array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Performing heap sort on the array
    heapSort(arr, 20);

    // Printing the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < 20; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
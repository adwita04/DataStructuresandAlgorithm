/*
Adwita Deshpande 
2203303
Mathematics and Computing

Aditya Sehra
2203302
Mathematics and Computing
*/

#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    int i,j,k;
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = (r + l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}
int main() {
    
    int k; 
    cout<<"Enter value of k: ";
    cin>>k;
    double sum_ci=0,sum_ci2 = 0;
    cout<<"(i,2^i,T(2^i),i^2*2^i,ci)" << endl;
    for (int i = 1; i <= k; i++) {
        int n = pow(2, i);
        int* arr = new int[n];
        for (int j = 0; j < n; j++) {
            arr[j] = rand();
        }
        double executionTime = measureTime(arr, n);
        double ci = executionTime / (n * log2(n));
        
        cout <<"("<< i << "," << n << "," << executionTime << "," << i  * n << "," << ci <<")"<< endl;
        if(i>5)
        {
            sum_ci += ci;
            sum_ci2 += ci*ci;
        }
        delete[] arr;
    }
    double expectation = sum_ci/(k-5);
    double variance = (sum_ci2/(k-5)) - expectation*expectation;
    cout<< "\n";
    cout << "Expectation of ci : "<< expectation <<endl;
    cout << "Variance of ci : "<<variance<<endl;
    return 0;
}
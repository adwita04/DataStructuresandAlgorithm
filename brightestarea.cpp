/*
Name: Adwita Deshpande
Roll no.: 2203303
*/

#include<bits/stdc++.h>
using namespace std;

class Subarray{
public:
    int start, end, sum;
    Subarray(int start,int end, int sum)
    {
        this->start = start;
        this->end = end;
        this->sum = sum;
    }
    Subarray(){}
};

vector<vector<int>> subtract128(vector<vector<int>> Matrix)
{
    for(int i =0 ; i< Matrix.size();i++)
    {
        for (int j =0 ; j< Matrix[0].size();j++)
        {
            Matrix[i][j] -= 128; 
        }
    }
    return Matrix;
}

int maxSumIfEndsWith(vector<int> a,int i, int& startIndex)
{
    if (i == 0)
    {
        startIndex = 0;
        return a[0];
    }
    if (a[i]> maxSumIfEndsWith(a,i-1,startIndex)+a[i])
    {
        startIndex = i;
        return a[i];
    }
    else
        return maxSumIfEndsWith(a,i-1,startIndex)+a[i];
}
Subarray maxSubarray(vector<int> arr, int n)
{
    Subarray sumArray[n];
    for (int i=0;i<n;i++)
    {
        int startIndex = -1;
        int sum = maxSumIfEndsWith(arr,i, startIndex);
        Subarray ans(startIndex,i,sum);
        sumArray[i] = ans;
    }
    int max = 0;
    Subarray maxSum;
    for(int i =0; i< n; i++)
    {
        if(sumArray[i].sum > max)
        {
            max = sumArray[i].sum;
            maxSum = sumArray[i];
        }
    }
    return maxSum;
}
int maxSubMatrix(vector<vector<int>> matrix){
    int m = matrix.size();
    int n = matrix[0].size();
    int sumMax = 0;
    int startIndex = 0;
    int endIndex = 0;
    int bottomIndex = 0;

    for(int i = 0; i<m; i++){
        vector<int> colSum(n,0);
        for(int j = i; j<m; j++){
            for(int k = 0; k < n; k++){
                colSum[k]+=matrix[j][k];
            }
            Subarray temp = maxSubarray(colSum,n);
            if(temp.sum > sumMax){
                sumMax = temp.sum;
                startIndex = temp.start;
                endIndex = temp.end;
                bottomIndex = j;
            }
        }

    }

    cout<<"Maximum Sum Submatrix: "<<endl;
    for(int i = startIndex; i<=bottomIndex; i++){
        for(int j = startIndex; j<=endIndex; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    return sumMax;
}

int main(){
    vector<vector<int> > matrix = {{2, -8, -1, -4, -20},
                                    {-5, -3, 4, 2, 1},
                                    {3, 8, 12, 1, 3},
                                    {-4, -2, 1, 6, -6}}; 

    int ans = maxSubMatrix(matrix);
    cout<<"Maximum sum: "<<ans;
}

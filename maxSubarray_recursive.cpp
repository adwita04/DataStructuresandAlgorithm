#include<iostream>
using namespace std;

int a[] = {-4,5,-2,15,-8,-11,8,-3,4,-7}; 
int n = 10;

//class to store subarrays and their sum
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

//function to find the subarray of max sum with last position included
int maxSumIfEndsWith(int i, int& startIndex)
{
    if (i == 0)
    {
        startIndex = 0;
        return a[0];
    }
    if (a[i]> maxSumIfEndsWith(i-1,startIndex)+a[i])
    {
        startIndex = i;
        return a[i];
    }
    else
        return maxSumIfEndsWith(i-1,startIndex)+a[i];
}

//function to find subarray with max sum by iteration through all positions as the last position in the above function
Subarray maxSubarray()
{
    Subarray sumArray[n];
    for (int i=0;i<n;i++)
    {
        int startIndex = -1;
        int sum = maxSumIfEndsWith(i, startIndex);
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

int main()
{
    cout<<"Array: {-4,5,-2,15,-8,-11,8,-3,4,-7}"<<endl;
    Subarray ans = maxSubarray();
    cout<<"Max Sum: "<<ans.sum<<endl;
    cout<<"Subarray : ";
    for(int i=ans.start; i<=ans.end; i++)
    {
        cout<<a[i]<<" ";
    }
}


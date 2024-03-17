#include <iostream>
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
};

//function to find the subarray of max sum with last position included
int maxSumEndsWith(int i, int& startIndex)
{
    if (i == 0)
    {
        startIndex = 0;
        return a[0];
    }
    if (a[i]> maxSumEndsWith(i-1,startIndex)+a[i])
    {
        startIndex = i;
        return a[i];
    }
    else
        return maxSumEndsWith(i-1,startIndex)+a[i];
}

//function to find the subarray of max sum with first position included
int maxSumStartsWith(int i, int& endIndex)
{
    if (i == n-1)
    {
        endIndex = n-1;
        return a[n-1];
    }
    if (a[i]> maxSumStartsWith(i+1,endIndex)+a[i])
    {
        endIndex = i;
        return a[i];
    }
    else
        return maxSumStartsWith(i+1,endIndex)+a[i];
}

//function to find max subarray by divide and conquer
Subarray subarrayMax(int start, int end)
{
    if (start == end)
    {
        Subarray ans(start, start, a[start]);
        return ans;
    }

    if(start<end)
    {
        int mid = (start + end)/2;
        Subarray ans1 = subarrayMax(start, mid);
        Subarray ans2 = subarrayMax(mid+1, end);

        int startIndex = -1;
        int sumEndsWith = maxSumEndsWith(mid, startIndex);

        int endIndex = -1;
        int sumStartsWith = maxSumStartsWith(mid+1, endIndex);

        int sumOverMid = sumEndsWith +sumStartsWith;
        Subarray ans3(startIndex, endIndex , sumOverMid);
        cout<<"We are done with the subproblem A["<<start<<"..."<<end<<"]"<<endl;
        
        if (ans1.sum> ans2.sum)
        {
            if(ans3.sum > ans1.sum)
            {
                return ans3;
            }
            return ans1;
        }
        else
        {
            if(ans3.sum>ans2.sum)
            {
                return ans3;
            }
            return ans2;
        }
    }
}


int main()
{
    cout<<"Array: {-4,5,-2,15,-8,-11,8,-3,4,-7}"<<endl;
    Subarray ans = subarrayMax(0,n-1);
    cout<<"Max Sum: "<<ans.sum<<endl;
    cout<<"Subarray : ";
    for(int i=ans.start; i<=ans.end; i++)
    {
        cout<<a[i]<<" ";
    }
}
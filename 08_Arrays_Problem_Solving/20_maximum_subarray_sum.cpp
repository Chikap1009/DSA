#include <bits/stdc++.h>
using namespace std;

int brute_maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i ; j<nums.size() ; j++)
        {
            int tempSum = 0;
            for (int k=i ; k<=j ; k++)
            {
                tempSum += nums[k];
            }
            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

int better_maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN;
    for (int i=0 ; i<nums.size() ; i++)
    {
        int tempSum = 0;
        for (int j=i ; j<nums.size() ; j++)
        {
            tempSum += nums[j];
            if (tempSum > maxSum)
            {
                maxSum = tempSum;
            }
        }
    }
    return maxSum;
}

int optimal_maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, sum = 0;

    for (int i=0 ; i<nums.size() ; i++)
    {
        sum += nums[i];
        maxSum = max(maxSum, sum);
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxSum;
}

int main()
{
    vector<int> v = {5,4,-1,7,8};

    cout << brute_maxSubArray(v) << endl;
    cout << better_maxSubArray(v) << endl;
    cout << optimal_maxSubArray(v) << endl;

    return 0;
}
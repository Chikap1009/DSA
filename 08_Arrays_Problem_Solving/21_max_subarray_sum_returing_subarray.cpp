#include <bits/stdc++.h>
using namespace std;

vector<int> optimal_maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, sum = 0;
    int ansStart = -1, ansEnd = -1;
    int start;

    for (int i=0 ; i<nums.size() ; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += nums[i];
        if (sum > maxSum)
        {
            maxSum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    
    vector<int> ans;
    for (int i = ansStart ; i <= ansEnd ; i++)
    {
        ans.emplace_back(nums[i]);
    }

    return ans;
}

int main()
{
    vector<int> v = {5,4,-1,7,8};
    vector<int> maxi = optimal_maxSubArray(v);

    for (auto x : maxi)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
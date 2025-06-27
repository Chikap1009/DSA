#include <bits/stdc++.h>
using namespace std;

int singleNumber1(vector<int> nums)
{
    map<int,int> mp;

    for (auto x : nums)
    {
        mp[x]++;
    }

    for (auto x : mp)
    {
        if (x.second == 1) return x.first;
    }

    return -1;
}

int singleNumber2(vector<int> nums)
{
    int ans = 0;
    for (int i=0 ; i<=31 ; i++)
    {
        int count = 0;
        for (int j=0 ; j<nums.size() ; j++)
        {
            if ((nums[j]&(1<<i)) != 0) count++;
        }
        if (count%3 != 0) ans |= (1<<i);
    }
    return ans;
}

int singleNumber3(vector<int> nums)
{
    sort(nums.begin(),nums.end());

    for (int i=2 ; i<nums.size() ; i+=3)
    {
        if (nums[i] != nums[i-1]) return nums[i-1];
    }
    return nums[nums.size()-1];
}

int singleNumber4(vector<int> nums)
{
    int ones = 0, twos = 0;

    for (int i=0 ; i<nums.size() ; i++)
    {
        ones = (ones^nums[i])&(~twos);
        twos = (twos^nums[i])&(~ones);
    }

    return ones;
}

int main()
{
    vector<int> nums = {1,2,4,3,2,1,1,2,3,3};

    cout << singleNumber1(nums) << endl;
    cout << singleNumber2(nums) << endl;
    cout << singleNumber3(nums) << endl;
    cout << singleNumber4(nums) << endl;

    return 0;
}
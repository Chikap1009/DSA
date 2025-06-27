#include <bits/stdc++.h>
using namespace std;

bool ls(vector<int>& nums, int ind)
{
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] == ind) return true;
    }
    return false;
}

int brute_longestConsecutive(vector<int>& nums)
{
    int longest = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        int count = 1;
        int x = nums[i];
        while (ls(nums,x+1) == true)
        {
            x++;
            count++;
        }
        longest = max(longest, count);
    }
    return longest;
}

int better_longestConsecutive(vector<int>& nums)
{
    int longest = 0;
    int lastElement = INT_MIN;

    sort(nums.begin(), nums.end());

    int count = 0;

    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] == lastElement+1)
        {
            count++;
        }
        else if (nums[i] != lastElement)
        {
            count = 1;
        }
        lastElement = nums[i];
        longest = max(longest, count);
    }

    return longest;
}

int optimal_longestConsecutive(vector<int>& nums)
{
    unordered_set<int> st;
    int longest = 0;
    for (auto x : nums)
    {
        st.insert(x);
    }
    for (auto it : st)
    {
        if (st.find(it-1) == st.end())
        {
            int count = 1;
            int x = it;
            while (st.find(x+1) != st.end())
            {
                x++;
                count++;
            }
            longest = max(longest,count);
        }
    }
    return longest;
}

int main()
{
    vector<int> v = {100,4,200,1,3,2};

    cout << brute_longestConsecutive(v) << endl;
    cout << better_longestConsecutive(v) << endl;
    cout << optimal_longestConsecutive(v) << endl;

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

void getSubsets(vector<int>& nums, vector<vector<int>>& ans, vector<int>subset = {}, int index = 0)
{
    if (index == nums.size())
    {
        ans.push_back(subset);
        return;
    }

    subset.push_back(nums[index]);
    getSubsets(nums,ans,subset,index+1);
    subset.pop_back();
    getSubsets(nums,ans,subset,index+1);
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    getSubsets(nums,ans);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,3,4};

    vector<vector<int>> ans = subsets(nums);

    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
    
    return 0;
}
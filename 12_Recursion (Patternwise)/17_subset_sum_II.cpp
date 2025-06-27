#include <bits/stdc++.h>
using namespace std;

// ans = {{}}
// void getSubsets(vector<int>& nums, vector<vector<int>>& ans, int index = 0, vector<int> subset = {})
// {
//     if (index == nums.size()) return;

//     for (int i=index ; i<nums.size() ; i++)
//     {
//         if (i>index && nums[i] == nums[i-1]) continue;

//         subset.push_back(nums[i]);
//         ans.push_back(subset);
//         getSubsets(nums,ans,i+1,subset);
//         subset.pop_back();
//     }
// }

// vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//     sort(nums.begin(),nums.end());
//     vector<vector<int>> ans = {{}};
//     getSubsets(nums,ans);
//     return ans;
// }


// ans = {}
void getSubsets(vector<int>& nums, vector<vector<int>>& ans, int index = 0, vector<int> subset = {})
{
    ans.push_back(subset);

    for (int i=index ; i<nums.size() ; i++)
    {
        if (i>index && nums[i] == nums[i-1]) continue;

        subset.push_back(nums[i]);
        getSubsets(nums,ans,i+1,subset);
        subset.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>> ans = {};
    getSubsets(nums,ans);
    return ans;
}

int main()
{
    vector<int> nums = {1,2,2,2,3,3};

    vector<vector<int>> ans = subsetsWithDup(nums);

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
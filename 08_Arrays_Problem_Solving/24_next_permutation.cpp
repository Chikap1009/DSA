#include <bits/stdc++.h>
using namespace std;

void permutation(vector<vector<int>>& ans, vector<int>& nums, int index=0)
{
    if (index == nums.size())
    {
        ans.push_back(nums);
        return;
    }

    for (int i=index ; i<nums.size() ; i++)
    {
        swap(nums[i], nums[index]);
        permutation(ans, nums, index+1);
        swap(nums[i], nums[index]);
    }
}

vector<int> brute_nextPermutation(vector<int>& nums)
{
    vector<vector<int>> ans;
    permutation(ans, nums);
    int ind;
    for (int i=0 ; i<ans.size() ; i++)
    {
        if (ans[i] == nums)
        {
            ind = i;
            break;
        }
    }
    if (ind == ans.size()-1)
    {
        return ans[0];
    }
    else
    {
        return ans[ind+1];
    }
}

vector<int> optimal_nextPermutation(vector<int>& nums)
{
    next_permutation(nums.begin(), nums.end());
    return nums;
}

vector<int> implementation(vector<int>& nums)
{
    int breakpt = -1;
    for (int i=nums.size()-2 ; i>=0 ; i--)
    {
        if (nums[i] < nums[i+1])
        {
            breakpt = i;
            break;
        }
    }
    if (breakpt == -1)
    {
        reverse(nums.begin(), nums.end());
    }
    else
    {
        for (int i=nums.size()-1 ; i>breakpt ; i--)
        {
            if (nums[i] > nums[breakpt])
            {
                swap(nums[i], nums[breakpt]);
                break;
            }
        }
        reverse(nums.begin()+breakpt+1,nums.end());
    }
    return nums;
}

int main()
{
    vector<int> v = {3,1,2};
    vector<int> ans = brute_nextPermutation(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = optimal_nextPermutation(ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = implementation(ans);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
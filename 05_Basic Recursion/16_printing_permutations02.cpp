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

vector<vector<int>> allPermutations(vector<int>& nums)
{
    vector<vector<int>> ans;
    permutation(ans, nums);
    return ans;
}

int main()
{
    vector<int> v = {3,1,2};
    vector<vector<int>> ans = allPermutations(v);
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
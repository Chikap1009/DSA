#include <bits/stdc++.h>
using namespace std;

void permutation(vector<int>& ds, vector<int>& hash, vector<vector<int>>& ans, vector<int>& nums)
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }

    for (int i=0 ; i<nums.size() ; i++)
    {
        if (hash[i] == 0)
        {
            ds.push_back(nums[i]);
            hash[i] = 1;
            permutation(ds, hash, ans, nums);
            hash[i] = 0;
            ds.pop_back();
        }
    }
}

vector<vector<int>> allPermutations(vector<int>& nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> hash(nums.size(),0);
    permutation(ds, hash, ans, nums);
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
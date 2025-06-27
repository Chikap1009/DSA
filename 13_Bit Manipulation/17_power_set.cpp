#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    for (int i=0 ; i<(1<<n) ; i++)
    {
        vector<int> temp;
        for (int j=0 ; j<n ; j++)
        {
            if ((i&(1<<j)) != 0) temp.push_back(nums[j]);
        }
        ans.push_back(temp);
    }
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
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_threeSum(vector<int>& nums)
{
    set<vector<int>> ansSet;
    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            for (int k=j+1 ; k<nums.size() ; k++)
            {
                int sum = nums[i] + nums[j] + nums[k];
                vector<int> temp = {nums[i], nums[j], nums[k]};
                sort(temp.begin(), temp.end());
                if (sum == 0)
                {
                    ansSet.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

vector<vector<int>> better_threeSum(vector<int>& nums)
{
    set<vector<int>> ansSet;
    for (int i=0 ; i<nums.size() ; i++)
    {
        unordered_set<int> hash;
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            int rem = -(nums[i] + nums[j]);
            if (hash.find(rem) != hash.end())
            {
                vector<int> temp = {nums[i], nums[j], rem};
                sort(temp.begin(), temp.end());
                ansSet.insert(temp);
            }
            hash.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

vector<vector<int>> optimal_threeSum(vector<int>& nums) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());

    for (int i=0 ; i<nums.size() ; i++)
    {
        if (i>0 && nums[i-1] == nums[i]) continue;
        int j = i+1;
        int k = nums.size()-1;

        while (j<k)
        {
            int sum = nums[i] + nums[j] + nums[k];
            if (sum < 0) j++;
            else if (sum > 0) k--;
            else
            {
                vector<int> temp = {nums[i], nums[j], nums[k]};
                ans.push_back(temp);
                j++;
                k--;
                while (j<k && nums[j] == nums[j-1]) j++;
                while (j<k && nums[k] == nums[k+1]) k--;
            }
        }
    }

    return ans;
}

int main()
{
    vector<int> v = {-1,0,1,2,-1,-4};

    vector<vector<int>> ans = brute_threeSum(v);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    ans = better_threeSum(v);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    ans = optimal_threeSum(v);
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
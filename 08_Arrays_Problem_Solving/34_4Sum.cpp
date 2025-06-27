#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> brute_fourSum(vector<int>& nums, int target) {
    set<vector<int>> ansSet;
    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            for (int k=j+1 ; k<nums.size() ; k++)
            {
                for (int l=k+1 ; l<nums.size() ; l++)
                {
                    int sum = nums[i] + nums[j] + nums[k] + nums[l];
                    if (sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        ansSet.insert(temp);
                    }
                } 
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

vector<vector<int>> better_fourSum(vector<int>& nums, int target) {
    set<vector<int>> ansSet;
    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            unordered_set<int> st;
            for (int k=j+1 ; k<nums.size() ; k++)
            {
                int rem = target - (nums[i] + nums[j] + nums[k]);
                if (st.find(rem) != st.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], rem};
                    sort(temp.begin(), temp.end());
                    ansSet.insert(temp);
                }
                st.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(ansSet.begin(), ansSet.end());
    return ans;
}

vector<vector<int>> optimal_fourSum(vector<int>& nums, int target) {
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (i>0 && nums[i-1] == nums[i]) continue;
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            if (j>i+1 && nums[j-1] == nums[j]) continue;
            int k = j+1;
            int l = nums.size()-1;
            while (k<l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum > target) l--;
                else if (sum < target) k++;
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while (k<l && nums[k-1] == nums[k]) k++;
                    while (k<l && nums[l] == nums[l+1]) l--;
                } 
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1,0,-1,0,-2,2};
    vector<vector<int>> ans = brute_fourSum(v, 0);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    ans = better_fourSum(v, 0);
    for (auto x : ans)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }

    ans = optimal_fourSum(v, 0);
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
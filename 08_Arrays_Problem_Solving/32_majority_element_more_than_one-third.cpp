#include <bits/stdc++.h>
using namespace std;

vector<int> brute_majorityElement(vector<int>& nums) {
    vector<int> ans;
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (ans.size() == 2)  break;
        if (ans.size() == 0 || ans[0] != nums[i])
        {
            int count = 0;
            for (int j=0 ; j<nums.size() ; j++)
            {
                if (nums[j] == nums[i])
                {
                    count++;
                }
            }
            if (count > nums.size() / 3)
            {
                ans.push_back(nums[i]);
            }
        }
    }
    return ans;
}

vector<int> better_majorityElement(vector<int>& nums) {
    unordered_map<int,int> hash;
    vector<int> ans;
    for (int i=0 ; i<nums.size() ; i++)
    {
        hash[nums[i]]++;
        if (hash[nums[i]] == nums.size()/3 + 1)
        {
            ans.push_back(nums[i]);
        }
        if (ans.size() == 2) break;
    }
    return ans;
}

vector<int> optimal_majorityElement(vector<int>& nums) {
    int count1 = 0, count2 = 0;
    int element1 = INT_MIN, element2 = INT_MIN;
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (count1 == 0 && nums[i] != element2)
        {
            element1 = nums[i];
            count1 = 1;
        }
        else if (count2 == 0 && nums[i] != element1)
        {
            element2 = nums[i];
            count2 = 1;
        }
        else if (nums[i] == element1)
        {
            count1++;
        }
        else if (nums[i] == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] ==  element1) count1++;
        else if (nums[i] == element2) count2++;
    }
    vector<int> ans;
    if (count1 > nums.size()/3) ans.push_back(element1);
    if (count2 > nums.size()/3) ans.push_back(element2);

    return ans;
}

int main()
{
    vector<int> v = {1,1,1,3,2,2,2};
    vector<int> ans = brute_majorityElement(v);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = better_majorityElement(v);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = optimal_majorityElement(v);

    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
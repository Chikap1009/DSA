#include <bits/stdc++.h>
using namespace std;

vector<int> brute_rearrangeArray(vector<int>& nums) {
    vector<int> positive;
    vector<int> negative;
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] > 0) positive.push_back(nums[i]);
        else negative.push_back(nums[i]);
    }
    for (int i=0 ; i<nums.size()/2 ; i++)
    {
        nums[i*2] = positive[i];
        nums[i*2 + 1] = negative[i]; 
    }
    return nums;
}

vector<int> optimal_rearrangeArray(vector<int>& nums) {
    int pos = 0;
    int neg = 1;
    vector<int> ans(nums.size(),0);
    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] > 0)
        {
            ans[pos] = nums[i];
            pos+=2;
        }
        else
        {
            ans[neg] = nums[i];
            neg+=2;
        }
    }
    return ans;
}

vector<int> variety_2_rearrangeArray(vector<int>& nums)
{
    vector<int> positive;
    vector<int> negative;

    for (int i=0 ; i<nums.size() ; i++)
    {
        if (nums[i] > 0)
        {
            positive.emplace_back(nums[i]);
        }
        else
        {
            negative.emplace_back(nums[i]);
        }
    }
    if (positive.size() > negative.size())
    {
        for (int i=0 ; i<negative.size() ; i++)
        {
            nums[i*2] = positive[i];
            nums[i*2+1] = negative[i]; 
        }
        int ind = 2*negative.size();
        for (int i=negative.size() ; i<positive.size() ; i++)
        {
            nums[ind] = positive[i];
            ind++;
        }
    }
    else
    {
        for (int i=0 ; i<positive.size() ; i++)
        {
            nums[i*2] = positive[i];
            nums[i*2+1] = negative[i]; 
        }
        int ind = 2*positive.size();
        for (int i=positive.size() ; i<negative.size() ; i++)
        {
            nums[ind] = negative[i];
            ind++;
        }
    }
    return nums;
}

int main()
{
    vector<int> v = {3,1,-2,-5,2,-4};
    vector<int> ans = brute_rearrangeArray(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    v = {3,1,-2,-5,2,-4};
    ans = optimal_rearrangeArray(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    v = {3,1,-2,-5,2,-4,5,7};
    ans = variety_2_rearrangeArray(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}

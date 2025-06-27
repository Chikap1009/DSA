#include <bits/stdc++.h>
using namespace std;

vector<int> brute_leadersInArray(vector<int>& nums)
{
    vector<int> leader;
    for (int i=0 ; i<nums.size() ; i++)
    {
        bool lead = true;
        for (int j=i+1 ; j<nums.size() ; j++)
        {
            if (nums[j] > nums[i])
            {
                lead = false;
                break;
            }
        }
        if (lead == true) leader.push_back(nums[i]);
    }
    return leader;
}

vector<int> optimal_leadersInArray(vector<int>& nums)
{
    vector<int> leader;
    int maxi = nums[nums.size()-1];
    leader.push_back(maxi);

    for (int i=nums.size()-2 ; i>=0 ; i--)
    {
        if (nums[i] >= maxi)
        {
            leader.push_back(nums[i]);
            maxi = nums[i];
        }
    }
    reverse(leader.begin(), leader.end());
    return leader;
}

int main()
{
    vector<int> v = {16, 17, 4, 3, 5, 2};

    vector<int> ans = brute_leadersInArray(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    ans = optimal_leadersInArray(v);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
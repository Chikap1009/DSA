#include <bits/stdc++.h>
using namespace std;

int brute_subarraySum(vector<int>& nums, int K)
{
    int total = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        for (int j=i ; j<nums.size() ; j++)
        {
            int sum = 0;
            for (int k=i ; k<=j ; k++)
            {
                sum+=nums[k];
            }
            if (sum == K) total++;
        }
    }
    return total;
}

int better_subarraySum(vector<int>& nums, int K)
{
    int total = 0;
    for (int i=0 ; i<nums.size() ; i++)
    {
        int sum = 0;
        for (int j=i ; j<nums.size() ; j++)
        {
            sum += nums[j];
            if (sum == K) total++;
        }
    }
    return total;
}

int optimal_subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> hash;
        int total = 0;
        int prefixSum = 0;
        hash[prefixSum]++;

        for (int i=0 ; i<nums.size() ; i++)
        {
            prefixSum += nums[i];
            int diff = prefixSum - k;
            total += hash[diff];
            hash[prefixSum]++;
        }

        return total;
    }

int main()
{
    vector<int> v = {1,2,3};

    cout << brute_subarraySum(v,3) << endl;
    cout << better_subarraySum(v,3) << endl;
    cout << optimal_subarraySum(v,3) << endl;

    return 0;
}
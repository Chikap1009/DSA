#include <bits/stdc++.h>
using namespace std;

int brute_singleNumber(vector<int> &arr)
{
    for (int i=0 ; i<arr.size() ; i++)
    {
        int count = 0;
        for (int j=0 ; j<arr.size() ; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count == 1)
        {
            return arr[i];
        }
    }
}

int better1_singleNumber(vector<int> &arr)
{
    int maxi = arr[0];
    int mini = arr[0];

    for (int i=0 ; i<arr.size() ; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
        if (arr[i] < mini)
        {
            mini = arr[i];
        }
    }

    vector<int> hash(maxi-mini+1, 0);

    for (int i=0 ; i<arr.size() ; i++)
    {
        hash[arr[i]-mini]++;
    }

    // for (int i=0 ; i<arr.size() ; i++)
    // {
    //     if (hash[arr[i]-mini] == 1)
    //     {
    //         return arr[i];
    //     }
    // }

    for (int i=mini ; i<=maxi ; i++)
    {
        if (hash[i-mini] == 1)
        {
            return i;
        }
    }
}

int better2_singleNumber(vector<int> &arr)
{
    map<int,int> mp;
    // unordered_map<int,int> mp;

    for (int i=0 ; i<arr.size() ; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        if (it.second == 1)
        {
            return it.first;
        }
    }
}

int optimal_singleNumber(vector<int> &arr)
{
    int xor_element = 0;

    for (auto it : arr)
    {
        xor_element ^= it;
    }

    return xor_element;
}

int main()
{
    vector<int> v = {4,1,2,1,2};

    cout << brute_singleNumber(v) << endl;
    cout << better1_singleNumber(v) << endl;
    cout << better2_singleNumber(v) << endl;
    cout << optimal_singleNumber(v) << endl;

    return 0;
}
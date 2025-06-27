#include <bits/stdc++.h>
using namespace std;

int brute_subarrayXOR(vector<int> &arr, int K)
{
    int count = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        for (int j=i ; j<arr.size() ; j++)
        {
            int total_XOR = 0;
            for (int k=i ; k<=j ; k++)
            {
                total_XOR ^= arr[k];
            }
            if (total_XOR == K) count++; 
        }
    }
    return count;
}

int better_subarrayXOR(vector<int> &arr, int K)
{
    int count = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        int total_XOR = 0;
        for (int j=i ; j<arr.size() ; j++)
        {
            total_XOR ^= arr[j];
            if (total_XOR == K) count++; 
        }
    }
    return count;
}

int optimal_subarrayXOR(vector<int> &arr, int k)
{
    int count = 0;
    int preXOR = 0;
    unordered_map<int,int> mp;

    for (int i=0 ; i<arr.size() ; i++)
    {
        preXOR ^= arr[i];
        if (preXOR == k) count++;
        count += mp[preXOR^k];
        mp[preXOR]++;
    }

    return count;
}

int main()
{
    vector<int> v = {4,2,2,6,4};
    cout << brute_subarrayXOR(v, 6) << endl;
    cout << better_subarrayXOR(v, 6) << endl;
    cout << optimal_subarrayXOR(v, 6) << endl;

    return 0;
}
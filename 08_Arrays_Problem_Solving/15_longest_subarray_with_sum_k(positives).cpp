#include <bits/stdc++.h>
using namespace std;

int brute_longest_subarray(vector<int> &arr, int k)
{
    int len = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        int sum = 0;
        for (int j=i ; j<arr.size() ; j++)
        {
            sum += arr[j];
            if (sum == k)
            {
                len = max(len, j-i+1);
            }
            if (sum > k)
            {
                break;
            }
        }
    }
    return len;
}

int better_longest_subarray(vector<int> &arr, int k)
{
    map<int,int> hash;
    int sum = 0;
    int len = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        sum += arr[i];
        if (sum == k)
        {
            len = max(len, i+1);
        }
        int diff = sum - k;
        if (hash.find(diff) != hash.end())
        {
            len = max(len, i-hash[diff]);
        }
        if (hash.find(sum) == hash.end())
        {
            hash[sum] = i;
        }
    }
    return len;
}

int optimal_longest_subarray(vector<int> &arr, int k)
{
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int len = 0;

    while (right < arr.size())
    {
        if (left <= right && sum > k)
        {
            sum -= arr[left];
            left++;
        }

        if (sum == k)
        {
            len = max(len, right-left+1);
        }

        right++;
        if (right < arr.size())
        {
            sum += arr[right];
        }
    }

    return len;
}

int main()
{
    vector<int> v = {2,0,0,3};

    cout << brute_longest_subarray(v,3) << endl;
    cout << better_longest_subarray(v,3) << endl;
    cout << optimal_longest_subarray(v,3) << endl;

    return 0;
}
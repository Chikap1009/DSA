#include <bits/stdc++.h>
using namespace std;

int brute_majorityElement(vector<int> &arr)
{
    int n = arr.size()/2;
    for (int i=0 ; i<n ; i++)
    {
        int count = 0;
        for (int j=0 ; j<n ; j++)
        {
            if (arr[j] == arr[i])
            {
                count++;
            }
        }
        if (count > n/2)
        {
            return arr[i];
        }
    }
    return -1;
}

int better_majorityElement(vector<int> &arr)
{
    int n = arr.size()/2;

    unordered_map<int,int> hash;

    for (int i=0 ; i<n ; i++)
    {
        hash[arr[i]]++;
    }

    for (auto it : hash)
    {
        if (it.second > n/2)
        {
            return it.first;
        }
    }
    return -1;
}

int optimal_majorityElement(vector<int> &arr)
{
    int n = arr.size()/2;
    int element;
    int count = 0;
    for (int i=0 ; i<n ; i++)
    {
        if (count == 0)
        {
            element = arr[i];
            count++;
        }

        if (arr[i] ==  element)
        {
            count++;
        }
        else
        {
            count--;
        }
    }

    int occur = 0;
    for (int i=0 ; i<n ; i++)
    {
        if (arr[i] ==  element)
        {
            occur++;
        }
    }

    if (occur > n/2)
    {
        return element;
    }
    return -1;
}

int main()
{
    vector<int> v = {2,2,1,1,1,2,2};

    cout << brute_majorityElement(v) << endl;
    cout << better_majorityElement(v) << endl;
    cout << optimal_majorityElement(v) << endl;

    return 0;
}
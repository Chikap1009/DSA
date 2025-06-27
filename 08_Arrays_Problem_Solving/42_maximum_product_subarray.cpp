#include <bits/stdc++.h>
using namespace std;

int brute_maxProductSubarray(vector<int>& arr)
{
    int maxProduct = INT_MIN;
    for (int i=0 ; i<arr.size() ; i++)
    {
        for (int j=i ; j<arr.size() ; j++)
        {
            int prod = 1;
            for (int k=i ; k<=j ; k++)
            {
                prod *= arr[k];
            }
            maxProduct = max(maxProduct, prod);
        }
    }
    return maxProduct;
}

int better_maxProductSubarray(vector<int>& arr)
{
    int maxProduct = INT_MIN;
    for (int i=0 ; i<arr.size() ; i++)
    {
        int prod = 1;
        for (int j=i ; j<arr.size() ; j++)
        {
            prod *= arr[j];
            maxProduct = max(maxProduct, prod);
        }
    }
    return maxProduct;
}

int optimal_maxProductSubarray(vector<int>& arr)
{
    int maxProduct = INT_MIN;
    int prefix = 1;
    int suffix = 1;

    for (int i=0 ; i<arr.size() ; i++)
    {
        if (prefix == 0) prefix = 1;
        if (suffix == 0) suffix = 1;

        prefix *= arr[i];
        suffix *= arr[arr.size()-i-1];

        maxProduct = max(maxProduct, max(prefix, suffix));
    }
    
    return maxProduct;
}

int main()
{
    vector<int> v = {2,3,-2,4};

    cout << brute_maxProductSubarray(v) << endl;
    cout << better_maxProductSubarray(v) << endl;
    cout << optimal_maxProductSubarray(v) << endl;

    return 0;
}
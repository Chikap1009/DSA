#include <bits/stdc++.h>
using namespace std;

int countSubArray(vector<int>& arr, int target, int index = 0, vector<int> v = {}, int sum = 0)
{
    if (sum > target) return 0;
    
    if (index == arr.size())
    {
        if (sum == target) return 1;
        return 0;
    }
    
    v.push_back(arr[index]);
    int l = countSubArray(arr, target, index+1, arr, sum+arr[index]);
    v.pop_back();
    int r = countSubArray(arr,target, index+1, arr, sum);
    
    return l+r;
}

int perfectSum(vector<int>& arr, int target) {
    return countSubArray(arr, target);
}

int main()
{
    vector<int> arr = {5,2,3,10,6,8};

    cout << perfectSum(arr, 10) << endl; // answer = 3

    return 0;
}
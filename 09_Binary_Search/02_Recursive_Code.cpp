#include <bits/stdc++.h>
using namespace std;

int binary_search(vector<int>& arr, int target, int low, int high)
{
    if (low > high) return -1;

    int mid = (low+high)/2;
    if (arr[mid] == target) return mid;
    else if (arr[mid] < target) return binary_search(arr, target, mid+1, high);
    else return binary_search(arr, target, low, mid-1);
}

int main()
{
    vector<int> v = {-1,0,3,5,9,12};

    cout << binary_search(v, 9, 0, v.size()-1) << endl;

    return 0;
}
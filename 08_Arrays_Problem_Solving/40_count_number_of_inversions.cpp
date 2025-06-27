#include <bits/stdc++.h>
using namespace std;

int brute_countInversions(vector<int>& arr)
{
    int count = 0;
    for (int i=0 ; i<arr.size() ; i++)
    {
        for (int j=i+1 ; j<arr.size() ; j++)
        {
            if (arr[j] < arr[i]) count++;
        }
    }
    return count;
}

int merge(vector<int>& arr, int low, int mid, int high)
{
    int left = low;
    int right = mid+1;
    int count = 0;

    vector<int> temp;

    while (left<=mid && right<=high)
    {
        if (arr[left] > arr[right])
        {
            temp.push_back(arr[right]);
            count += (mid-left+1);
            right++;
        }
        else
        {
            temp.push_back(arr[left]);
            left++;
        }
    }

    while (left<=mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right<=high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i=low ; i<=high ; i++)
    {
        arr[i] = temp[i-low];
    }

    return count;
}

int merge_sort(vector<int>& arr, int low, int high)
{
    int count = 0;
    if (low>=high) return count;

    int mid = (low+high)/2;
    count += merge_sort(arr, low, mid);
    count += merge_sort(arr, mid+1, high);

    count += merge(arr, low, mid, high);

    return count;
}

int optimal_countInversions(vector<int>& arr)
{
    return merge_sort(arr,0,arr.size()-1);
}

int main()
{
    vector<int> v = {5, 3, 2, 4, 1};

    cout << brute_countInversions(v) << endl;
    cout << optimal_countInversions(v) << endl;

    return 0;
}
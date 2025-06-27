#include <bits/stdc++.h>
using namespace std;

int brute_reversePairs(vector<int>& arr)
{
    int count = 0;

    for (int i=0 ; i<arr.size() ; i++)
    {
        for (int j=i+1 ; j<arr.size() ; j++)
        {
            if (arr[i] > 2 * arr[j]) count++;
        }
    }

    return count;
}

int countPairs(vector<int>& arr, int low, int mid, int high)
{
    int count = 0;
    int right = mid+1;

    for (int i=low ; i<=mid ; i++)
    {
        while (right<=high && arr[i] > 2*arr[right])
        {
            right++;
        }
        count += (right - (mid+1));
    }
    return count;
}

int merge(vector<int>& arr, int low, int mid, int high)
{
    int count = countPairs(arr, low, mid, high);

    vector<int> temp;
    int left = low;
    int right = mid+1;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.emplace_back(arr[left]);
            left++;
        }
        else
        {
            temp.emplace_back(arr[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.emplace_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.emplace_back(arr[right]);
        right++;
    }

    for (int i=low ; i<=high ; i++)
    {
        arr[i] = temp[i-low];
    }

    return count;
}

int mergeSort(vector<int>& arr, int low, int high)
{
    int count = 0;
    if (low >= high) return count;

    int mid = (low+high)/2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid+1, high);
    
    count += merge(arr, low, mid, high);

    return count;
}

int optimal_reversePairs(vector<int>& arr)
{
    return mergeSort(arr, 0, arr.size()-1);
}

int main()
{
    vector<int> v = {6, 13, 21, 25, 1, 2, 3, 4, 4, 5, 9, 11, 13};

    cout << brute_reversePairs(v) << endl;
    cout << optimal_reversePairs(v) << endl;

    return 0;
}
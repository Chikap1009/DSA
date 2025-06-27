#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high)
{
    int pivot = arr[low];
    int i = low;
    int j = high;

    while (i<j)
    {
        while (arr[i]<=pivot && i<high)
        {
            i++;
        }
        while (arr[j]>=pivot && j>low)
        {
            j--;
        }

        if (i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    arr[low] = arr[j];
    arr[j] = pivot;

    return j;
}

void quick_sort(vector<int> &arr, int low, int high)
{
    if (low>=high) return;

    int partition_index = partition(arr, low, high);
    quick_sort(arr, low, partition_index-1);
    quick_sort(arr, partition_index+1, high);

}

int main()
{
    int n;
    cin >> n;

    vector<int> v;

    for (int i=0 ; i<n ; i++)
    {
        int number;
        cin >> number;

        v.emplace_back(number);
    }

    quick_sort(v, 0, v.size()-1);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
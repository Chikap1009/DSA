#include <bits/stdc++.h>
using namespace std;

void recursive_insertion_sort(int arr[], int n, int i=0)
{
    if (i==n) return;

    int original_i = i;

    while (i-1>=0 && arr[i] < arr[i-1])
    {
        swap(arr[i],arr[i-1]);
        i--;
    }

    recursive_insertion_sort(arr, n, original_i+1);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }

    recursive_insertion_sort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
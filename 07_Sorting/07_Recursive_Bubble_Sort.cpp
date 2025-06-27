#include <bits/stdc++.h>
using namespace std;

void recursive_bubble_sort(int arr[], int n) // n is the length of the array.
{
    if (n==1) return;

    bool didSwap = 0;

    for (int j=0 ; j<n-1 ; j++)
    {
        if (arr[j] > arr[j+1])
        {
            swap(arr[j],arr[j+1]);
            didSwap = 1;
        }
    }

    if (didSwap == 0) return;

    recursive_bubble_sort(arr, n-1);
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

    recursive_bubble_sort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
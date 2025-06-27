#include <bits/stdc++.h>
using namespace std;

void bubble_sort(int arr[], int n)
{
    int didSwap = 0;
    for (int i=n-1 ; i>=1 ; i--)
    {
        for (int j=0 ; j<i ; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                didSwap = 1;
            }
        }

        if (didSwap == 0) break;
    }
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

    bubble_sort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
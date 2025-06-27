#include <bits/stdc++.h>
using namespace std;

// Time Complexity = O(n^2)

void selection_sort(int arr[], int n)
{
    for (int i=0 ; i<=n-2 ; i++)
    {
        int mini_element_index = i;

        for (int j=i ; j<=n-1 ; j++)
        {
            if (arr[j] < arr[mini_element_index])
            {
                mini_element_index = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[mini_element_index];
        arr[mini_element_index] = temp;
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

    selection_sort(arr, n);

    for (auto x : arr)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
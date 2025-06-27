#include <bits/stdc++.h>
using namespace std;

void reverse(int arr[], int n, int i = 0)
{
    if (i>=n/2) return;
    swap(arr[i],arr[n-i-1]);
    reverse(arr, n, i+1);
}

int main()
{
    int a[] = {1,2,3,4,5};
    reverse(a, 5);
    for (auto x : a)
    {
        cout << x << " ";
    }
    return 0;
}
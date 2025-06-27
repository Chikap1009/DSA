#include <bits/stdc++.h>
using namespace std;

bool canWeAllocate(vector<int> &arr, int n, int m, int limit)
{
    int studentGotBook = 0;
    int sum = 0;
    for (int i=0 ; i<n ; i++)
    {
        sum += arr[i];
        if (sum > limit)
        {
            studentGotBook++;
            sum = arr[i];
        }
        else if (sum == limit)
        {
            studentGotBook++;
            sum = 0;
        }
    }
    if (sum != 0) studentGotBook++;
    if (studentGotBook <= m) return true;
    return false;
}

vector<int> maxSumElement(vector<int> &arr) {
    int maxi = INT_MIN;
    int sum = 0;

    for (auto x : arr)
    {
        maxi = max(maxi, x);
        sum += x;
    }

    return {maxi, sum};
}

int findPages(vector<int> &arr, int n, int m) {
    if (n < m) return -1;
    vector<int> temp = maxSumElement(arr);
    int low = temp[0]; // max
    int high = temp[1]; // sum

    while (low <= high)
    {
        int mid = (low + high)/2;

        if (canWeAllocate(arr, n, m, mid))
        {
            high = mid-1;
        }
        else
        {
            low = mid+1;
        }
    }
    return low;
}

int main()
{
    vector<int> v = {25, 46, 28, 49, 24};

    cout << findPages(v, 5, 4) << endl;

    return 0;
}
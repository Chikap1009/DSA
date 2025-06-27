#include <bits/stdc++.h>
using namespace std;

int numberOfRotations(vector<int>& arr)
{
    int low = 0;
    int high = arr.size()-1;
    int minElement = INT_MAX;
    int minElementIndex = -1;

    while (low <= high)
    {
        int mid = (low+high)/2;

        if (arr[low] <= arr[high])
        {
            if (arr[low] < minElement)
            {
                minElement = arr[low];
                minElementIndex = low;
            }
            break;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] < minElement)
            {
                minElement = arr[low];
                minElementIndex = low;
            }
            low = mid+1;
        }
        else
        {
            if (arr[mid] < minElement)
            {
                minElement = arr[mid];
                minElementIndex = mid;
            }
            high = mid-1;
        }
    }
    return minElementIndex;
}

int main()
{
    vector<int> v = {4,5,6,7,0,1,2};

    cout << numberOfRotations(v) << endl;

    return 0;
}
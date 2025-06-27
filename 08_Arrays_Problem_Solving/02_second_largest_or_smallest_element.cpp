#include <bits/stdc++.h>
using namespace std;

int second_largest_element(vector<int> &arr)
{
    int largest = arr[0];
    int second_largest = INT_MIN;

    for (int i=1 ; i<arr.size() ; i++)
    {
        if (arr[i] > largest)
        {
            second_largest = largest;
            largest = arr[i];
        }

        else if (arr[i] > second_largest && arr[i] != largest)
        {
            second_largest = arr[i];
        }
    }

    return second_largest;
}

int second_smallest_element(vector<int> &arr)
{
    int smallest = arr[0];
    int second_smallest = INT_MAX;

    for (int i=1 ; i<arr.size() ; i++)
    {
        if (arr[i] < smallest)
        {
            second_smallest = smallest;
            smallest = arr[i];
        }

        else if (arr[i] < second_smallest && arr[i] != smallest)
        {
            second_smallest = arr[i];
        }
    }

    return second_smallest;
}

int main()
{
    vector<int> v = {1,2,4,7,7,5};

    cout << second_largest_element(v) << " " << second_smallest_element(v);

    return 0;
}
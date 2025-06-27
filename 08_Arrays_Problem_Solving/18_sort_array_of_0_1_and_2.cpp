#include <bits/stdc++.h>
using namespace std;

void brute_sortColors(vector<int> &arr)
{
    // Implement Quick Sort or Merge Sort.
    sort(arr.begin(), arr.end());
}

void better_sortColors(vector<int> &arr)
{
    int num0 = 0, num1 = 0, num2 = 0;
    for (auto x : arr)
    {
        if (x==0) num0++;
        else if (x==1) num1++;
        else num2++;
    }
    for (int i=0 ; i<num0 ; i++)
    {
        arr[i] = 0;
    }
    for (int i=num0 ; i<num0+num1 ; i++)
    {
        arr[i] = 1;
    }
    for (int i=num0+num1 ; i<arr.size() ; i++)
    {
        arr[i] = 2;
    }
}

void optimal_sortColors(vector<int> &arr)
{
    int low = 0, mid = 0, high = arr.size()-1;

    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> v = {2,0,2,1,1,0};

    brute_sortColors(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v = {2,0,2,1,1,0};

    better_sortColors(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v = {2,0,2,1,1,0};
    
    optimal_sortColors(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
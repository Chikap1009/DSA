#include <bits/stdc++.h>
using namespace std;

void left_rotate(vector<int> &arr)
{
    int first = arr[0];

    for (int i=1 ; i<arr.size() ; i++)
    {
        arr[i-1] = arr[i];
    }

    arr[arr.size()-1] = first;
}

void right_rotate(vector<int> &arr)
{
    int last = arr[arr.size()-1];

    for (int i=arr.size()-2 ; i>=0 ; i--)
    {
        arr[i+1] = arr[i];
    }

    arr[0] = last;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};

    left_rotate(v);

    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    right_rotate(v);

    for (auto x : v)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
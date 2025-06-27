#include <bits/stdc++.h>
using namespace std;

void left_rotate_by_k_places(vector<int> &arr, int k)
{
    k = k % (arr.size());
    vector<int> temp;
    for (int i=0 ; i<k ; i++)
    {
        temp.push_back(arr[i]);
    }

    for (int i=k ; i<arr.size() ; i++)
    {
        arr[i-k] = arr[i];
    }

    for (int i=arr.size()-k ; i<arr.size() ; i++)
    {
        arr[i] = temp[i - (arr.size()-k)];
    }
}

void right_rotate_by_k_places(vector<int> &arr, int k)
{
    k = k % (arr.size());
    vector<int> temp;
    for (int i=arr.size()-k ; i<arr.size() ; i++)
    {
        temp.push_back(arr[i]);
    }
    for (int i=arr.size()-k-1 ; i>=0 ; i--)
    {
        arr[i+k] = arr[i];
    }
    for (int i=0 ; i<k ; i++)
    {
        arr[i] = temp[i];
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7};

    left_rotate_by_k_places(v, 17);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    right_rotate_by_k_places(v, 17);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
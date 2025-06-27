#include <bits/stdc++.h>
using namespace std;

void left_rotate_by_k_places(vector<int> &arr, int k)
{
    k = k % (arr.size());
    reverse(arr.begin(), arr.begin()+k);
    reverse(arr.begin()+k, arr.end());
    reverse(arr.begin(), arr.end());
}

void right_rotate_by_k_places(vector<int> &arr, int k)
{
    k = k % (arr.size());
    reverse(arr.begin(),arr.end()-k);
    reverse(arr.end()-k, arr.end());
    reverse(arr.begin(), arr.end());
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
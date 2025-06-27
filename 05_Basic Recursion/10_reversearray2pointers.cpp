#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr)
{
    int l = 0;
    int r = arr.size()-1;

    while (l<r)
    {
        int temp = arr[l];
        arr[l] = arr[r];
        arr[r] = temp;

        l++;
        r--;
    }
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    reverse(v);
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}
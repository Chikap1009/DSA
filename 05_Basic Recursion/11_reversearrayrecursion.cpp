#include <bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr, int l, int r)
{
    if (l>=r) return;
    swap(arr[l],arr[r]);

    l++;
    r--;

    reverse(arr, l, r);
}

int main()
{
    vector<int> v = {1,2,3,4,5};
    reverse(v,0,v.size()-1);
    for (auto x : v)
    {
        cout << x << " ";
    }
    return 0;
}
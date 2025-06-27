#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &arr)
{
    for (int i=1 ; i<arr.size() ; i++)
    {
        if (arr[i] < arr[i-1]) return false;
    }
    return true;
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    cout << check(v) << endl;

    return 0;
}
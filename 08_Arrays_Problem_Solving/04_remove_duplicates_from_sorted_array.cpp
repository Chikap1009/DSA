#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int> &arr)
{
    int i=0;
    for (int j=1 ; j<arr.size() ; j++)
    {
        if (arr[j] != arr[i]) return false;
    }
    return true;
}

int main()
{
    vector<int> v = {1,2,3,4,5};

    cout << check(v) << endl;

    return 0;
}
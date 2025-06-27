#include <bits/stdc++.h>
using namespace std;

int linear_search(vector<int> &arr, int k)
{
    for (int i=0 ; i<arr.size() ; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    vector<int> v = {1,3,7,9,3,6,8,2};

    cout << linear_search(v, 3) << endl;

    return 0;
}
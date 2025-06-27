#include <bits/stdc++.h>
using namespace std;

int largest_element(vector<int> &arr)
{
    int max = arr[0];

    for (int i=0 ; i<arr.size() ; i++)
    {
        if (arr[i] > max)
        {
            max  = arr[i];
        }
    }

    return max;
}

int main()
{
    vector<int> v = {3,2,1,5,2};

    cout << largest_element(v) << endl;

    return 0;
}
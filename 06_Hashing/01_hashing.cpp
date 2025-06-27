#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i=0 ; i<n ; i++)
    {
        cin >> arr[i];
    }

    int hash[13] = {0}; // max element value + 1

    for (int i=0 ; i<n ; i++)
    {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;

    for (int i=0 ; i<q ; i++)
    {
        int number;
        cin >> number;

        cout << hash[number] << endl;
    }

    return 0;
}
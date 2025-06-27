#include <bits/stdc++.h>
using namespace std;

bool larger(int x1, int x2)
{
    if (x1>x2) return true;
    return false;
}

int main()
{
    int a[] = {1,5,4,3,2,6};
    sort(a,a+6);
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    sort(a,a+6,larger);
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> v = {1,5,4,3,2,6};
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    sort(v.begin(), v.end());
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
    sort(v.begin(), v.end(),larger);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    sort(v.begin()+2, v.end()-1);
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
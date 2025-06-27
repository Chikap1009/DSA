#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10,20,30,40};
    cout << v[0] << endl;
    cout << v.at(0) << endl;
    cout << v.front() << endl;
    cout << v.back() << endl;

    for (auto it = v.begin() ; it != v.end() ; it++)
    {
        cout << *(it) << " ";
    }

    for (auto x : v)
    {
        cout << x << " ";
    }

    return 0;
}
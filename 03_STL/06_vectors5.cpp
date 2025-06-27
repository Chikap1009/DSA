#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v(2,100);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.insert(v.begin(), 300);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.insert(v.begin()+1, 2, 500);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    vector<int> copy(2,50);
    v.insert(v.begin(),copy.begin(),copy.end());

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;


    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10,20,30,40,50};

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.erase(v.begin()+2);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    v.erase(v.begin()+1,v.begin()+3);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
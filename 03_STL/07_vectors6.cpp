#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v={10,20,30,40,50};

    cout << v.size() << endl;

    v.pop_back();
    cout << v.size() << endl;

    vector<int> temp={10,20};
    v.swap(temp);

    for (auto x:v)
    {
        cout << x << " ";
    }
    cout << endl;
    for (auto x:temp)
    {
        cout << x << " ";
    }
    cout << endl;

    v.clear();
    for (auto x:v)
    {
        cout << x << " ";
    }
    cout << endl;

    cout << v.empty() << endl;

    return 0;
}
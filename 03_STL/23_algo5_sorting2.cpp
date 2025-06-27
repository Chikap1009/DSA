#include <bits/stdc++.h>
using namespace std;

bool comp (pair<int,int> p1, pair<int,int> p2)
{
    if (p1.second < p2.second) return true;
    else if (p1.second > p2.second) return false;
    else
    {
        if (p1.first > p2.first) return true;
        return false;
    }
}

int main()
{
    pair<int,int> a[] = {{1,3},{2,6},{2,3}};

    for (auto x : a)
    {
        cout << x.first << " " << x.second << endl;
    }

    sort(a,a+3,comp);

    for (auto x : a)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
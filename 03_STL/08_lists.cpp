#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ls;

    ls.push_back(2);
    ls.emplace_back(1);

    ls.push_front(5);
    ls.emplace_front(7);

    for (auto x : ls)
    {
        cout << x << " ";
    }

    cout << endl;

    cout << ls.front() << endl;
    cout << ls.back() << endl;

    ls.pop_back();

    for (auto x : ls)
    {
        cout << x << " ";
    }

    cout << endl;

    ls.pop_front();

    for (auto x : ls)
    {
        cout << x << " ";
    }

    cout << endl;

    return 0;
}
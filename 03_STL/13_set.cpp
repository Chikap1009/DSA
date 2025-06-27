#include <bits/stdc++.h>
using namespace std;

void print(set<int> s)
{
    for (auto x : s)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    set<int> s;
    s.insert(10);
    s.insert(40);
    s.emplace(20);
    s.emplace(30);
    s.insert(45);
    s.emplace(40);
    print(s);

    s.erase(10);
    print(s);

    s.erase(60);
    print(s);

    cout << s.count(40) << endl;
    cout << s.count(100) << endl;

    auto it1 = s.find(30);
    cout << *(it1) << endl;

    s.erase(it1);
    print(s);

    s.emplace(30);
    s.emplace(50);
    s.emplace(35);
    print(s);

    s.erase(s.find(20),s.find(45));
    print(s);

    return 0;
}
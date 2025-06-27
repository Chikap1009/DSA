#include <bits/stdc++.h>
using namespace std;

void print(multiset<int> ms)
{
    for (auto x : ms)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    multiset<int> ms;
    ms.insert(10);
    ms.emplace(40);
    ms.emplace(20);
    ms.emplace(50);
    ms.emplace(30);
    ms.emplace(30);
    ms.emplace(30);
    ms.emplace(30);

    print(ms);

    cout << ms.count(30) << endl;
    cout << ms.count(60) << endl;

    // ms.erase(30);
    // print(ms);

    auto it1 = ms.find(30);
    it1++;
    it1++;

    ms.erase(ms.find(30), it1);
    print(ms);

    return 0;
}
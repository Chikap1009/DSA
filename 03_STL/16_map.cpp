#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int,int> mp1;
    map<int,pair<int,int>> mp2;
    map<pair<int,int>,int> mp3;

    mp1[1] = 2;
    mp1.insert({3,1});
    mp1.emplace(2,4);

    for (auto x : mp1)
    {
        cout << x.first << " " << x.second << endl;
    }

    mp3[{2,3}] = 10;

    cout << mp1[1] << endl;
    cout << mp1[5] << endl;

    auto it = mp1.find(2);
    // cout << *(it).first << " " << *(it).second << endl;

    return 0;
}
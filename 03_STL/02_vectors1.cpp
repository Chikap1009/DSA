#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v1;

    v1.push_back(1);
    v1.emplace_back(2);

    vector<pair<int,int>> v2;

    v2.push_back({1,2});
    v2.emplace_back(3,4);

    vector<int> v3(5,100);

    vector<int> v4(5);

    vector<int> v5(5,20);
    vector<int> v6(v5);
}
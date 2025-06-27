#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {10,2,4,1,3,6,7,3,11,4};

    cout << *max_element(v.begin(),v.end()) << endl;
    cout << *min_element(v.begin(),v.end()) << endl;

    return 0;
}
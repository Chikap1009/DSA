#include <bits/stdc++.h>
using namespace std;

vector<int> findIntersection(vector<int> &a, vector<int> &b)
{
    vector<int> intersection;

    int i=0;
    int j=0;
    
    while (i<a.size() && j<b.size())
    {
        if (a[i] == b[j])
        {
            intersection.emplace_back(a[i]);
            i++;
            j++;
        }

        else if (a[i] < b[j])
        {
            i++;
        }

        else
        {
            j++;
        }
    }

    return intersection;
}

int main()
{
    vector<int> v1 = {1,2,2,2,3,3,3,4,4,4};
    vector<int> v2 = {2,2,2,4,4,4,5,5,6};

    vector<int> i = findIntersection(v1, v2);

    for (auto it : i)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
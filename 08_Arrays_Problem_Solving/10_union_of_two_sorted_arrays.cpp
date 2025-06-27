#include <bits/stdc++.h>
using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
        vector<int> u;

        int i=0;
        int j=0;

        while (i<a.size() && j<b.size())
        {
            if (a[i] < b[j])
            {
                if (u.size() == 0 || u.back() != a[i])
                {
                    u.emplace_back(a[i]);
                }
                i++;
            }
            else if (b[j] < a[i])
            {
                if (u.size() == 0 || u.back() != b[j])
                {
                    u.emplace_back(b[j]);
                }
                j++;
            }
            else
            {
                if (u.size() == 0 || u.back() != a[i])
                {
                    u.emplace_back(a[i]);
                }
                i++;
                j++;
            }
        }

        while (i<a.size())
        {
            if (u.size() == 0 || u.back() != a[i])
            {
                u.emplace_back(a[i]);
            }
            i++;
        }

        while (j<b.size())
        {
            if (u.size() == 0 || u.back() != b[j])
            {
                u.emplace_back(b[j]);
            }
            j++;
        }

        return u;
    }

int main()
{
    vector<int> v1 = {1,2,2,2,3,3,3,4,4,4};
    vector<int> v2 = {2,2,2,4,4,4,5,5,6};

    vector<int> u = findUnion(v1, v2);

    for (auto it : u)
    {
        cout << it << " ";
    }
    cout << endl;

    return 0;
}
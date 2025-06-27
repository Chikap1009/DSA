#include <bits/stdc++.h>
using namespace std;

bool subsets(int n, int k, vector<int>& a, vector<int> temp = {}, int index = 0, int sum = 0)
{
    if (sum > k) return false;
    if (index == n)
    {
        if (sum == k) return true;
        return false;
    }

    temp.push_back(a[index]);
    if (subsets(n, k, a, temp, index+1,sum+a[index]))
    {
        return true;
    }
    temp.pop_back();
    if (subsets(n, k, a, temp, index+1, sum))
    {
        return true;
    }
    return false;
}

bool isSubsetPresent(int n, int k, vector<int> &a)
{
    return subsets(n ,k, a);

}

int main()
{
    vector<int> v = {1,2,3};

    cout << isSubsetPresent(3, 5, v) << endl;

    return 0;
}
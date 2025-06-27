#include <bits/stdc++.h>
using namespace std;

int factorial(int n)
{
    int fact = 1;
    for (int i=2 ; i<=n ; i++)
    {
        fact*=i;
    }
    return fact;
}

int brute_funcnCr(int n, int r)
{
    int nCr = (factorial(n)) / (factorial(r) * factorial(n-r));
    return nCr;
}

int optimal_funcnCr(int n, int r)
{
    if (r>n/2) r = n-r;
    int nCr = 1;
    for (int i=1 ; i<=r ; i++)
    {
        nCr *= (n-i+1);
        nCr /= (i);
    }
    return nCr;
}

int variety1_Pascal(int row, int col)
{
    return optimal_funcnCr(row-1,col-1);
}


// Same as generateRow(int n)
vector<int> brute_variety2_Pascal(int n)
{
    vector<int> v;
    for (int col=1 ; col<=n ; col++)
    {
        v.push_back(optimal_funcnCr(n-1, col-1));
    }
    return v;
}

vector<int> optimal_variety2_Pascal(int n)
{
    vector<int> v;
    int res = 1;
    v.push_back(res);
    for (int col=2 ; col<=n ; col++)
    {
        res*=(n-col+1);
        res/=(col-1);
        v.push_back(res);
    }
    return v;
}

vector<vector<int>> brute_variety3_Pascal(int n)
{
    vector<vector<int>> pascal;
    for (int row=1 ; row<=n ; row++)
    {
        vector<int> rows;
        for (int col=1 ; col<=row ; col++)
        {
            rows.push_back(optimal_funcnCr(row-1,col-1));
        }
        pascal.push_back(rows);
    }
    return pascal;
}

vector<vector<int>> optimal_variety3_Pascal(int n)
{
    vector<vector<int>> ans;
    for (int row=1 ; row<=n ; row++)
    {
        ans.push_back(optimal_variety2_Pascal(row));
    }
    return ans;
}

void print1(vector<int> v)
{
    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;
}

void print2(vector<vector<int>> v)
{
    for (auto x : v)
    {
        for (auto y : x)
        {
            cout << y << " ";
        }
        cout << endl;
    }
}


int main()
{
    cout << brute_funcnCr(4,2) << endl;
    cout << optimal_funcnCr(4,2) << endl;

    // Variety 1
    // Row 5 Column 4
    cout << variety1_Pascal(5, 4) << endl;

    // Variety 2
    // N = 6
    vector<int> ans1 = brute_variety2_Pascal(6);
    print1(ans1);
    vector<int> ans2 = optimal_variety2_Pascal(6);
    print1(ans2);

    // Variety 3
    // N = 6
    vector<vector<int>> ans3 = brute_variety3_Pascal(6);
    print2(ans3);
    vector<vector<int>> ans4 = optimal_variety3_Pascal(6);
    print2(ans4);

    return 0;
}
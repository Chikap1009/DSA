#include <bits/stdc++.h>
using namespace std;

int add(int n, int sum = 0)
{
    if (n<1) return sum;
    return add(n-1, sum+n);
}

int main()
{
    cout << add(10) << endl;

    return 0;
}
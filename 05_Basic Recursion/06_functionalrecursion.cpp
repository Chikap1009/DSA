#include <bits/stdc++.h>
using namespace std;

int add(int n)
{
    if (n==1) return 1;
    return n + add(n-1);
}

int main()
{
    cout << add(10) << endl;

    return 0;
}
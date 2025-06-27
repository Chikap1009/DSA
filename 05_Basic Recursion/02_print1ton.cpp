#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if (n<1) return;
    print(n-1);
    cout << n << " ";
}

int main()
{
    print(10);

    return 0;
}
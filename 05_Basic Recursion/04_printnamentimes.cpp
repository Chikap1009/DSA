#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
    if (n<1) return;
    cout << "Chirag ";
    print(n-1);
}

int main()
{
    print(10);

    return 0;
}
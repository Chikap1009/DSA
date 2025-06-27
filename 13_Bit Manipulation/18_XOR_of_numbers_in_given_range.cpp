#include <bits/stdc++.h>
using namespace std;

int XORfrom1ton(int n)
{
    if (n%4 == 1) return 1;
    else if (n%4 == 2) return n+1;
    else if (n%4 == 3) return 0;
    else return n;
}

int findXOR(int l, int r) {
    return (XORfrom1ton(l-1) ^ XORfrom1ton(r));
}

int main()
{
    cout << findXOR(7,11) << endl;

    return 0;
}
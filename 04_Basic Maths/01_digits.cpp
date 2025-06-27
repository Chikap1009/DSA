#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 7889;
    int og = n;

    int cnt = 0;

    while(n>0)
    {
        int last = n%10;
        cnt++;
        n = n/10;
    }

    cout << cnt << endl;

    cout << log10(og) << endl;
    cout << log10(og) + 1 << endl;
    cout << (int) log10(og) + 1 << endl;

    cnt = (int) log10(og) + 1;

    return 0;
}
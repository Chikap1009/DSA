#include <bits/stdc++.h>
using namespace std;

bool prime(int n)
{
    int count = 0;
    for (int i=1 ; i*i<=n ; i++)
    {
        if (n%i == 0)
        {
            count++;
            if (i != n/i)
            {
                count++;
            }
        }
    }
    if (count == 2)
    {
        return true;
    }
    return false;
}

int main()
{
    cout << prime(1) << endl;
    cout << prime(2) << endl;
    cout << prime(3) << endl;
    cout << prime(4) << endl;
    cout << prime(5) << endl;
    cout << prime(6) << endl;
    cout << prime(7) << endl;
    
    return 0;
}
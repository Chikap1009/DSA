/* 
For n = 4,
4444444
4333334
4322234
4321234
4322234
4333334
4444444
*/

#include <bits/stdc++.h>
using namespace std;

// void print(int n)
// {
//     for (int i=0 ; i<2*n-1 ; i++)
//     {
//         for (int j=0 ; j<2*n-1 ; j++)
//         {
//             cout << min(min(i, j), min(2*(n-1)-i, 2*(n-1)-j));
//         }
//         cout << endl;
//     }
// }

void print(int n)
{
    for (int i=0 ; i<2*n-1 ; i++)
    {
        for (int j=0 ; j<2*n-1 ; j++)
        {
            cout << n - min(min(i, j), min(2*(n-1)-i, 2*(n-1)-j));
        }
        cout << endl;
    }
}

int main()
{
    print(4);
    return 0;
}
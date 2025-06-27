#include <bits/stdc++.h>
using namespace std;

// int minBitFlips(int start, int goal) {
//     int count = 0;
//     int check = 0;
//     while(start != goal)
//     {
//         if (((start&(1<<check)) != 0) && (goal&(1<<check)) == 0)
//         {
//             start = start&(~(1<<check));
//             count++;
//         }
//         else if (((start&(1<<check)) == 0) && (goal&(1<<check)) != 0) 
//         {
//             start = start|(1<<check);
//             count++;
//         }
//         check++;
//     }
//     return count;
// }

int minBitFlips(int start, int goal) {
    int res = start^goal;
    int count = 0;
    while(res > 0)
    {
        count += res&1;
        res>>=1;
    }
    return count;
}

int main()
{
    cout << minBitFlips(10,7) << endl;
    
    return 0;
}
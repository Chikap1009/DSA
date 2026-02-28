#include <bits/stdc++.h>
using namespace std;

int climbStairs(int n) {
    if (n <= 1) return n;
    
    int prev2 = 1, prev1 = 1, curr;
    for (int i=2 ; i<=n ; i++) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    
    return prev1;
}

int main() {
    int n = 5; // Example input
    cout << "Number of ways to climb " << n << " stairs: " << climbStairs(n) << endl;
    return 0;
}
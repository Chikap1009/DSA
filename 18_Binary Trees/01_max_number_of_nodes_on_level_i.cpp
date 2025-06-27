#include <bits/stdc++.h>
using namespace std;

int countNodes(int i) {
    return (1<<(i-1));
}

int main() {
    cout << countNodes(5) << endl;

    return 0;
}
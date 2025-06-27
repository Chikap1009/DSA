#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.emplace(30);
    
    cout << q.front() << endl;
    cout << q.back() << endl;

    q.pop();
    cout << q.front() << endl;
    cout << q.back() << endl;

    q.back() += 10;
    cout << q.front() << endl;
    cout << q.back() << endl;

    return 0;
}
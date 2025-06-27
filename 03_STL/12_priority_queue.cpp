#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(10);
    pq.push(40);
    pq.emplace(30);
    pq.push(35);

    cout << pq.top() << endl;

    pq.pop();
    cout << pq.top() << endl;

    priority_queue<int,vector<int>,greater<int>> pq1;
    pq1.push(10);
    pq1.push(40);
    pq1.emplace(30);
    pq1.push(35);

    cout << pq1.top() << endl;

    pq1.pop();
    cout << pq1.top() << endl;

    return 0;
}
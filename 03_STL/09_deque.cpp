#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);

    dq.push_front(10);
    dq.emplace_front(11);

    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << endl;

    dq.pop_back();
    dq.pop_front();
    
    for (auto x : dq)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
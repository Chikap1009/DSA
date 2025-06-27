#include <bits/stdc++.h>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2;
    MyQueue() {

    }
    
    void push(int x) {
        s1.push(x);
    }
    
    int pop() {
        if (s2.empty())
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int el = s2.top();
        s2.pop();
        return el;
    }
    
    int peek() {
        if (s2.empty())
        {
            while(s1.size())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
    
    bool empty() {
        if (s1.empty() && s2.empty()) return true;
        return false;
    }
};

int main()
{
    MyQueue q = MyQueue();

    q.push(3);
    q.push(5);
    q.push(7);
    q.push(9);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    q.push(11);
    cout << q.peek() << endl;
    cout << q.pop() << endl;
    cout << q.empty() << endl;

    return 0;
}
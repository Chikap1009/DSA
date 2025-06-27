#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    queue<int> q;
    MyStack() {

    }
    
    void push(int x) {
        int s = q.size();
        q.push(x);
        for (int i=0 ; i<s ; i++)
        {
            int temp = q.front();
            q.push(temp);
            q.pop();
        }
    }
    
    int pop() {
        int temp = q.front();
        q.pop();
        return temp;
    }
    
    int top() {
        return q.front();
    }
    
    bool empty() {
        if (q.size()) return false;
        return true;
    }
};

int main()
{
    MyStack st = MyStack();
    st.push(5);
    st.push(7);
    st.push(9);
    st.push(11);
    cout << st.top() << endl;
    cout << st.pop() << endl;
    cout << st.empty() << endl;

    return 0;
}
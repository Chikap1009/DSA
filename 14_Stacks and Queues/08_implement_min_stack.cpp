#include <bits/stdc++.h>
using namespace std;

// class MinStack {
// public:
//     stack<pair<int,int>> st;
//     MinStack() {
        
//     }
    
//     void push(int val) {
//         if (st.empty()) st.push({val,val});
//         else st.push({val,min(val,st.top().second)});
//     }
    
//     void pop() {
//         st.pop();
//     }
    
//     int top() {
//         return st.top().first;
//     }
    
//     int getMin() {
//         return st.top().second;
//     }
// };

class MinStack {
public:

    stack<long long> st;
    long long mini;

    MinStack() {
        mini = LONG_MAX;
    }
    
    void push(int val) {
        long long x = val;
        if (st.empty()) {
            st.push(x);
            mini = x;
        }
        else {
            if (x > mini) st.push(x);
            else
            {
                st.push(2*x - mini);
                mini = x;
            }
        }
    }
    
    void pop() {
        if (st.top() > mini) st.pop();
        else {
            mini = 2*mini - st.top();
            st.pop();
        }
    }
    
    int top() {
        if (st.top() > mini) return st.top();
        else return mini;
    }
    
    int getMin() {
        return mini;
    }
};

int main()
{
    MinStack st = MinStack();
    
    st.push(7);
    st.push(9);
    st.push(8);
    st.push(4);
    st.push(10);
    cout << st.getMin() << endl;
    st.pop();
    cout << st.top() << endl;
    cout << st.getMin() << endl;

    return 0;
}
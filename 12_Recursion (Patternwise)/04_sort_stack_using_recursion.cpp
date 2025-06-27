#include <bits/stdc++.h>
using namespace std;

void pushSorted(stack<int> &st, int num)
{
    if (st.size() == 0 || st.top() <= num)
    {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();
    pushSorted(st, num);
    st.push(n);
}

void sortStack(stack<int> &st)
{
    if (st.size() == 0) return;

    int num = st.top();
    st.pop();
    sortStack(st);
    pushSorted(st, num);
}

void print(stack<int> &st)
{
    if (st.size() == 0) return;

    int num = st.top();
    cout << num << " ";
    st.pop();
    print(st);
    st.push(num);
}

int main()
{
    stack<int> st;

    st.push(5);
    st.push(9);
    st.push(2);
    st.push(10);
    st.push(1);
    st.push(8);
    st.push(3);
    st.push(4);
    st.push(6);
    st.push(7);
    // 7 6 4 3 8 1 10 2 9 5

    print(st);
    cout << endl;

    sortStack(st);

    print(st);
    cout << endl;

    return 0;
}
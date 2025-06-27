#include <bits/stdc++.h>
using namespace std;

class MyStack
{
    private:
        int arr[1000];
        int top;
    public:
        MyStack(){top=-1;}

        int pop();
        void push(int);
        int getTop();
        int size();
};


void MyStack::push(int x) {
    top++;
    arr[top] = x;
}

int MyStack::pop() {
    if (top == -1) return -1;
    int el = arr[top];
    top--;
    return el;
}

int MyStack::getTop()
{
    if (top == -1) return -1;
    return arr[top];
}

int MyStack::size()
{
    return (top+1);
}

int main()
{
    MyStack st = MyStack();

    st.push(1);
    st.push(2);
    cout << st.getTop() << endl;
    cout << st.pop() << endl;
    st.push(7);
    cout << st.getTop() << endl;
    cout << st.size() << endl;

    return 0;
}
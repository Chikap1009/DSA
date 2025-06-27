#include <bits/stdc++.h>
using namespace std;

struct StackNode {
    int data;
    StackNode* next;

    StackNode(int a) {
        data = a;
        next = nullptr;
    }
};

class MyStack {
  private:
    StackNode *top;
    int size;

  public:
    void push(int x) {
        StackNode* newNode = new StackNode(x);
        newNode->next = top;
        top = newNode;
        size++;
    }

    int pop() {
        if (!top) return -1;
        StackNode* temp = top;
        top = top->next;
        int el = temp->data;
        size--;
        delete temp;
        return el;
    }

    int getTop() {
        if (!top) return -1;
        return (top->data);
    }

    int getSize() {return size;}

    MyStack() { top = NULL; size=0;}
};

int main()
{
    MyStack st = MyStack();
    st.push(5);
    st.push(9);
    st.push(7);
    st.push(10);
    cout << st.pop() << endl;
    cout << st.getTop() << endl;
    cout << st.getSize() << endl;

    return 0;
}
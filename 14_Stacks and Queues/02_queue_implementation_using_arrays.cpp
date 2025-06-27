#include <bits/stdc++.h>
using namespace std;

// class MyQueue {
//     private:
//         int size = 100005;
//         int arr[100005];
//         int front;
//         int rear;
//         int currSize;

//     public :
//         MyQueue(){front=-1;rear=-1;currSize=0;}
//         void push(int);
//         int pop();
//         int top();
//         int getSize();
// };

// void MyQueue::push(int x) {
//     if (currSize == 0)
//     {
//         front = 0;
//         rear = 0;
//     }
//     else
//     {
//         rear = (rear+1)%size;
//     }
//     arr[rear] = x;
//     currSize++;
// }

// int MyQueue::pop() {
//     if (currSize == 0) return -1;
//     int el = arr[front];
//     front = (front+1)%size;
//     currSize--;
//     return el;
// }

// int MyQueue::top() {
//     if (currSize == 0) return -1;
//     return (arr[front]);
// }

// int MyQueue::getSize() {
//     return currSize;
// }

class MyQueue {
    private:
        int arr[100005];
        int front;
        int rear;

    public :
        MyQueue(){front=0;rear=0;}
        void push(int);
        int pop();
        int top();
        int size();
};

void MyQueue::push(int x) {
    arr[rear] = x;
    rear++;
}

int MyQueue::pop() {
    if (front >= rear) return -1;
    int el = arr[front];
    front++;
    return el;
}

int MyQueue::top() {
    if (front >= rear) return -1;
    return (arr[front]);
}

int MyQueue::size() {
    return (rear-front);
}

int main()
{
    MyQueue q = MyQueue();

    q.push(1);
    q.push(2);
    cout << q.top() << endl;
    cout << q.pop() << endl;;
    q.push(7);
    cout << q.top() << endl;
    cout << q.size() << endl;
    // cout << q.getSize() << endl;

    return 0;
}
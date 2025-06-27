#include <bits/stdc++.h>
using namespace std;

struct QueueNode
{
    int data;
    QueueNode *next;
    QueueNode(int a)
    {
        data = a;
        next = NULL;
    }
};

struct MyQueue {
    QueueNode *front;
    QueueNode *rear;
    int size;
    void push(int);
    int pop();
    int getTop();
    int getSize();
    MyQueue() {front = rear = NULL;size=0;}
};

void MyQueue::push(int x)
{
    QueueNode* newNode = new QueueNode(x);
    if (!front) front = newNode;
    if (rear) rear->next = newNode;
    rear = newNode;
    size++;
}

int MyQueue::pop()
{
    if (!front) return -1;
    QueueNode* temp = front;
    if (!front->next) rear = nullptr;
    front = front->next;
    int el = temp->data;
    size--;
    delete temp;
    return el;
}

int MyQueue::getTop()
{
    if (!front) return -1;
    return front->data;
}

int MyQueue::getSize()
{
    return size;
}

int main()
{
    MyQueue q = MyQueue();
    q.push(5);
    q.push(7);
    q.push(9);
    q.push(10);
    cout << q.pop() << endl;
    cout << q.getTop() << endl;
    cout << q.getSize() << endl;

    return 0;
}
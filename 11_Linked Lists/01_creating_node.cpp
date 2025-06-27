#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data1, Node* next1)
    {
        data = data1;
        next = next1;
    }

    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }
};

int main()
{
    int arr[] = {1,2,3,4,5};
    Node x = Node(arr[3], nullptr);
    cout << x.data << endl;
    cout << x.next << endl << endl;

    Node* y = new Node(arr[2]);
    cout << y << endl;
    cout << y->data << endl;
    cout << y->next << endl;

    return 0;
}
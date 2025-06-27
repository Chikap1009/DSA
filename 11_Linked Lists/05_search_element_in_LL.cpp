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

Node* convertArrToLL(vector<int>& arr)
{
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i=1 ; i<(int)arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }

    return head;
}

bool searchInLL(Node* head, int val)
{
    Node* temp = head;
    while(temp)
    {
        if (temp->data == val) return true;
        temp = temp->next;
    }

    return false;
}

int main()
{
    vector<int> vec = {12,23,31,45,56};
    Node* head = convertArrToLL(vec);

    cout << searchInLL(head,23) << endl;

    return 0;
}
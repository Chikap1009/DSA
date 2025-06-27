#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertArrToDLL(vector<int> arr)
{
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for (int i=1 ; i<(int)arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        temp->back = prev;
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head)
{
    Node* temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* bruteMiddleNode(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    int mid = len/2 + 1;
    temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == mid)
        {
            return temp;
        }
        temp = temp->next;
    }
    return head;
}

Node* optimalMiddleNode(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteMiddleNode(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalMiddleNode(head);
    print(head);

    return 0;
}
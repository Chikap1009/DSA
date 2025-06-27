#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
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

int recursiveAdd(Node* head)
{
    if (!head) return 1;

    int carry = recursiveAdd(head->next);
    head->data += carry;
    if (head->data < 10) return 0;
    head->data = 0;
    return 1;
}

Node* add1(Node* head)  {
    int carry = recursiveAdd(head);

    if (carry == 1)
    {
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

Node* reverseLL(Node* head)
{
    Node* temp = head;
    Node* prev = nullptr;
    while (temp)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}

Node* iterativeAdd1(Node* head)
{
    head = reverseLL(head);
    Node* temp = head;
    int carry = 1;
    while (temp)
    {
        temp->data += carry;
        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        temp->data = 0;
        temp = temp->next;
    }
    head = reverseLL(head);
    if (carry)
    {
        Node* newHead = new Node(1);
        newHead->next = head;
        return newHead;
    }
    return head;
}

int main()
{
    vector<int> v = {9,8,4,4,6,3,9,9,9,9,7,9};
    Node* head = convertArrToDLL(v);

    head = add1(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    head = iterativeAdd1(head);
    print(head);

    return 0;
}
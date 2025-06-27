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

Node* bruteDeleteMiddle(Node* head) {
    if (head->next == nullptr) return nullptr;
    int len = 0;
    Node* temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    int reach = len/2;
    temp = head;
    while (reach)
    {
        reach--;
        temp = temp->next;
    }
    Node* delNode = temp->next;
    temp->next = temp->next->next;
    delete delNode;
    return head;
}

Node* optimalDeleteMiddle(Node* head) {
    if (head->next == nullptr) return nullptr;
    Node* slow = head;
    Node* fast = head;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteDeleteMiddle(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalDeleteMiddle(head);
    print(head);

    return 0;
}
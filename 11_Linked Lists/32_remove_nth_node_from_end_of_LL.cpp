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

Node* bruteRemoveNthFromEnd(Node* head, int n) {
    int len = 0;
    Node* temp = head;
    while (temp)
    {
        len++;
        temp = temp->next;
    }
    int reach = len-n;
    if (reach == 0)
    {
        temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    temp = head;
    while (temp)
    {
        cnt++;
        if (cnt == reach)
        {
            Node* delNode = temp->next;
            temp->next = temp->next->next;
            delete delNode;
            return head;
        }
    }
    return head;
}

Node* optimalRemoveNthFromEnd(Node* head, int n) {
    Node* fast = head;
    for (int i=0 ; i<n ; i++)
    {
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* slow = head;
    while (fast->next)
    {
        slow = slow->next;
        fast = fast->next;
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
    head = bruteRemoveNthFromEnd(head, 4);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalRemoveNthFromEnd(head, 4);
    print(head);

    return 0;
}
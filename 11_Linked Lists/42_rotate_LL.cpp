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

Node* findKNode(Node* head, int k)
{
    Node* temp = head;
    k--;
    while(temp && k)
    {
        temp = temp->next;
        k--;
    }
    return temp;
}

void reverseLL(Node* head)
{
    Node* temp = head;
    Node* prevNode = nullptr;
    while (temp)
    {
        Node* nextNode = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = nextNode;
    }
}

Node* rotateRight(Node* head, int k) {
    if (k==0 || !head || !head->next) return head;
    Node* tail = head;
    int len = 1;
    while (tail->next)
    {
        len++;
        tail = tail->next;
    }
    if (k%len == 0) return head;
    k %= len;
    tail->next = head;
    Node* newTail = head;
    int cnt = len - k;
    cnt--;
    while (cnt)
    {
        newTail = newTail->next;
        cnt--;
    }
    head = newTail->next;
    newTail->next = nullptr;
    return head;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    Node* head = convertArrToDLL(v);

    print(head);
    head = rotateRight(head, 17);
    print(head);

    return 0;
}
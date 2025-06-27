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

Node* bruteOddEvenList(Node* head) {
    if (head == nullptr) return head;
    vector<int> arr;
    Node* temp = head;
    while (temp)
    {
        arr.push_back(temp->data);
        if (temp->next) temp = temp->next->next;
        else break;
    }

    temp = head->next;
    while (temp)
    {
        arr.push_back(temp->data);
        if (temp->next) temp = temp->next->next;
        else break;
    }

    temp = head;
    int i=0;
    while(temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

Node* optimalOddEvenList(Node* head) {
    if (head == nullptr) return head;
    Node* odd = head;
    Node* even = head->next;
    Node* second = head->next;
    while (even && even->next)
    {
        odd->next = odd->next->next;
        odd = odd->next;
        even->next = even->next->next;
        even = even->next;
    }
    odd->next = second;
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteOddEvenList(head);
    print(head);

    cout << endl;

    v = {12,24,36,48,60};
    head = convertArrToDLL(v);

    print(head);
    head = optimalOddEvenList(head);
    print(head);

    return 0;
}
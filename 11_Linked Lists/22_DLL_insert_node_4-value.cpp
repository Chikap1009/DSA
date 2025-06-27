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

Node* insertK(Node* head, int val, int x)
{
    Node* newNode = new Node(val);
    if (head == nullptr) return head;
    if (head->data == x)
    {
        newNode->next = head;
        head->back = newNode;
        return newNode;
    }
    Node* temp = head->next;
    Node* prev = head;
    while (temp)
    {
        if (temp->data == x)
        {
            newNode->back = prev;
            newNode->next = temp;
            temp->back = newNode;
            prev->next = newNode;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = insertK(head, 100, 48);
    print(head);

    return 0;
}
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

Node* insertK(Node* head, int val, int k)
{
    Node* newNode = new Node(val);
    if (head == nullptr && k==1) return newNode;
    else if (head == nullptr) return head;
    Node* temp = head;
    Node* prev = temp->back;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt == k)
        {
            if (k==1)
            {
                newNode->next = head;
                head->back = newNode;
            }
            else
            {
                newNode->back = prev;
                newNode->next = temp;
                temp->back = newNode;
                prev->next = newNode;
            }
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    if (cnt + 1 == k)
    {
        prev->next = newNode;
        newNode->back = prev;
    }
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = insertK(head, 100, 4);
    print(head);

    return 0;
}
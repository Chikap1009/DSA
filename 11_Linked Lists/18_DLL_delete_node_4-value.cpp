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

    for (int i=1 ; i<arr.size() ; i++)
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

Node* deleteK(Node* head, int val)
{
    if (head == nullptr) return head;
    if (head->data==val)
    {
        Node* temp = head;
        head = head->next;
        temp->next = nullptr;
        if (head != nullptr)
        {
            head->back = nullptr;
        }
        delete temp;
        temp = nullptr;
        return head;
    }
    Node* temp = head->next;
    while (temp)
    {
        if (temp->data == val)
        {
            if (temp->next == nullptr)
            {
                Node* prev = temp->back;
                prev->next = nullptr;
                temp->back = nullptr;
                delete temp;
                temp = nullptr;

            }
            else
            {
                Node* prev = temp->back;
                Node* forward = temp->next;
                prev->next = forward;
                forward->back = prev;
                temp->back = nullptr;
                temp->next = nullptr;
                delete temp;
                temp = nullptr;
            }
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = deleteK(head, 36);
    print(head);

    return 0;
}
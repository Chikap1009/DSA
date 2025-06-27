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

Node* bruteSegregate(Node* head) {
    int count0 = 0, count1 = 0, count2 = 0;
    Node* temp = head;
    while (temp)
    {
        if (temp->data == 0) count0++;
        else if (temp->data == 1) count1++;
        else count2++;
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (count0)
        {
            temp->data = 0;
            count0--;
        }
        else if (count1)
        {
            temp->data = 1;
            count1--;
        }
        else
        {
            temp->data = 2;
            count2--;
        }
        temp = temp->next;
    }
    return head;
}

Node* optimalSegregate(Node* head) {
    if (!head || !head->next) return head;
    Node* zeroHead = new Node(-1);
    Node* oneHead = new Node(-1);
    Node* twoHead = new Node(-1);
    
    Node* zero = zeroHead;
    Node* one = oneHead;
    Node* two = twoHead;
    
    Node* temp = head;
    
    while (temp)
    {
        if (temp->data == 0)
        {
            zero->next = temp;
            zero = zero->next;
        }
        else if (temp->data == 1)
        {
            one->next = temp;
            one = one->next;
        }
        else
        {
            two->next = temp;
            two = two->next;
        }
        temp = temp->next;
    }
    
    if (oneHead->next)
    {
        zero->next = oneHead->next;
    }
    else
    {
        zero->next = twoHead->next;
    }
    one->next = twoHead->next;
    two->next = nullptr;
    
    Node* newHead = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
    
    return newHead;
}

int main()
{
    vector<int> v = {0,1,2,2,2,2,1,1,0,0,0,1,1,0,2,0,1,2,0};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteSegregate(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalSegregate(head);
    print(head);

    return 0;
}
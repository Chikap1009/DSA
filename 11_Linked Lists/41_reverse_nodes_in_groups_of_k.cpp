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

Node* reverseKGroup(Node* head, int k) {
    Node* temp = head;
    Node* prevNode = nullptr;
    while (temp)
    {
        Node* kNode = findKNode(temp, k);
        if (kNode)
        {
            Node* nextNode = kNode->next;
            kNode->next = nullptr;
            reverseLL(temp);
            if (temp == head)
            {
                head = kNode;
                prevNode = temp;
            }
            else
            {
                prevNode->next = kNode;
                prevNode = temp;
            }
            temp = nextNode;
        }
        else
        {
            if (prevNode) prevNode->next = temp;
            break;
        }
    }
    return head;
}

int main()
{
    vector<int> v = {1,2,3,4,5,6,7,8,9,10};

    Node* head = convertArrToDLL(v);

    print(head);
    head = reverseKGroup(head, 3);
    print(head);

    return 0;
}
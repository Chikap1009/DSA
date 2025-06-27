#include <bits/stdc++.h>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data1)
    {
        data = data1;
        next = nullptr;
        prev = nullptr;
    }
};

Node* convertArrToDLL(vector<int> arr)
{
    if (arr.empty()) return nullptr;
    Node* head = new Node(arr[0]);
    Node* back = head;

    for (int i=1 ; i<(int)arr.size() ; i++)
    {
        Node* temp = new Node(arr[i]);
        temp->prev = back;
        back->next = temp;
        back = temp;
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

Node* removeDuplicates(Node* head)
{
    Node* temp = head;
    Node* nextNode = temp->next;
    while (nextNode)
    {
        if (temp->data == nextNode->data)
        {
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete duplicate;
        }
        else
        {
            temp->next = nextNode;
            nextNode->prev = temp;
            temp = nextNode;
            nextNode = nextNode->next;
        }
    }
    temp->next = nullptr;
    return head;
}

int main()
{
    vector<int> v = {1,1,1,1,1,2,2,2,2,3,3,3,3,4,4,4,4};
    Node* head = convertArrToDLL(v);

    head = removeDuplicates(head);
    print(head);

    return 0;
}
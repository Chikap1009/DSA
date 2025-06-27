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

Node* deleteAllOccurOfX(Node* head, int x) {
    Node* temp = head;
    while (temp)
    {
        if (temp->data == x)
        {
            if (temp == head) head = head->next;

            Node* prevNode = temp->prev;
            Node* nextNode = temp->next;

            if (prevNode) prevNode->next = nextNode;
            if (nextNode) nextNode->prev = prevNode;

            // temp->next = nullptr;
            // temp->prev = nullptr;

            delete temp;
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{
    vector<int> v = {2,5,2,4,8,10,2,2};

    Node* head = convertArrToDLL(v);

    head = deleteAllOccurOfX(head,2);
    print(head);

    return 0;
}
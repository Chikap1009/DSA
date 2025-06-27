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

Node* bruteSortList(Node* head) {
    vector<int> arr;
    Node* temp = head;
    while(temp)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    sort(arr.begin(),arr.end());
    temp = head;
    int i=0;
    while (temp)
    {
        temp->data = arr[i];
        i++;
        temp = temp->next;
    }
    return head;
}

Node* findMid(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right)
{
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while (left && right)
    {
        if (left->data <= right->data)
        {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else
        {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    if (left) temp->next = left;
    else temp->next = right;

    return dummyNode->next;
}

Node* mergeSort(Node* head)
{
    if (!head || !head->next) return head;

    Node* middle = findMid(head);
    Node* leftHead = head;
    Node* rightHead = middle->next;

    middle->next = nullptr;
    leftHead = mergeSort(leftHead);
    rightHead = mergeSort(rightHead);

    return merge(leftHead, rightHead);
}

Node* optimalSortList(Node* head) {
    return mergeSort(head);
}

int main()
{
    vector<int> v = {36,24,48,60,12};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteSortList(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalSortList(head);
    print(head);

    return 0;
}
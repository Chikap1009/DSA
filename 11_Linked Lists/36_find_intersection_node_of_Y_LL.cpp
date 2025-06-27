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

Node* bruteGetIntersectionNode(Node* headA, Node* headB)  {
    unordered_set<Node*> seen;
    Node* temp = headA;
    while (temp)
    {
        seen.insert(temp);
        temp = temp->next;
    }
    temp = headB;
    while (temp)
    {
        if (seen.find(temp) != seen.end()) return temp;
        temp = temp->next;
    }
    return nullptr;
}

Node* getIntersection(Node* headA, Node* headB, int diff)     {
    Node* temp1 = headA;
    Node* temp2 = headB;
    while (diff)
    {
        temp2 = temp2->next;
        diff--;
    }
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return temp1;
}

Node* betterGetIntersectionNode(Node* headA, Node* headB)  {
    Node* temp = headA;
    int n1 = 0;
    while (temp)
    {
        n1++;
        temp = temp->next;
    }
    temp = headB;
    int n2 = 0;
    while (temp)
    {
        n2++;
        temp = temp->next;
    }
    if (n1 < n2)
    {
        return getIntersection(headA, headB, n2-n1);
    }
    else
    {
        return getIntersection(headB, headA, n1-n2);
    }
}

Node* optimalGetIntersectionNode(Node* headA, Node* headB)  {
    Node* temp1 = headA;
    Node* temp2 = headB;
    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2) return temp1;
        if (!temp1) temp1 = headB;
        if (!temp2) temp2 = headA;
    }
    return temp1;
}

int main()
{
    vector<int> v1 = {12,24,36,48,60};
    Node* head1 = convertArrToDLL(v1);
    vector<int> v2 = {11,22,33,44,55};
    Node* head2 = convertArrToDLL(v2);

    Node* node1 = bruteGetIntersectionNode(head1, head2);
    Node* node2 = betterGetIntersectionNode(head1, head2);
    Node* node3 = optimalGetIntersectionNode(head1, head2);

    return 0;
}
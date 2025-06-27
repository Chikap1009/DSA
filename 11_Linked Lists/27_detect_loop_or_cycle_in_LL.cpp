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

bool bruteHasCycle(Node* head) {
    unordered_set<Node*> st;
    Node* temp = head;
    while (temp)
    {
        if (st.find(temp) != st.end()) return true;
        st.insert(temp);
        temp = temp->next;
    }
    return false;
}

bool optimalHasCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast) return true;
    }
    return false;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    cout << bruteHasCycle(head) << endl;
    cout << optimalHasCycle(head) << endl;

    return 0;
}
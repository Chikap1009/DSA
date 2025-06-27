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

Node* bruteReverseDLL(Node* head) {
    stack<int> st;
    Node* temp = head;
    while (temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    
    temp = head;
    while (temp)
    {
        temp->data = st.top();
        st.pop();
        temp = temp->next;
    }
    
    return head;
}
Node* optimalReverseDLL(Node* head) {
    Node* temp = head;
    while (temp)
    {
        // Node* before = temp->back;
        // Node* after = temp->next;
        // temp->back = after;
        // temp->next = before;
        // head = temp;
        // temp = after;

        Node* before = temp->back;
        temp->back = temp->next;
        temp->next = before;
        head = temp;
        temp = temp->back;
    }
    return head;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    head = bruteReverseDLL(head);
    print(head);

    cout << endl;

    head = convertArrToDLL(v);

    print(head);
    head = optimalReverseDLL(head);
    print(head);

    return 0;
}
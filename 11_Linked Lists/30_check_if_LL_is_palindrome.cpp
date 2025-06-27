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

bool bruteIsPalindrome(Node* head) {
    stack<int> st;
    Node* temp = head;
    while(temp)
    {
        st.push(temp->data);
        temp = temp->next;
    }
    temp = head;
    while (temp)
    {
        if (temp->data != st.top()) return false;
        st.pop();
        temp = temp->next;
    }
    return true;
}

Node* reverseLL(Node* head)
{
    Node* prev = nullptr;
    Node* temp = head;
    while (temp)
    {
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev; // newHead
}

bool optimalIsPalindrome(Node* head) {
    if (head->next == nullptr) return true;
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* newHead = reverseLL(slow->next);
    Node* first = head;
    Node* second = newHead;
    bool ans = true;
    while (second)
    {
        if (first->data != second->data)
        {
            ans = false;
            break;
        }
        first = first->next;
        second = second->next;
    }
    slow->next = reverseLL(newHead);
    return ans;
}

int main()
{
    vector<int> v = {12,24,36,24,12};

    Node* head = convertArrToDLL(v);

    print(head);
    cout << bruteIsPalindrome(head) << endl;
    cout << optimalIsPalindrome(head) << endl;

    return 0;
}
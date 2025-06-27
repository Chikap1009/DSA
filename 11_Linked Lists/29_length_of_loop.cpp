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

int bruteLengthOfCycle(Node* head) {
    unordered_map<Node*,int> hash;
    Node* temp = head;
    int cnt = 1;
    while (temp)
    {
        if (hash.find(temp) != hash.end()) return cnt - hash[temp];
        hash[temp] = cnt;
        cnt++;
        temp = temp->next;
    }
    return 0;
}

int optimalLengthOfCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast)
        {
            int len = 0;
            slow = slow->next;
            while (slow != fast)
            {
                slow = slow->next;
                len++;
            }
            return len;
        }
    }
    return 0;
}

int main()
{
    vector<int> v = {12,24,36,48,60};

    Node* head = convertArrToDLL(v);

    print(head);
    cout << bruteLengthOfCycle(head) << endl;
    cout << optimalLengthOfCycle(head) << endl;

    return 0;
}
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

vector<pair<int, int>> bruteFindPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int,int>> ans;
    Node* t1 = head;
    while (t1)
    {
        Node* t2 = t1->next;
        while (t2)
        {
            if (t1->data + t2->data == target)
            {
                ans.push_back({t1->data,t2->data});
            }
            else if (t1->data + t2->data > target)
            {
                break;
            }
            t2 = t2->next;
        }
        t1 = t1->next;
    }
    return ans;
}

vector<pair<int, int>> optimalFindPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int,int>> ans;
    Node* left = head;
    Node* right = head;
    while (right->next)
    {
        right=right->next;
    }
    while (left->data < right->data)
    {
        if (left->data + right->data == target)
        {
            ans.push_back({left->data,right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < target)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}

int main()
{
    vector<int> v = {1,2,4,5,6,8,9};

    Node* head = convertArrToDLL(v);

    vector<pair<int, int>> ans = bruteFindPairsWithGivenSum(head,7);
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }

    cout << endl;

    ans = optimalFindPairsWithGivenSum(head,7);
    for (auto x : ans)
    {
        cout << x.first << " " << x.second << endl;
    }

    return 0;
}
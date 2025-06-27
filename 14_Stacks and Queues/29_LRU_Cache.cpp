#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int x, int y) {
        key = x;
        value = y;
        prev = nullptr;
        next = nullptr;
    }
};

void deleteNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void insertAfterHead(Node* head, Node* node) {
    node->next = head->next;
    node->prev = head;
    head->next = node;
    node->next->prev = node;
}

class LRUCache {
public:
    unordered_map<int,Node*> mp;
    int limit;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        limit = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* frontNode = mp[key];
        deleteNode(frontNode);
        insertAfterHead(head, frontNode);
        return frontNode->value;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* frontNode = mp[key];
            deleteNode(frontNode);
            insertAfterHead(head, frontNode);
            mp[key]->value = value;
        }
        else {
            if (mp.size() == limit) {
                Node* delNode = tail->prev;
                deleteNode(delNode);
                mp.erase(delNode->key);
                delete delNode;
            }
            Node* newNode = new Node(key, value);
            insertAfterHead(head, newNode);
            mp[key] = newNode;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lruc = LRUCache(2);
    lruc.put(1,1);
    lruc.put(2,2);
    cout << lruc.get(1) << endl;
    lruc.put(3,3);
    cout << lruc.get(2) << endl;
    lruc.put(4,4);
    cout << lruc.get(1) << endl;
    cout << lruc.get(3) << endl;
    cout << lruc.get(4) << endl;

    return 0;
}
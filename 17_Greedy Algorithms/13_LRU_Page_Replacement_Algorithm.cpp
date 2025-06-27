#include <bits/stdc++.h>
using namespace std;

struct Node{
    int key;
    Node* prev;
    Node* next;

    Node(int x) {
        key = x;
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
    int pageFault;
    unordered_map<int,Node*> mp;
    int limit;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        limit = capacity;
        pageFault = 0;
        head = new Node(-1);
        tail = new Node(-1);
        head->next = tail;
        tail->prev = head;
    }
    
    void put(int key) {
        if (mp.find(key) != mp.end()) {
            Node* frontNode = mp[key];
            deleteNode(frontNode);
            insertAfterHead(head, frontNode);
        }
        else {
            if (mp.size() == limit) {
                Node* delNode = tail->prev;
                deleteNode(delNode);
                mp.erase(delNode->key);
                delete delNode;
            }
            Node* newNode = new Node(key);
            insertAfterHead(head, newNode);
            mp[key] = newNode;
            pageFault++;
        }
    }
};



int pageFaults(int N, int C, int pages[]){
    LRUCache lru = LRUCache(C);
    for (int i=0 ; i<N ; i++) {
        lru.put(pages[i]);
    }
    return lru.pageFault;
}

int main() {
    int pages[] = {5, 0, 1, 3, 2, 4, 1, 0, 5};

    cout << pageFaults(9, 4, pages) << endl; // ans = 8

    return 0;
}
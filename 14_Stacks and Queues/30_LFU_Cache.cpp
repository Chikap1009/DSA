#include <bits/stdc++.h>
using namespace std;

struct Node {
    int key;
    int value;
    int frequency;
    Node* prev;
    Node* next;

    Node(int k, int v) {
        key = k;
        value = v;
        frequency = 1;
        prev = next = nullptr;
    }
};

struct List {
    Node* head;
    Node* tail;

    List() {
        head = new Node (-1, -1);
        tail = new Node (-1, -1);

        head->next = tail;
        tail->prev = head;
    }

    void deleteNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insertAtHead(Node* node) {
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
};

class LFUCache {
public:
    int currSize;
    int maxSize;
    int minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, List*> freqList;
    LFUCache(int capacity) {
        currSize = 0;
        maxSize = capacity;        
    }
    
    void updateFreq(Node* node) {
        List* tempList = freqList[node->frequency];
        tempList->deleteNode(node);
        if (node->frequency == minFreq && tempList->head->next == tempList->tail) minFreq++;
        node->frequency++;
        List* list;
        if (freqList.find(node->frequency) != freqList.end()) list=freqList[node->frequency];
        else list = new List();
        freqList[node->frequency] = list;
        list->insertAtHead(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;
        Node* node = keyNode[key];
        updateFreq(node);
        int val = node->value;
        // List* tempList = freqList[node->frequency];
        // tempList->deleteNode(node);
        // if (node->frequency == minFreq && tempList->head->next == tempList->tail) minFreq++;
        // node->frequency++;
        // List* list;
        // if (freqList.find(node->frequency) != freqList.end()) list=freqList[node->frequency];
        // else list = new List();
        // list->insertAtHead(node);
        return val;
    }
    
    void put(int key, int value) {
        if (maxSize == 0) return;
        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            updateFreq(node);
            node->value = value;
        }
        else {
            if (currSize == maxSize) {
                List* list = freqList[minFreq];
                keyNode.erase(list->tail->prev->key);
                list->deleteNode(list->tail->prev);
                currSize--;
            }
            currSize++;
            Node* node = new Node(key, value);
            node->frequency = 1;
            minFreq = 1;
            List* tempList;
            if (freqList.find(minFreq) != freqList.end()) tempList = freqList[minFreq];
            else tempList = new List();
            tempList->insertAtHead(node);
            freqList[1] = tempList;
            keyNode[key] = node;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {

    LFUCache lfu = LFUCache(2);
    lfu.put(1,1);
    lfu.put(2,2);
    cout << lfu.get(1) << endl;
    lfu.put(3,3);
    cout << lfu.get(2) << endl;
    cout << lfu.get(3) << endl;
    lfu.put(4,4);
    cout << lfu.get(1) << endl;
    cout << lfu.get(3) << endl;
    cout << lfu.get(4) << endl;

    return 0;
}
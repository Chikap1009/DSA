// Run in LeetCode(138).
// Brute
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* temp = head->next;
    Node* newHead = new Node(head->val);
    Node* res = newHead;
    unordered_map<Node*, Node*> mp;
    mp[head] = newHead;

    while(temp)
    {
        res->next = new Node(temp->val);
        res = res->next;
        mp[temp] = res;
        temp = temp->next;
    }

    temp = head;
    res = newHead;
    while(temp)
    {
        Node* ogRandom = temp->random;
        Node* copyRandom = mp[ogRandom];
        res->random = copyRandom;
        temp = temp->next;
        res = res->next;
    }

    return newHead;
}

// Optimal
Node* copyRandomList(Node* head) {
    if (!head) return nullptr;
    Node* temp = head;
    while (temp)
    {
        Node* copyNode = new Node(temp->val);
        copyNode->next = temp->next;
        temp->next = copyNode;
        temp = copyNode->next;
    }
    temp = head;
    while(temp)
    {
        if (!temp->random) temp->next->random = nullptr;
        else temp->next->random = temp->random->next;
        temp = temp->next->next;
    }
    temp = head;
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    // dummyNode->next = head->next;
    // Node* res = head->next;
    while (temp)
    {
        res->next = temp->next;
        res = res->next;
        temp->next = res->next;
        if (res->next) res->next = res->next->next;
        temp = temp->next;
        // temp->next = res->next;
        // if (res->next) res->next = res->next->next;
        // temp = temp->next;
        // res = res->next;
    }
    return dummyNode->next;
}
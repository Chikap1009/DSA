// Run in Compiler.

Node* flatten2LL(Node* head1, Node* head2)
{
    Node* t1 = head1;
    Node* t2 = head2;
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;
    while(t1 && t2)
    {
        if (t1->data <= t2->data)
        {
            temp->bottom = t1;
            temp = t1;
            t1 = t1->bottom;
        }
        else
        {
            temp->bottom = t2;
            temp = t2;
            t2 = t2->bottom;
        }
        temp->next = nullptr;
    }
    if (t1)
    {
        t1->next = nullptr;
        temp->bottom = t1;
    }
    else
    {
        t2->next = nullptr;
        temp->bottom = t2;
    }
    return dummyNode->bottom;
}

Node* flattenMultipleLL(Node* head)
{
    if (!head || !head->next) return head;
    
    Node* mergedHead = flattenMultipleLL(head->next);
    return flatten2LL(head, mergedHead);
}

Node *flatten(Node *root) {
    if (!root || !root->next) return root;
    return flattenMultipleLL(root);
}
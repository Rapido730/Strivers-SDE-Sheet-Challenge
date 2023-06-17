// Problem Link : https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_8230827?challengeSlug=striver-sde-challenge&leftPanelTab=0

Node *flat(Node *list1, Node *list2)
{

    Node *l1 = list1;
    Node *l2 = list2;
    if (!l1)
        return l2;

    if (!l2)
        return l1;

    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }

    Node *res = l1;
    while (l1 && l2)
    {
        Node *temp = nullptr;

        while (l1 && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->child;
        }

        temp->child = l2;
        swap(l1, l2);
    }

    return res;
}

Node *flattenLinkedList(Node *head)

{

    if (head == NULL || head->next == NULL)
        return head;

    Node *L2 = flattenLinkedList(head->next);

    head->next = NULL;

    Node *nhead = flat(head, L2);

    return nhead;
}

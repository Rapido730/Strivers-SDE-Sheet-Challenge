// Problem Link : https://www.codingninjas.com/codestudio/problems/intersection-of-two-linked-lists_8230688?challengeSlug=striver-sde-challenge&leftPanelTab=0

Node *findIntersection(Node *headA, Node *headB)
{
    int l1 = 0, l2 = 0;
    Node *h1 = headA;
    Node *h2 = headB;
    while (h1)
    {
        h1 = h1->next;
        l1++;
    }

    while (h2)
    {
        h2 = h2->next;
        l2++;
    }

    h1 = headA;
    h2 = headB;

    if (l1 > l2)
    {
        int diff = l1 - l2;
        while (diff--)
        {
            h1 = h1->next;
        }
    }

    if (l2 > l1)
    {
        int diff = l2 - l1;
        while (diff--)
        {
            h2 = h2->next;
        }
    }

    while (h1 && h2)
    {
        if (h1 == h2)
            return h1;

        h1 = h1->next;
        h2 = h2->next;
    }

    return nullptr;
}

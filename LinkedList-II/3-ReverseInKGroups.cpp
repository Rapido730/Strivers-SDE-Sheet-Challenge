// Problem Link : https://www.codingninjas.com/codestudio/problems/reverse-nodes-in-k-group_8230709?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

Node *getListAfterReverseOperation(Node *head, int n, int b[])
{

    if (!head || !head->next)
        return head;

    int len = 0;

    Node *curr = head;

    while (curr != nullptr)
    {
        len++;
        curr = curr->next;
    }

    Node *dummy = new Node(0);
    dummy->next = head;

    Node *pre = dummy;
    Node *nex;
    int i = 0;
    while (i < n && len >= 2)
    {

        if (b[i] == 0)
        {
            i++;
            continue;
        }
        curr = pre->next;
        nex = curr->next;

        for (int j = 1; j < min(b[i], len); j++)
        {
            curr->next = nex->next;
            nex->next = pre->next;
            pre->next = nex;
            nex = curr->next;
        }

        pre = curr;

        len -= b[i++];
    }

    return dummy->next;
}
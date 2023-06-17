// Problem Link https://www.codingninjas.com/codestudio/problems/linked-list-cycle-ii_8230823?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

Node *firstNode(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    Node *entry = head;

    while (fast && fast->next)
    {
        fast = fast->next->next;

        slow = slow->next;

        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->next;
                entry = entry->next;
            }
            return slow;
        }
    }

    return nullptr;
}
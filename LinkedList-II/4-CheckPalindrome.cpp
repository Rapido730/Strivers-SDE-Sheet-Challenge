// Problem Link : codingninjas.com/codestudio/problems/palindrome-linked-list_8230717?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

bool isPalindrome(LinkedListNode<int> *head)
{
    if (!head || !head->next)
        return true;

    if (!head->next->next)
        return head->data == head->next->data;

    LinkedListNode<int> *fast = head;
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *prev = nullptr;
    while (fast && fast->next && fast->next->next)
    {
        fast = fast->next;

        if (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }

    if (fast->next)
    {
        slow = slow->next;
    }

    prev = nullptr;
    LinkedListNode<int> *next;
    while (slow && slow)
    {
        next = slow->next;
        slow->next = prev;
        prev = slow;
        slow = next;
    }

    // cout << prev->val << endl;
    LinkedListNode<int> *h = head;
    while (prev && prev)
    {
        if (prev->data != h->data)
            return false;

        prev = prev->next;
        h = h->next;
    }

    return true;
}
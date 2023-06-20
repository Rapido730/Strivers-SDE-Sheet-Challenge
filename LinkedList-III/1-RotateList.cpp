// Problem Link : https://www.codingninjas.com/codestudio/problems/rotate-linked-list_8230752?challengeSlug=striver-sde-challenge&leftPanelTab=0

/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */

Node *rotate(Node *head, int k)
{
    if (!head || !head->next)
        return head;
    int len = 0;

    Node *h = head;

    while (h)
    {
        h = h->next;
        len++;
    }

    k = k % len;

    Node *slow = head;
    Node *fast = head;

    if (k == 0)
        return head;

    while (k--)
        fast = fast->next;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *node = slow->next;
    fast->next = head;
    head = node;
    slow->next = nullptr;

    return head;
}
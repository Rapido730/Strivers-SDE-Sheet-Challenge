// Problem Link : https://www.codingninjas.com/codestudio/problems/cycle-detection-in-a-singly-linked-list_8230683?challengeSlug=striver-sde-challenge&leftPanelTab=0

bool detectCycle(Node *head)
{
    if (!head)
        return false;

    Node *fast = head;
    Node *slow = head;

    while (fast->next)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast->next == nullptr)
            return false;
        fast = fast->next;

        if (fast == slow)
            return true;
    }

    if (!fast->next)
        return false;

    return slow == fast;
}
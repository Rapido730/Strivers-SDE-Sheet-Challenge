// Problem Link : https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_8230764?challengeSlug=striver-sde-challenge&leftPanelTab=1

Node *findMiddle(Node *head)
{
    Node *fast = head, *slow = head;

    while (fast && fast->next)
    {
        fast = fast->next;
        slow = slow->next;

        if (fast->next)
        {
            fast = fast->next;
        }
    }

    return slow;
}

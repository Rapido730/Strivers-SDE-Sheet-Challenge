// Problem Link : https://leetcode.com/problems/copy-list-with-random-pointer/description/

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        Node *h = head;

        while (h)
        {
            Node *temp = new Node(h->val);
            temp->next = h->next;
            h->next = temp;
            h = h->next->next;
        }

        h = head;

        while (h)
        {

            if (h->random)
                h->next->random = h->random->next;

            h = h->next->next;
        }

        Node *dummy = new Node(0);
        Node *itr = head;
        Node *temp = dummy;
        Node *fast;
        while (itr != NULL)
        {
            fast = itr->next->next;
            temp->next = itr->next;
            itr->next = fast;
            temp = temp->next;
            itr = fast;
        }
        return dummy->next;
    }
};
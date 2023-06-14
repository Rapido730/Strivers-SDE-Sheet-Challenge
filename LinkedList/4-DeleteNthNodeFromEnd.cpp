// Problem Link : https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {

        ListNode *start = new ListNode();

        start->next = head;
        head = start;
        ListNode *fast = head;
        ListNode *slow = head;

        while (n--)
        {
            fast = fast->next;
        }

        while (fast && fast->next)
        {
            fast = fast->next;
            slow = slow->next;
        }

        // cout<<slow->val<<endl;
        slow->next = slow->next->next;

        return head->next;
    }
};
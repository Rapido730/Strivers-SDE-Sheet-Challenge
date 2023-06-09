// Problem Link : https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_8230729?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>

Node<int> *sortTwoLists(Node<int> *list1, Node<int> *list2)
{
    if (list1 == nullptr)
        return list2;
    if (list2 == nullptr)
        return list1;

    if (list1->data > list2->data)
        swap(list1, list2);

    Node<int> *res = list1;

    while (list1 && list2)
    {
        Node<int> *temp = nullptr;

        while (list1 && list1->data <= list2->data)
        {
            temp = list1;
            list1 = list1->next;
        }

        temp->next = list2;
        swap(list1, list2);
    }
    return res;
}

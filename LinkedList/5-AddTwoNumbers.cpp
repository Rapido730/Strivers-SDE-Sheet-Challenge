// Problem Link : https://www.codingninjas.com/codestudio/problems/add-two-numbers-as-linked-lists_8230833?challengeSlug=striver-sde-challenge&leftPanelTab=0

Node *addTwoNumbers(Node *l1, Node *l2)
{
    Node *dummy = new Node();

    Node *node = dummy;
    int carry = 0;
    while (l1 && l2)
    {
        int sum = l1->data + l2->data + carry;
        carry = sum / 10;
        sum %= 10;

        Node *temp = new Node(sum);

        node->next = temp;
        node = node->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    while (l1)
    {
        int sum = l1->data + carry;
        carry = sum / 10;
        sum %= 10;

        Node *temp = new Node(sum);

        node->next = temp;
        node = node->next;
        l1 = l1->next;
    }

    while (l2)
    {
        int sum = l2->data + carry;
        carry = sum / 10;
        sum %= 10;

        Node *temp = new Node(sum);

        node->next = temp;
        node = node->next;
        l2 = l2->next;
    }

    if (carry)
    {
        Node *temp = new Node(carry);

        node->next = temp;
        node = node->next;
    }

    return dummy->next;
}

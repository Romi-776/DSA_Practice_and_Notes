// (2 pointer (Fast and Slow) | T.C. = O(N), S.C  = O(1))

ListNode *middleNode(ListNode *head)
{
    ListNode *slow = head, *fast = head;

    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
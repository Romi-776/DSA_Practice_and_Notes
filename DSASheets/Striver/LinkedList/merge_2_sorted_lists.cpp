class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *head = NULL, *temp = NULL;

        // if one list is empty then the other is remaining merged sorted list
        if (!list1)
            return list2;
        else if (!list2)
            return list1;

        // list1 will contain the elements with smaller val
        if (list1->val > list2->val)
            swap(list1, list2);

        // setting the head of the meged list
        head = list1;

        // until one of the list ends
        while (list1 and list2)
        {
            // list1 will contain the elements with smaller val
            if (list1->val > list2->val)
                swap(list1, list2);

            // add each element to the merged list in sorted manner
            while (list1 and list1->val <= list2->val)
            {
                temp = list1;
                list1 = list1->next;
            }
            if (list1)
            {
                temp->next = list2;
            }
        }
        if (list2)
            temp->next = list2;

        return head;
    }
};
// NAIVE SOLUTION | T.C = O(n+m), S.C = O(n)
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        unordered_map<ListNode *, int> mp1;
        while (headA)
        {
            mp1[headA]++;
            headA = headA->next;
        }

        while (headB)
        {
            if (mp1[headB])
                return headB;
            headB = headB->next;
        }

        return NULL;
    }
};

// OPTIMIZED SOLUTION | T.C = O(max(N,M)), S.C = O(1)
// (Use 2 pointers to traverse both linked list simultaneously and then when one reaches null change it to the second ll's head then whenever they reach same node return it)
// THIS INTUITION WORKS BECAUSE WHEN THE SMALLER LINKED LIST REACHES THE END THEN AT THAT TIME
// THE LARGER LINKED LIST IS JUST BEHIND N NO. OF NODES (WHERE N IS THE DIFF. B/W TWO LISTS)
// SO THAT'S WHY WHEN THE LONGER LIST'S POINTER STARTS AGAIN FROM THE SMALLER LISTS HEAD THEN
// BOTH OF THE POINTERS ARE ALIGNED WITH EACH OTHER SO THEY WILL MEET THE INTERSECTION NODE SIMULTANEOUSLY
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA and headB)
        {
            ListNode *p1 = headA, *p2 = headB;

            while (p1 != p2)
            {
                p1 = (p1 == NULL ? headB : p1->next);
                p2 = (p2 == NULL ? headA : p2->next);
            }

            return p1;
        }
        return NULL;
    }
};
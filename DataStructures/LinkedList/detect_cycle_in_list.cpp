// NAIVE APPROACH | T.C. = O(N), S.C = O(N)
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        unordered_map<ListNode *, int> mp;
        while (head)
        {
            mp[head]++;
            head = head->next;
            if (mp[head])
                return true;
        }

        return false;
    }
};


// OPTIMIZED APPROACH | T.C. = O(N), S.C = O(1)
// TO PROVE THE INTUITION BEHIND THIS APPROACH, USE A SEGMENT OF Linked List
// AND CHECK FOR TWO CASES 1. WHEN FAST IS JUST BEHIND THE SLOW AND 2. WHEN FAST
// IS TWO NODES BEHIND THE SLOW.
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode* slow = head, *fast = head;
        
        while (fast and fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return true;
        }
        return false;
    }
};
// (Iterate first n nodes with fast and then move both fast and slow until we reach last node then delete the next node of slow)

// T.C = O(N), S.C = O(1)

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* behind = head, *ahead = head;

        // going n nodes ahead
        while (n--) {
            ahead = ahead->next;
        }

        // now traversing both pointers simultaneously until we're not at end node using ahead pointer
        // in this way behind will be just behind the node to be deleted
        while (ahead and ahead->next) {
            ahead = ahead->next;
            behind = behind->next;
        }
        
        ListNode* nodeToDelete = NULL;
        // if we've to delete a node that is not head
        if (ahead){
            nodeToDelete = behind->next;
            behind->next = behind->next->next;
        }
        else {
            nodeToDelete = head;
            head = head->next;
        } 
        
        // deleting the required node 
        delete nodeToDelete;
        return head;
    }
};
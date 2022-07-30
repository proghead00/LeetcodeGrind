// ONE PASS BOI

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(!head) return NULL;
        
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        
        ListNode* beforeLeftPtr = dummy;
        ListNode* leftPtr = head;
        
        for(int i = 0; i < left - 1; i++){ // NB: IT'S left - 1 
            beforeLeftPtr = leftPtr;
            leftPtr = leftPtr->next;
        }
        
        // simple reverse
        ListNode* prev = beforeLeftPtr;
        ListNode* cur = leftPtr;
        ListNode* nx;
        for(int i = left; i <= right; i++){
            nx = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nx;
        }
        
        // example: 
        // originally: 1 -> 2 -> 3 -> 4 -> 5 [left = 2, right = 4]
        // after simple reverse: 1 -> 4 -> 3 -> 2 -> NULL (5)
        // but I need: 1 -> 4 -> 3 -> 2 -> 5
        // hence I need to connect 1 with 4 and 2 with 5 now
        
        // connections:
        beforeLeftPtr->next = prev;
        leftPtr->next = nx;
        
        return dummy->next;
        
    }
};
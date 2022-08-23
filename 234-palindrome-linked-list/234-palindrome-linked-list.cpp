class Solution {
public:
    ListNode* rev(ListNode* &head) {
        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* nx;
        while (cur != NULL) {
            nx = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nx;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {

        // mid
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next != NULL and fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        slow->next = rev(slow->next);

        ListNode* c1 = head;
        ListNode* c2 = slow->next;
        while (c1 and c2) {
            if (c1->val != c2->val) return false;
            c1 = c1->next;
            c2 = c2->next;
        }
        return true;
    }
};
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return NULL;

        ListNode* s = head; ListNode* f = head->next->next;

        while (f and f->next) {
            f = f->next->next;
            s = s->next;
        }

        s->next = s->next->next;
        return head;
    }
};
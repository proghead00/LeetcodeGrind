class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    // recursion
    if (head == NULL or head->next == NULL) {
      return head;
    }
    ListNode *next = head->next;
    head->next = swapPairs(next->next);
    next->next = head;
    return next;
  }
};

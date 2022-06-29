class Solution {
public:
  ListNode *swapPairs(ListNode *head) {
    // recursion
    if (head == NULL or head->next == NULL) {
      return head;
    }
    ListNode *nx = head->next;
    head->next = swapPairs(nx->next);
    nx->next = head;
    return nx;
  }
};

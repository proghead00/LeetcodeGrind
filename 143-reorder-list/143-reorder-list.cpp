class Solution {
public:
  void reorderList(ListNode *head) {

    // node size <= 2
    if (!head or !head->next or !head->next->next)
      return;

    // go to the second last node
    ListNode *sl = head;
    while (sl->next->next) {
      sl = sl->next;
    }
    sl->next->next = head->next;
    head->next = sl->next;
    sl->next = NULL;
    reorderList(head->next->next);
  }
};

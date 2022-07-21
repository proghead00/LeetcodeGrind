class Solution {
public:
  ListNode* rev(ListNode* head, int left, int right) {
    int cc = right - left + 1;
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* nx;

    while (cc--) {
      nx = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nx;
    }
    // prev points to the new head that's needed
    return prev;
  }

  ListNode* reverseBetween(ListNode* head, int left, int right) {
    if (!head or !head->next or left == right) return head;

    ListNode* beforeLeft = head;
    ListNode* afterRight = head;

    // count total nodes
    ListNode* c = head; int cnt = 1;
    while (c->next) {
      cnt++;
      c = c->next;
    }
    // c points to the last node now

    ListNode* rightGiven = head;
    for (int i = 0; i < left - 2; i++) beforeLeft = beforeLeft->next;
    for (int i = 0; i < right; i++) afterRight = afterRight->next;
    for (int i = 0; i < right - 1; i++) rightGiven = rightGiven->next;

    ListNode* leftGiven;
    if (left != 1)
      leftGiven = beforeLeft->next;
    else leftGiven = head;

    // so now I have 4 pointers: leftGiven, beforeLeft, rightGiven, afterRight

    // leftGiven points to the node at left and rightGiven points to the node at right values respectively


    if (left == 1 and right == cnt) return rev(head, left, right);

    else if (left == 1) {
      ListNode* pp = rev(head, left, right);
      head = pp;
      while (pp->next) {
        pp = pp->next;
      }
      pp->next = afterRight;
      return head;
    }

    else if (right == cnt) {
      beforeLeft->next = rev(leftGiven, left, right);
      return head;
    }
    else {
      beforeLeft->next = rev(leftGiven, left, right);
      leftGiven->next = afterRight;

      return head;

    }
  }
};
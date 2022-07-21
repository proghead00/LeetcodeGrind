
class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {

    ListNode *move = head;
    int cnt = 1;
    while (cnt < left) {
      move = move->next;
      cnt++;
    }

    stack <int> s;
    ListNode *temp = move;
    while (cnt <= right) {
      s.push(move->val);
      move = move->next;
      cnt++;
    }
    
    // just pop and swap bruh
    while (!s.empty()) {
      temp->val = s.top();
      s.pop();
      temp = temp->next;
    }
    return head;
  }
};
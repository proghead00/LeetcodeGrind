class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        
        ListNode *lessNode = new ListNode(0);
        ListNode *t1 = lessNode;

        ListNode *greaterNode = new ListNode(0);
        ListNode *t2 = greaterNode;

        ListNode *move = head;
        
        while (move) {
            if (move->val < x) {
                lessNode->next = move;
                lessNode = lessNode->next;
            }

            else {
                greaterNode->next = move;
                greaterNode = greaterNode->next;
            }


            move = move->next;
        }

        lessNode->next = t2->next;
        greaterNode->next = NULL;

        return t1->next;
    }
};

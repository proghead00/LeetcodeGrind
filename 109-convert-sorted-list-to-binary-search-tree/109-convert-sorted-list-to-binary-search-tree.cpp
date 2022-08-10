class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (!head) return NULL;
        if (!head->next) return new TreeNode(head->val);

        ListNode* slow = head;
        ListNode* fast = head->next;
        while (fast->next and fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;

        // break down the list
        slow->next = NULL;

        TreeNode* root = new TreeNode(mid->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(mid->next);

        return root;
    }
};
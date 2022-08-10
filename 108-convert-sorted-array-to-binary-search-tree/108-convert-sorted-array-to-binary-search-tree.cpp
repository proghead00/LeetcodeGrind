class Solution {
public:

    TreeNode* build(int l, int r, vector<int>& nums) {
        if (l > r) return NULL;
        int mid = (l + r) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(l, mid - 1, nums);
        root->right = build(mid + 1, r, nums);

        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(0, nums.size() - 1, nums);
    }
};
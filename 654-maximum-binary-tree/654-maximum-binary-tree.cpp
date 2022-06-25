class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if (!nums.size()) return NULL;

        auto idx = max_element(nums.begin(), nums.end());
        int rootVal = *idx;

        vector<int> left;
        vector<int> right;

        for (auto it = nums.begin(); it < idx; it++)
            left.push_back(*it);

        for (auto it = idx + 1; it < nums.end(); it++)
            right.push_back(*it);

        TreeNode *root = new TreeNode(rootVal);
        root->left = constructMaximumBinaryTree(left);
        root->right = constructMaximumBinaryTree(right);

        return root;

    }
};
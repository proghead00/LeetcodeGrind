class Solution {
    unordered_map<int, int> mp;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        // if the remaining number is already present
        if (mp.count(k - root->val)) return true;

        // map the current node's value
        mp[root->val]++;

        bool left = findTarget(root->left, k);
        bool right = findTarget(root->right, k);

        return left or right;
    }

};
class Solution {
    unordered_map<int, int> mp;
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;
        if (mp.count(k - root->val)) return true;
        mp[root->val]++;
        return findTarget(root->left, k) or findTarget(root->right, k);
    }

};
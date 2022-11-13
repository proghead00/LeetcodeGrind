class Solution {
public:
    
    int help(TreeNode* root, int &ans) {
        if(!root) return 0;
        
        int l = help(root->left, ans);
        int r = help(root->right, ans);
        
        // not via root
        int temp1 = 1 + l + r;
        
        // via root
        int temp2 = max(l, r) + 1;
        
        ans = max({ans, temp1, temp2});
        
        return temp2;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        help(root, ans);
        return ans - 1;
    }
};
class Solution {
public:
    int mx = INT_MIN;
    
    int help(TreeNode* root) {
        
        if(!root) return 0;
        
        // take max values from left and right subtrees
        int left = max(0, help(root->left));
        int right = max(0, help(root->right));
        
        // we already have the max values from left and right subtrees
        mx = max(mx, left + root->val + right);
        
        // now return the best path to the parent 
        return max(left, right) + root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int x = help(root);
        return mx;
    }
};
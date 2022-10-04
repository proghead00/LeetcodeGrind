class Solution {
public:

    bool dfs(TreeNode* root, int t, int cur){
        
        if(!root) return false;
        
        cur += root->val;
        if(cur == t and !root->left and !root->right) 
            return true;
        
        bool l = dfs(root->left, t, cur);        
        bool r = dfs(root->right, t, cur); 
        
        return l or r;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        int curSum = 0;
        return dfs(root, targetSum, curSum);
    }
};
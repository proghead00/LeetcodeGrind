class Solution {
public:
    
    void help(TreeNode* root, int &cnt, int mx) {

        if(!root) return;
        
        if(root->val >= mx) {
            mx = root->val;
            cnt++;
        }
        
        help(root->left, cnt, mx);
        help(root->right, cnt, mx);
        
    }
    
    int goodNodes(TreeNode* root) {
        // total good nodes = (root is a good node?) + (total from left) + (total from right)
        int cnt = 0;
        help(root, cnt, INT_MIN);
        return cnt;
    }
};
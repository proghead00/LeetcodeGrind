class Solution {
public:
    int help(TreeNode* root, int &ans) {

        if (root == NULL) return 0;
        int l = help(root->left, ans);
        int r = help(root->right, ans);

        ans = max(ans, 1 + l + r); // via that node
        
        int height = 1 + max(l, r); // via root: WE GOTTA RETURN THIS TO THE ABOVE PARENT
        return height;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        int ans = INT_MIN;
        int x = help(root, ans);
        return ans - 1; // since ans gives # nodes but we gotta find the edges
    }
};
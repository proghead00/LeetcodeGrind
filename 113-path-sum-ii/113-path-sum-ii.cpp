class Solution {
public:
    void dfs(vector<vector<int>> &path, vector<int> &temp, int target, TreeNode* root, int curSum){
        
        if(!root) return;
        curSum += root->val;
        
        // DON'T DO THIS SINCE WE CAN HAVE -VE INPUTS
        // if(curSum > target) return; 
     
        temp.push_back(root->val);
           
        if(curSum == target and !root->left and !root->right){
            path.push_back(temp);
            temp.pop_back(); // since we are already pushing the value before
            return;
        }
        
        dfs(path, temp, target, root->left, curSum);
        dfs(path, temp, target, root->right, curSum);
        
        temp.pop_back(); 
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> temp;
        
        dfs(ans, temp, targetSum, root, 0);
        
        return ans;
    }
};
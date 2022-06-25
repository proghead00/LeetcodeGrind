class Solution {
public:
    int ans=INT_MIN;
    
    //checks whether a subtree is BST or NOT
    bool isBST(TreeNode* root,int minn,int maxx)   
    {
        if(!root)
            return true;
        if(root->val<=minn || root->val>=maxx)
            return false;
        
        return isBST(root->left,minn,root->val) && isBST(root->right,root->val,maxx);
    }
    
    
    //finds tha max sum possible in a subtree
   int maxSum(TreeNode* root,int &max_sum)
    {
        if(!root)
            return 0;
       
       int left = maxSum(root->left,max_sum);
       int right = maxSum(root->right,max_sum);
       int curr = left+right+root->val;
       max_sum=max(max_sum,curr);
       
       return curr;
    }
    
    
    //helper function to
    void help(TreeNode* root)
    {
        if(!root)
            return;
        int low=INT_MIN,high=INT_MAX; //used in BST checking for subtree as the range variables
        
        int sum=INT_MIN;  //stores the sum for a particular BST
        
        if(isBST(root,low,high))  //if the subtree is a BST
        {
            maxSum(root,sum);  //call to find the max possible sum in that BST
            ans=max(ans,sum);  
            return;            //since a node is a BST,it means all the nodes below it also form a valid BST
                                //so we don't check below
        }
        
            help(root->left);
            help(root->right);
        
    }
    
    
    int maxSumBST(TreeNode* root) 
    {
        help(root);
        if(ans==INT_MIN || ans<0)
            return 0;
        return ans;
    }
};
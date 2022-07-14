class Solution {
public:
       int idx;
       TreeNode* help(vector<int>& preorder, vector<int>& inorder, unordered_map<int, int> &mp, int start, int end) {

              if (start > end or idx > preorder.size()) return NULL;

              // create the root
              TreeNode* root = new TreeNode(preorder[idx]);

              int split = mp[preorder[idx]];
              idx++;

              root->left = help(preorder, inorder, mp, start, split - 1);
              root->right = help(preorder, inorder, mp, split + 1, end);

              return root;
       }

       TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

              // value, idx
              unordered_map<int, int> mp;
              for (int i = 0; i < inorder.size(); i++)
                     mp[inorder[i]] = i;

              idx = 0;
              return help(preorder, inorder, mp, 0, inorder.size() - 1);

       }
};
class Solution {
public:
  // -1 ==> I need a camera
  // 0 ==> I have a camera installed on me
  // 1 ==> I am already covered by some other camera from my child(ren)

  // when 1 is returned to the parent, parent is like: "my children are covered
  // (since 1 is returned), so I don't need to worry about installing a camera
  // on me. I'd rather ask MY parent to cover up for me"

  // leaf nodes have NULL as their children, and NULL means they are already
  // covered (return 1) since they do not need to explicitly get covered by the
  // parent
  // hence, leaf nodes do not need to install camera on themselves
  // leaf nodes would hence ask their parent to cover up for them

  // We'll do a post-order since I need to confirm whether one of my children
  // needs a camera
  // If any one needs a camera (that is, if -1 is returned), then I need to
  // install a camera
  // Therefore, I am doing a post-order traversal that will ensure that whether
  // either of my LEFT or RIGHT child needs a camera
  int cameras = 0;

  int help(TreeNode *root) {
    if (root == NULL)
      return 1; // null will not need any camera (so we return 1, stating that
                // it's already been covered)

    int left = help(root->left);
    int right = help(root->right);

    if (left == -1 or right == -1) {
      cameras++;
      return 0; // I have installed a camera on me
    }

    if (left == 0 or right == 0)
      return 1; // I am being covered by my children, so I don't need new camera

    // case when the child DOES NOT have a camera installed on it BUT it is
    // already covered
    // in this case, I'd ask my parent to cover me up ==> return -1 )
    return -1;
  }
  int minCameraCover(TreeNode *root) {

    // if root is left to be monitored, install a camera on it
    if (help(root) == -1)
      cameras++;
    return cameras;
  }
};

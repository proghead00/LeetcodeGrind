/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val === undefined ? 0 : val);
 *     this.left = (left === undefined ? null : left);
 *     this.right = (right === undefined ? null : right);
 * }
 */

/**
 * @param {number[]} preorder
 * @param {number[]} inorder
 * @return {TreeNode}
 */
var buildTree = function(preorder, inorder) {
    // Create a map to store indices of elements in the inorder array for quick lookup
    let inorderMap = new Map();

    for (let i = 0; i < inorder.length; i++) {
        inorderMap.set(inorder[i], i);
    }

    let preIndex = 0;

    // Helper function to build the binary tree
    let build = (start, end) => {
        if (start > end || preIndex >= preorder.length) {
            return null;
        }

        // Create a new TreeNode using the current element in the preorder array
        const newNode = new TreeNode(preorder[preIndex]);
        preIndex++;

        // Find the split index in the inorder array for the current element
        let split = inorderMap.get(newNode.val);

        // Recursively build left and right subtrees
        newNode.left = build(start, split - 1);
        newNode.right = build(split + 1, end);

        return newNode;
    };

    return build(0, inorder.length - 1);
};

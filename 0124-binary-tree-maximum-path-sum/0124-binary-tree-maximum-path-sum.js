/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @return {number}
 */

var maxPathSum = function(root) {
    
    let mx = -Infinity;

    let help = (root) => {
        
        if(!root) return 0;

        let left =  Math.max(0, help(root.left))
        let right =  Math.max(0,help(root.right))

        mx = Math.max(mx, (left + right + root.val));
 
        return Math.max(left, right) + root.val;
    }

    help(root)

    return mx;

};
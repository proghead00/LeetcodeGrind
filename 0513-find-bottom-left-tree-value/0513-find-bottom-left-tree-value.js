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
var findBottomLeftValue = function(root) {
 
    let queue = [root]
    let ans = root.val


    while(queue.length) {

        // let sz = queue.length

        // while(sz--) {

        const cur = queue.shift()
         
        if(cur.right) {
            queue.push(cur.right)
            ans = cur.right.val
        }

        if(cur.left) {
            queue.push(cur.left)
            ans = cur.left.val
        }

       }
    // }

    return ans
};
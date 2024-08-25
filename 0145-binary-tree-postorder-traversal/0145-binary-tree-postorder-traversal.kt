/**
 * Example:
 * var ti = TreeNode(5)
 * var v = ti.`val`
 * Definition for a binary tree node.
 * class TreeNode(var `val`: Int) {
 *     var left: TreeNode? = null
 *     var right: TreeNode? = null
 * }
 */
class Solution {
    private val ans: MutableList<Int> = mutableListOf();
    private fun postOrd(root: TreeNode?): Unit {
        if (root == null) return;

        postOrd(root.left);
        postOrd(root.right);
        ans.add(root.`val`);
    }
    fun postorderTraversal(root: TreeNode?): List<Int> {
        if (root == null) return emptyList();
        postOrd(root);
        return ans;
    }
}
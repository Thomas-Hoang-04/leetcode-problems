/**
 * Definition for a Node.
 * class Node(var `val`: Int) {
 *     var children: List<Node?> = listOf()
 * }
 */

class Solution {
    private val ans: MutableList<Int> = mutableListOf();
    private fun postOrder(root: Node?): Unit {
        if (root == null) return;

        ans.add(root.`val`);

        for (c in root.children.lastIndex downTo 0) postOrder(root.children[c]);
    }
    fun postorder(root: Node?): List<Int> {
        postOrder(root);
        return ans.reversed();
    }
}
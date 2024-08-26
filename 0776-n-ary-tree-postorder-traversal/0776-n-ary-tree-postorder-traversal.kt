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

        for (c in root.children) postOrder(c);

        ans.add(root.`val`);
    }
    fun postorder(root: Node?): List<Int> {
        if (root == null) return emptyList();
        postOrder(root);
        return ans;
    }
}
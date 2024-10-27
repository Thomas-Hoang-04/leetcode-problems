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
    private val nodeMap: HashMap<Int, Int> = hashMapOf()
    private val subTreeSize: HashMap<Int, Int> = hashMapOf()
    private val depths: MutableList<Int> = mutableListOf()

    private fun dfs(root: TreeNode?, depth: Int) {
        if (root == null) return

        nodeMap[root.`val`] = depths.size
        depths.add(depth)

        dfs(root.left, depth + 1)
        dfs(root.right, depth + 1)
    }

    private fun computeHeight(root: TreeNode?): Int {
        if (root == null) return 0

        val total = computeHeight(root.left) + computeHeight(root.right) + 1
        subTreeSize[root.`val`] = total

        return total
    }

    fun treeQueries(root: TreeNode?, queries: IntArray): IntArray {
        dfs(root, 0) 
        val cntNodes: Int = depths.size
        computeHeight(root)

        val maxDepthLeft: MutableList<Int> = mutableListOf(depths[0])
        val maxDepthRight: MutableList<Int> = mutableListOf(depths.last())
        for (i in 1 until cntNodes) {
            maxDepthLeft.add(max(maxDepthLeft[i - 1], depths[i]))
            maxDepthRight.add(max(maxDepthRight[i - 1], depths[cntNodes - i - 1]))
        }
        val newMaxDepthRight: List<Int> = maxDepthRight.reversed();

        val res: IntArray = IntArray(queries.size);
        var maxDepth: Int
        for (i in 0 until queries.size) {
            val q: Int = queries[i]
            val st: Int = nodeMap[q]!! - 1
            val e: Int = st + 1 + subTreeSize[q]!!

            maxDepth = maxDepthLeft[st]
            if (e < cntNodes) maxDepth = max(maxDepth, newMaxDepthRight[e])

            res[i] = maxDepth
        }
        return res
    }
}
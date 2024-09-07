/**
 * Example:
 * var li = ListNode(5)
 * var v = li.`val`
 * Definition for singly-linked list.
 * class ListNode(var `val`: Int) {
 *     var next: ListNode? = null
 * }
 */
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
    private val pattern: MutableList<Int?> = mutableListOf();
    private val prefixTab: MutableList<Int> = mutableListOf(0);
    private fun searchTree(root: TreeNode?, patternIdx: Int): Boolean {
        if (root == null) return false;
        var idx: Int = patternIdx;
        while (idx > 0 && root?.`val` != pattern[idx]) idx = prefixTab[idx - 1];
        idx += if (root?.`val` == pattern[idx]) 1 else 0;

        if (idx == pattern.size) return true;

        return searchTree(root?.left, idx) || searchTree(root?.right, idx);
    }
    fun isSubPath(head: ListNode?, root: TreeNode?): Boolean {
        pattern.add(head?.`val`);
        var patternIdx: Int = 0;
        var dh: ListNode? = head?.next;

        while (dh != null) {
            while (patternIdx > 0 && dh?.`val` != pattern[patternIdx]) patternIdx = prefixTab[patternIdx - 1];
            patternIdx += if (dh?.`val` == pattern[patternIdx]) 1 else 0;
            pattern.add(dh?.`val`);
            prefixTab.add(patternIdx);
            dh = dh?.next;
        }

        return searchTree(root, 0);
    }
}
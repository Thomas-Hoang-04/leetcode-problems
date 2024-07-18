/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    private int[] postOrder(TreeNode curr, int dist) {
        if (curr == null) return new int[12];
        int[] leafCnt = new int[12];
        if (curr.left == null && curr.right == null) {
            leafCnt[0] = 1;
            return leafCnt;
        }

        int[] left = postOrder(curr.left, dist);
        int[] right = postOrder(curr.right, dist);

        for (int i = 0; i < 10; i++) leafCnt[i + 1] += left[i] + right[i];

        leafCnt[11] += left[11] + right[11];

        for (int d1 = 0; d1 <= dist; d1++) 
            for (int d2 = 0; d2 <= dist; d2++)
                if (2 + d1 + d2 <= dist) leafCnt[11] += left[d1] * right[d2];

        return leafCnt;
    }
    public int countPairs(TreeNode root, int distance) {
        return postOrder(root, distance)[11];
    }
}
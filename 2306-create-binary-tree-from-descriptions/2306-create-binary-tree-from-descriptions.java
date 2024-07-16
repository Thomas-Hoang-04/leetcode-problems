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
    public TreeNode createBinaryTree(int[][] descriptions) {
        TreeNode[] nodes = new TreeNode[100001];
        boolean[] child = new boolean[100001];
        boolean[] par = new boolean[100001];

        for (int[] node: descriptions) {
            if (nodes[node[0]] == null) nodes[node[0]] = new TreeNode(node[0]);
            if (nodes[node[1]] == null) nodes[node[1]] = new TreeNode(node[1]);
            if (node[2] == 1) nodes[node[0]].left = nodes[node[1]];
            else nodes[node[0]].right = nodes[node[1]];

            child[node[1]] = true;
            par[node[0]] = !child[node[0]];
            par[node[1]] = !child[node[1]];
        }

        for (int i = 1; i < 100001; i++) if (par[i]) return nodes[i];

        return null;
    }
}
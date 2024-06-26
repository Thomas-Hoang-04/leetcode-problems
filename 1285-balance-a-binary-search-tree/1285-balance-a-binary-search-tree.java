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
    private List<Integer> tree = new ArrayList<>();
    private void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.left);
        tree.add(root.val);
        flatten(root.right);
    }
    private TreeNode createAVL(int st, int e) {
        if (st > e) return null;
        int mid = st + (e - st) / 2;
        return new TreeNode(tree.get(mid), createAVL(st, mid - 1), createAVL(mid + 1, e));
    }
    public TreeNode balanceBST(TreeNode root) {
        flatten(root);
        return createAVL(0, tree.size() - 1);
    }
}
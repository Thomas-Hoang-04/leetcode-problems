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
    private List<Integer> tree;
    private void flatten(TreeNode root) {
        if (root == null) return;
        flatten(root.left);
        tree.add(root.val);
        flatten(root.right);
    }
    private TreeNode createAVL(int st, int e) {
        if (st > e) return null;
        int mid = st + (e - st) / 2;
        TreeNode left = createAVL(st, mid - 1);
        TreeNode right = createAVL(mid + 1, e);
        return new TreeNode(tree.get(mid), left, right);
    }
    public Solution() {
        this.tree = new ArrayList<>();
    }
    public TreeNode balanceBST(TreeNode root) {
        if (root == null) return root;
        flatten(root);
        return createAVL(0, tree.size() - 1);
    }
}
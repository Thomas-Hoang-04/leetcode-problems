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
    private List<TreeNode> ans = new ArrayList<>();
    private boolean del[] = new boolean[1001];
    private TreeNode dfs(TreeNode root) {
        if (root == null) return root;

        root.left = dfs(root.left);
        root.right = dfs(root.right);

        if (del[root.val]) {
            if (root.left != null && !del[root.left.val]) ans.add(root.left);
            if (root.right != null && !del[root.right.val]) ans.add(root.right);
            return null;
        }

        return root;
    }
    public List<TreeNode> delNodes(TreeNode root, int[] to_delete) {
        if (root == null) return ans;
        for (int d: to_delete) del[d] = true;
        if (!del[root.val]) ans.add(root);
        dfs(root);
        return ans;
    }
}
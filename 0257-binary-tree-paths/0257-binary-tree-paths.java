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
    private final List<String> ans = new ArrayList<>();
    private void dfs(TreeNode root, StringBuilder path) {
        if (root == null) return;

        final int tmp = path.length();

        if (root.left == null && root.right == null) {
            path.append(root.val);
            ans.add(path.toString());
        } else {
            path.append(root.val);
            path.append("->");

            dfs(root.left, path);
            dfs(root.right, path);
        }

        path.setLength(tmp);
    }
    public List<String> binaryTreePaths(TreeNode root) {
        dfs(root, new StringBuilder());
        return ans;
    }
}
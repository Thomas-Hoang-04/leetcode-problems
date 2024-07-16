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
    private boolean dfs(TreeNode root, int tar, StringBuilder path) {
        if (root == null) return false;
        if (root.val == tar) return true;

        path.append("L");
        if (dfs(root.left, tar, path)) return true;
        path.setLength(path.length() - 1);

        path.append("R");
        if (dfs(root.right, tar, path)) return true;
        path.setLength(path.length() - 1);

        return false;
    }
    public String getDirections(TreeNode root, int stVal, int destVal) {
        StringBuilder stPath = new StringBuilder();
        StringBuilder destPath = new StringBuilder();
        StringBuilder dir = new StringBuilder();
        
        dfs(root, stVal, stPath);
        dfs(root, destVal, destPath);

        int intersect = 0;

        while (intersect < stPath.length() && intersect < destPath.length() && stPath.charAt(intersect) == destPath.charAt(intersect)) intersect++;

        for (int i = 0; i < stPath.length() - intersect; i++) dir.append("U");

        while (intersect < destPath.length()) dir.append(destPath.charAt(intersect++));

        return dir.toString();
    }
}
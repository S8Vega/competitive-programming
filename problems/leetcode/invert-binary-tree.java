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
    public TreeNode invertTree(TreeNode root) {
        if (root == null) return root;
        System.out.println(root.val);
        if (root.left != null) root.left = invertTree(root.left);
        if (root.right != null) root.right = invertTree(root.right);
        TreeNode aux = root.left;
        root.left = root.right;
        root.right = aux;
        return root;
    }
}
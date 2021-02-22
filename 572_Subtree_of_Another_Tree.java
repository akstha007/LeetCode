/*
572. Subtree of Another Tree
https://leetcode.com/problems/subtree-of-another-tree/
By: Ashok Shrestha
*/
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
    public boolean isIdentical(TreeNode s, TreeNode t){
        if(s==null && t==null) return true;
        if(s==null || t==null) return false;

        return (s.val==t.val) && isIdentical(s.left, t.left) && isIdentical(s.right, t.right);
    }

    public boolean isSubtree(TreeNode s, TreeNode t) {
        if(s==null && t==null) return true;
        if(s==null || t==null) return false;

        return isIdentical(s,t) || isSubtree(s.left,t) || isSubtree(s.right, t);
    }
}

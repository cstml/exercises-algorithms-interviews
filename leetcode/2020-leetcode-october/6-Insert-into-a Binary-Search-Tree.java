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
    public TreeNode insertIntoBST(TreeNode root, int val) {
        TreeNode current = root;
        TreeNode insert = new TreeNode(val);
        boolean found = false;
        
        if (current == null)
            return insert;
        
        while (found != true){
            if (val > current.val){
                if (current.right != null)
                    current=current.right;
                else{
                    found = true;
                    current.right=insert;
                }
            }else{
                if (current.left != null)
                    current=current.left;
                else{
                    found = true;
                    current.left=insert;
                }
            }   
        }
        return root;
    }
}

//https://leetcode.com/submissions/detail/405396257/?from=/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3485/

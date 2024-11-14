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
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null) return new ArrayList<List<Integer>>();
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        Queue<TreeNode>q = new LinkedList<>();
        q.offer(root);
        while(!q.isEmpty()){
            List<Integer>list = new ArrayList<Integer>();
            int size = q.size();
            for(int i = 0 ; i < size ; ++i){
                 TreeNode head = q.poll();
                 list.add(head.val);
                if(head.left!=null){ 
                    q.offer(head.left);
                }
                if(head.right!=null){
                    q.offer(head.right);
                } 
            }
            res.add(list);
        }
        return res;
    }
}
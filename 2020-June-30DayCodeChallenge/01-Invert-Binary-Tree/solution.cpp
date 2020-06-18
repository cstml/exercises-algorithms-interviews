/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* current = root;   
        TreeNode* tmp;              //temp pointer to allow to swap values
        queue<TreeNode*> q;         //queue to keep the order of the nodes as we read them
        
        if (current)                //remember to test if current is not null before pushing
            q.push(current);        //this messed up a couple times prior 
        
        while (!q.empty())          //as long as we haven't reached the last node
        {
            current = q.front();    //read the last node
            q.pop();                //pop it out of the queue
            
                                    //add it's children to the queue
            if (current->left)
                q.push(current->left);
            
            if (current->right)
                q.push(current->right);
            
            tmp = current->right;
            current->right=current->left;   //swap children
            current->left=tmp;
            cout<<current->val;
        }        
        
        return root;                //return the root
    }
};

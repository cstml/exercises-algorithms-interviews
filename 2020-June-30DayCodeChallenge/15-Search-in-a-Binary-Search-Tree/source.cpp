
 //Search in a Binary Search Tree
 
//Definition for a binary tree node.

#include <queue>
#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) 
    {
        if (root-> val == val)
            return root;
        if (root->val >= val)
        {
            if(root->left)
                return searchBST(root->left,val);
            else
                return nullptr;
        }
        else
            if (root->val<=val)
            {
                if (root->right)
                    return searchBST(root->right,val);
                else
                    return  nullptr;
            }
        return nullptr;
    }

    TreeNode* VectCreateTree(std::vector <int> vec)
    {
        std::queue <TreeNode*>q;
        TreeNode *root = new TreeNode;
        unsigned int numberElements = vec.size();
        unsigned int i=0;

        TreeNode *current;
        q.push(root);
        current = q.front();
        current->val = vec.front();
        vec.erase(vec.begin());
        i++;

        while (i<numberElements)
        {
            current = q.front();
            q.pop();

            if (i<numberElements)
            {
                current->left = new TreeNode;
                q.push(current->left);
                current->left->val = vec.front();
                vec.erase(vec.begin());
                i++;
            }
            if (i<numberElements)
            {
                current->right = new TreeNode;
                q.push(current->right);
                current->right->val = vec.front();
                vec.erase(vec.begin());
                i++;
            }
        }
        PrintTree(root);
        return root;
    }

    void PrintTree (TreeNode* p)
    {
        std::queue <TreeNode*> q;
        q.push(p);
        while (!q.empty())
        {
            std::cout<<q.front()->val<<" ";

            if (q.front()->left)
                q.push(q.front()->left);

            if (q.front()->right)
                q.push(q.front()->right);

            q.pop();
        }
        std::cout<<std::endl;
        return;
    }
};

int main()
{
    std::vector <int> a= {4,2,7,1,3};
    int search = 2;
    TreeNode* root;
    Solution s;
    root = s.VectCreateTree(a);
    s.PrintTree(s.searchBST(root,search));
    return 1;
}

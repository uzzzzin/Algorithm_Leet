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
class Solution 
{
public:

    TreeNode* invert(TreeNode* root)
    {
        if(nullptr == root)
            return root;
        
        TreeNode* tmpNode = root->left;
        root->left = root->right;
        root->right = tmpNode;

        invert(root->left);
        invert(root->right);

        return root;
    }
    
    TreeNode* invertTree(TreeNode* root) 
    {
        TreeNode* returnNode = root;
        returnNode = invert(root);
        return returnNode;
    }
};


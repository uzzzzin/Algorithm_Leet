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
    int returnDia;

    int diameter(TreeNode* root)
    {
        if(nullptr == root)
            return 0;

        int LDepth = diameter(root->left);
        int RDepth = diameter(root->right);

        if(LDepth + RDepth > returnDia)
            returnDia = LDepth + RDepth;

        if(LDepth>RDepth)
        {
            return LDepth+1;
        }
        else
        {
            return RDepth+1;
        }
    }

    int diameterOfBinaryTree(TreeNode* root) 
    {
        returnDia = 0;
        diameter(root);
        return returnDia;
    }
};

// cout << "a" << endl;
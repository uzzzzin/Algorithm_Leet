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
    int accSum = 0;
    TreeNode* ToGst(TreeNode* root)
    {
        if(nullptr == root)
            return 0;
        
        ToGst(root->right);
        //cout << root->val << endl;
        accSum+= root->val;
        root->val = accSum;
        ToGst(root->left);

        return root;
    }

    TreeNode* bstToGst(TreeNode* root) 
    {
        TreeNode* origin = root;
        ToGst(root);
        return origin;
    }
};
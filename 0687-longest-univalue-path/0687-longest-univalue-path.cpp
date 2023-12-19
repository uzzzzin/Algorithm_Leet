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
    int returnDepth;
    int rootVal;

    int longest(TreeNode* root, int _rootVal)
    {
        if(nullptr == root)
            return 0;

        cout << root->val << endl;
        int LDepth = longest(root->left, root->val);
        int RDepth = longest(root->right, root->val);

        if(LDepth + RDepth > returnDepth)
            returnDepth = LDepth + RDepth;

        if(_rootVal == root->val)
        {
            //cout << "A rootVal : "<< _rootVal << " , root->val :  " << root->val << endl;
            if(LDepth > RDepth)
                return LDepth + 1;
            else
                return RDepth + 1;
        } 
        else
        {
            //cout << "B rootVal : "<< _rootVal << " , root->val :  " << root->val << endl;
            return 0;
        }
    }
    int longestUnivaluePath(TreeNode* root) 
    { 
        returnDepth = 0;
        rootVal = 1001;
        longest(root, rootVal);
        return returnDepth;
    }
};



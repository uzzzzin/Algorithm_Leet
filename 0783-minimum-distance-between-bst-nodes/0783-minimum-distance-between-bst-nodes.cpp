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
    int minDiff = 100001;
    int prevVal;

    void Diff(TreeNode* root)
    {
        if(nullptr == root)
            return;

        Diff(root->left);

        cout << root->val << " ";

        int absDiff = abs(prevVal - root->val);
        if(absDiff < abs(minDiff))
            minDiff = absDiff;
        cout << prevVal << endl;

        prevVal = root->val;




        Diff(root->right);

        return;
    }

    int minDiffInBST(TreeNode* root) 
    { 
        prevVal = 1000001;
        Diff(root);
        return minDiff;
    }
};
        

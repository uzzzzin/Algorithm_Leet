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
    int returnSum = 0;
    //int Sum(TreeNode* rooy)
    int rangeSumBST(TreeNode* root, int low, int high) 
    {
        if(root == nullptr)
            return 0;
        if(root->val >= low && root->val <= high)
        {
            returnSum += root->val;
        }

        rangeSumBST(root->left, low, high);
        rangeSumBST(root->right, low, high);
        return returnSum;
    }
};

// 전위 순회하면서 low 부터 high까지 더해서 리턴 박기
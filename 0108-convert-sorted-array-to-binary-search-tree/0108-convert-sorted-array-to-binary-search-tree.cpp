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
    TreeNode* MakeBST(vector<int>& nums,int LIdx, int RIdx)
    {
        if(LIdx > RIdx)
            return 0;
        
        int mid = (LIdx + RIdx) /2;
        TreeNode* bst = new TreeNode(nums[mid]);

        vector<int> LVector = {};
        for(int i = 0; i <mid; ++i)
            LVector.push_back(nums[i]);

        vector<int> RVector = {};
        for(int i = mid+1;i<nums.size(); ++i)
            RVector.push_back(nums[i]);

        bst->left = MakeBST(LVector, 0, LVector.size()-1);
        bst->right = MakeBST(RVector, 0, RVector.size()-1);

        return bst;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
        TreeNode* returnNode = MakeBST(nums,0, nums.size()-1);

        return returnNode;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode 
 {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution 
{
public:

    bool isPalindrome(ListNode* head) 
    {
        vector<int> NodeVector;
        ListNode* curNode = head;
        while(true)
        {
            if(curNode->next != nullptr)
            {
                NodeVector.push_back(curNode->val);
                curNode = curNode->next;
            }
            else
            {
                NodeVector.push_back(curNode->val);
                break;
            }
        }

        int vecSize = NodeVector.size();
        for(int i =0; i < vecSize/ 2; ++i)
        {
            if(NodeVector[i] != NodeVector[vecSize-1-i])
            {
                return false;
            }
        }

        
        return true;
        
    }
};
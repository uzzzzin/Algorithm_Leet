/**
 * Definition for singly-linked list.
 * struct ListNode {
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) 
    {
        ListNode* curNode1 = list1;
        ListNode* curNode2 = list2;

        ListNode* returnNode = NULL;
        ListNode* targetNode = NULL;

        while(curNode1 != NULL && curNode2 != NULL)
        {
            if(curNode1->val <= curNode2->val)
            {
                if(returnNode == NULL) // 맨 처음
                {
                    returnNode = curNode1;
                    targetNode = curNode1;
                }
                else
                {
                   targetNode->next = curNode1;
                   targetNode = curNode1;
                }
                curNode1 = curNode1->next;
            }

            else // curNode1->val > curNode2->val
            {
                if(returnNode == NULL) // 맨 처음
                {
                    returnNode = curNode2;
                    targetNode = curNode2;
                }
                else
                {
                    targetNode->next = curNode2;
                    targetNode = curNode2;
                }
                curNode2 = curNode2->next;
            }

        }



        while(NULL != curNode1)
        {
            if(returnNode == NULL) // 맨 처음
            {
                returnNode = curNode1;
                targetNode = curNode1;
            }
            else
            {
                targetNode->next = curNode1;
                targetNode = curNode1;
            }
            curNode1 = curNode1->next;
        }

        
        while(NULL != curNode2)
        {
            if(returnNode == NULL) // 맨 처음
            {
                returnNode = curNode2;
                targetNode = curNode2;
            }
            else
            {
                targetNode->next = curNode2;
                targetNode = curNode2;
            }
            curNode2 = curNode2->next;
        }

        return returnNode;
    }
};


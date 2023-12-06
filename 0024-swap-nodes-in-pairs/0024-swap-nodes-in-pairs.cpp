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
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode* returnNode = head;

        if(NULL == head)
          return head;

        //int vVal = head->val;

        while(true)
        {
          if(head == NULL || head->next == NULL )
          {
            break;
          }
          else
          {
            int vVal = head->val;
            cout << head->val << endl;
            head->val = head->next->val;
            head->next->val = vVal;
            head = head->next->next;
            
          }

        }
        return returnNode;
    }
};
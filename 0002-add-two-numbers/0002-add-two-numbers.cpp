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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        ListNode* returnNode = new ListNode(0, nullptr);
        ListNode* aaaaNode = returnNode;
        if(NULL == l1 && NULL != l2)
          return l2;
        
        if(NULL == l2 && NULL != l1)
          return l1;

        if(NULL == l1 && NULL == l2)
          return l1;

        while(true)
        { 
          returnNode->val = returnNode->val + l1->val + l2->val;

          if( returnNode->val >= 10)
          {
            returnNode->val = returnNode->val - 10;
            returnNode->next = new ListNode(1);
          }
          else
          {
            if(!(l1->next == NULL && l2->next == NULL ))
            {
              returnNode->next = new ListNode(0);
            }
            
          }
          
          if(l1->next == NULL && l2->next != NULL )
          {
            l1->next = new ListNode(0);
          }

          if(l2->next == NULL && l1->next != NULL)
          {
            l2->next = new ListNode(0);
          }

          if(l1->next == NULL && l2->next == NULL )
          {
            break;
          }

          l1 = l1->next;
          l2 = l2->next;
          returnNode = returnNode->next;
          
        }

        return aaaaNode;
    }
};

// if(nullptr == l1)
//             {
//               break;
//               if( nullptr == l2->next)
//               {
//                 break;
//               }
//             }

//             else if(nullptr == l2)
//             {
//               if( nullptr == l1->next)
//               {
//                 break;
//               }
//             }
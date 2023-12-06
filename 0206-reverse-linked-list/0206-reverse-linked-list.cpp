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
    ListNode* reverseList(ListNode* head) 
    {

      if(NULL == head)
        return head;

      ListNode* prevNode = NULL;
      ListNode* curNode = head;
      ListNode* nextNode = NULL;

      ListNode* returnNode = NULL;

      while(true)
      {
        if(curNode == NULL)
        {
          break;
        }
        nextNode = curNode->next;
        curNode->next = prevNode;
        prevNode = curNode;
        curNode = nextNode;
      }
      returnNode = prevNode;
      return returnNode;
    }
};






// 말은 쉽지 아오

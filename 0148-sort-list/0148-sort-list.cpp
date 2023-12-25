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
    ListNode* sortList(ListNode* head) 
    {
        priority_queue<int, vector<int>, greater<int>> pq; 
        ListNode* copyHead = head;
        ListNode* returnHead = head;

        while(nullptr != head)
        {
            pq.push(head->val);

            head = head->next;
        }

        while(!pq.empty())
        {
            copyHead->val = pq.top();
            pq.pop();

            copyHead = copyHead->next;
        }

        return returnHead;
    }
};
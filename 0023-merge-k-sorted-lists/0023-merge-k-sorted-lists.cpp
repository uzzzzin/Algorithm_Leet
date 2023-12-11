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
    ListNode* mergeKLists(vector<ListNode*>& lists) 
    {
        priority_queue<int> pq; 

        if(lists.empty())
            return NULL;

        ListNode* returnList = new ListNode();


        ListNode* realReturn = returnList;

        for(int i = 0; i < lists.size(); ++i)
        {
            while(nullptr != lists[i])
            {
                pq.push(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        

        stack<int> sta = {};

        while(!(pq.empty()))
        {
            sta.push(pq.top());
            pq.pop();
        }

        if(sta.empty())
            return NULL;

        while(!(sta.empty()))
        { 
            int qVal = sta.top();
            sta.pop();
            cout << "sta top : " << qVal << endl;

            returnList->val = qVal;

            if(!(sta.empty()))
                returnList->next = new ListNode();

            returnList = returnList->next;

        }
        return realReturn;
    }
};
class Solution 
{
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int> queue = {};

        for(int i = 0; i < nums.size(); ++i)
        {
            queue.push(nums[i]);
        }

        for(int i = 1; i <= k; ++i)
        {
            if(i == k)
                return queue.top();

            queue.pop();
        }

        return queue.top();
    }
};
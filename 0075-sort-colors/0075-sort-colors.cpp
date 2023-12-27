class Solution 
{
public:
    void sortColors(vector<int>& nums) 
    {
        int begin = 0;
        int end = nums.size()-1;

        int cur = 0;

        for(int i = 0; i < nums.size(); ++i)
        {
            // if(0 == nums[begin])
            //     ++begin;
            //     ++cur;

            // if(2 == nums[end])
            //     --end;

            // if(begin >= end)
            //     return;

            if(0 == nums[cur])
            {
                swap(nums[cur], nums[begin]);
                ++begin;
                ++cur;
            }
            else if(1 == nums[cur])
                ++cur;

            else // 2 == nums[end]
            {
                swap(nums[cur], nums[end]);
                --end;

            }
        }
        
    }
};


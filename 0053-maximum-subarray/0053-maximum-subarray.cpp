class Solution 
{
public:
    int maxSubArray(vector<int>& nums) 
    {
        if(0 == nums.size())
            return 0;

        if(1 == nums.size())
            return nums[0];

        vector<int> vec;
        vec.resize(nums.size());
        vec[0] = nums[0];
        
        int sum = vec[0];

        for(int i = 1; i < nums.size(); ++i )
        {
            if(vec[i-1] + nums[i] > nums[i])
                vec[i] = vec[i-1] + nums[i];
            else
                vec[i] = nums[i];

            sum = max(sum, vec[i]);
        }
        return sum;
    }
};
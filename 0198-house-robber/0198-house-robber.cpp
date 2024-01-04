class Solution 
{
public:
    int rob(vector<int>& nums) 
    {
        if(0 == nums.size())
            return 0;

        if(1 == nums.size())
            return nums[0];

        if(2 == nums.size())
            return max(nums[0],nums[1]);

        vector<int> vec;
        vec.resize(nums.size()+1);
        vec[0] = nums[0];
        vec[1] = nums[1];
        
        int maxInt = nums[0];

        for(int i = 2; i < nums.size(); ++i)
        {
            vec[i] = maxInt + nums[i];
            maxInt = max(maxInt, vec[i-1]);
        }
        return max(vec[nums.size()-1],vec[nums.size()-2]);
    }
};

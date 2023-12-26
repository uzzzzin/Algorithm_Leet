class Solution 
{
public:
    int singleNumber(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int i = 0;

        if(nums.size() == 1)
            return nums[0];

        if(nums[0] != nums[1])
            return nums[0];
        
        if(nums[nums.size()-1] != nums[nums.size()-2])
            return nums[nums.size()-1];

        while(true)
        {
            if(i+3 == nums.size())
            { // 한 번 ++ 되어 들어옴
                return nums[i+1];
            }
            
            //중간값이 양 옆값들과 다르다면
            if(nums[i+1] != nums[i] && nums[i+1] != nums[i+2])
                return nums[i+1];
            else
                i = i+1;
        }

        return nums[i];
    }
};
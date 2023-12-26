class Solution 
{
public:
    int recurSearch(vector<int>& nums, int beginIdx, int endIdx, int target)
    {
        int midIdx = beginIdx + (endIdx - beginIdx)/2;

        // 탈출 조건
        if(beginIdx > endIdx)
            return -1;
        
        if(nums[midIdx] == target)
            return midIdx;

        if(nums[midIdx] < target) // 미드값이 타겟보다 작을 때 -> 오른쪽
            return recurSearch(nums, midIdx +1, endIdx, target);
        else // 왼쪽
            return recurSearch(nums, beginIdx, midIdx-1, target);
    }

    int search(vector<int>& nums, int target) 
    {
        return recurSearch(nums, 0, nums.size()-1, target);
    }
};
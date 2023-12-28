class Solution 
{
public:
    // int zeroSearch(vector<int>& nums, int beginIdx, int endIdx) // 애초에 재귀로 회전점 찾기 불가 !! 리턴 박을 조건 부족
    // {
    //     int midIdx = beginIdx + (endIdx - beginIdx)/2;

    //     // 탈출 조건
    //     if(beginIdx >= endIdx)
    //         return -2;

    //     if(0 == nums[midIdx])
    //         return midIdx;

    //     if(nums[midIdx] >= nums[beginIdx]) // 미드값보다  시작값이 작을 때 -> 사이에 회전이 없음 -> 오른쪽
    //         return zeroSearch(nums, midIdx +1, endIdx);
    //     else // 왼쪽
    //         return zeroSearch(nums, beginIdx, midIdx);
    // }

    int recurSearch(vector<int>& nums, int beginIdx, int endIdx, int target)
    {
        int midIdx = beginIdx + (endIdx - beginIdx)/2;
        // 탈출 조건
        if(beginIdx > endIdx)
            return -1;
        
        if(nums[midIdx] == target)
            return midIdx;

        if(target > nums[midIdx])
            return recurSearch(nums, midIdx+1, endIdx, target);
        else // target < nums[mid]
            return recurSearch(nums, beginIdx, midIdx-1, target);
    }

    int search(vector<int>& nums, int target) 
    {
        if(1 == nums.size())
        {
            if(target == nums[0])
                return 0;
            return -1;
        }

        int beginIdx = 0;
        int endIdx = nums.size()-1;
        int midIdx = beginIdx + (endIdx - beginIdx)/2;

        while(beginIdx < endIdx)
        {
            midIdx = beginIdx + (endIdx - beginIdx)/2;
            if(nums[midIdx] >= nums[0]) // 미드값보다  맨 첨이 작을 때 -> 사이에 회전이 없음 -> 오른쪽
                beginIdx = midIdx+1;
            else // nums[midIdx] < nums[beginIdx] 왼쪽
                endIdx = midIdx;
        }

        int pivot = beginIdx;
        //int pivot = endIdx;

        if(target >= nums[pivot] && target <= nums[nums.size()-1]) // 타겟이 피벗 인덱스와 배열의 끝 사이에 있다
            return recurSearch(nums,pivot,nums.size()-1,target);
        else
            return recurSearch(nums,0,pivot-1,target);

    }
};
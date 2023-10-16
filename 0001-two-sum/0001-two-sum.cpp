class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> Answer;
        /*
        nums 벡터를 순회하면서 벡터의 현재 요소와 타겟의 차를 알고, 
        그 차가 벡터의 다른 요소에 있다면 현재 인덱스와 그 다른 인덱스를 리턴할 벡터의 값으로 넣는다.
        */
        for(int i = 0; i < nums.size(); ++i)
        {
            int num = nums[i];
            int diff = target - num;

            auto iter = find(nums.begin()+i+1, nums.end(), diff);
            if(iter != nums.end())
            {
                // 현재 이터에 해당하는 거 + nums[i] = target
                Answer.push_back(i);
                Answer.push_back(iter-nums.begin());
                break;
            }
        }
        return Answer;
    }
};
// nums 벡터가 있는데 거긴 숫자들이 들어있음.
// nums들의 두 요소의 합으로  target 변수와 같은 값을 내야 함.
// 정확히 하나의 답만 가지고 있고, nums의 요소를 두 번씩 사용할 순 없다.










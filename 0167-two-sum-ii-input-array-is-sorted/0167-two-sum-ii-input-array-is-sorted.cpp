class Solution 
{
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        int LIdx = 0;
        int RIdx = numbers.size()-1;

        vector<int> returnVector;

        while(true)
        {
            int LVal = numbers[LIdx];
            int RVal = numbers[RIdx];

            if(target == LVal + RVal)
            {
                returnVector.push_back(LIdx+1);
                returnVector.push_back(RIdx+1);
                break;
            }

            if(LVal + RVal > target)
                --RIdx;
            else//(LVal + RVal < target)
                ++LIdx;
        }
        return returnVector;
    }
};
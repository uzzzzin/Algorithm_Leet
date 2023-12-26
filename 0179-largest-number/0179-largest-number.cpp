class Solution 
{
public:

    static bool compareStr(int int1, int int2)
    {
        if(to_string(int1)+ to_string(int2)>to_string(int2)+ to_string(int1))
            return true;
        return false;
    }

    string largestNumber(vector<int>& nums) 
    {
        string returnStr = "";

        sort(nums.begin(), nums.end(), compareStr);

        for(int i = 0; i < nums.size(); ++i)
        {
            returnStr += to_string(nums[i]);
        }

        if(returnStr[0] =='0'||returnStr.size() == 0)
            return "0";
        
        return returnStr;
    }
};
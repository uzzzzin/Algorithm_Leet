class Solution 
{
public:
    vector<int> topKFrequent(vector<int>& nums, int k)
    {
        vector<int> returnVec;


        unordered_map<int,int> cnt;

        for(int i = 0; i < nums.size(); ++i)
        {
            cnt[nums[i]]++;
        }
        
        for(auto iter : cnt)
        {
            cout << iter.first << " " << iter.second << endl;
        }


        while(k > returnVec.size())
        { 
            int maxVal= cnt.begin()->second;
            int maxKey = cnt.begin()->first;
            
            for(auto iter : cnt)
            {
                // if(NULL == maxVal)
                // {
                //     maxVal = iter.second;
                //     maxKey = itet.first;
                // }
                // else
                // {
                    if(iter.second > maxVal)
                    {
                        maxVal = iter.second;
                        maxKey = iter.first;
                    }
                //}
            }
            returnVec.push_back(maxKey);
            cnt.erase(maxKey);
        }
        

        return returnVec;

    }
};

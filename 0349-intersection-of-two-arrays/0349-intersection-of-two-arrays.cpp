class Solution 
{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int> returnVector;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        nums1.erase(unique(nums1.begin(),nums1.end()),nums1.end());
        nums2.erase(unique(nums2.begin(),nums2.end()),nums2.end());

        unordered_set<int> uoSet;

        if(nums1.size() > nums2.size())
        {
            for(int i = 0; i < nums1.size(); ++i)
                uoSet.insert(nums1[i]);

            for(int i = 0; i < nums2.size(); ++i)
            {
                if(uoSet.end() != uoSet.find(nums2[i])) // 찾는 게 들어있다면
                    returnVector.push_back(nums2[i]);
            }
        }
        else
        {
            for(int i = 0; i < nums2.size(); ++i)
                uoSet.insert(nums2[i]);

            for(int i = 0; i < nums1.size(); ++i)
            {
                if(uoSet.end() != uoSet.find(nums1[i])) // 찾는 게 들어있다면
                    returnVector.push_back(nums1[i]);
            }
        }
        
        return returnVector;
    }
};
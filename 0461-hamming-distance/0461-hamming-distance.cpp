class Solution 
{
public:
    int hammingDistance(int x, int y) 
    {
        int returnCnt = 0;
        for(int i = 0; i < 32; ++i)
        {
            if(bool (x & 1) != bool(y & 1))
                ++returnCnt;
            x = x >> 1;
            y = y >> 1;
        }

        return returnCnt;
    }
};
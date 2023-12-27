class Solution 
{
public:
    int hammingWeight(uint32_t n) 
    {
        int returnInt = 0;

        for(int i = 0; i < 32; ++i)
        {
            if(bool(n & 1))
                ++returnInt;

            n = n >> 1;
        }

        return returnInt;
    }
};
class Solution 
{
public:
    int numJewelsInStones(string jewels, string stones) 
    {
        int i = 0;
        int iReturn = 0;

        unordered_set<char> jewel;
        while(jewels[i] != '\0')
        {
            jewel.insert(jewels[i]);
            ++i;
        }

        i = 0;

        while(stones[i] != '\0')
        {
            if( 0!= jewel.count(stones[i]) )
            {
                iReturn = iReturn + 1;
            }
            ++i;
        }

        return iReturn;
    }
};


// 돌이랑 보석을 내가 어케 알알냄 ?? 


// 

//
//
//

// ------------------------------
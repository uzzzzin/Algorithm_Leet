class Solution 
{
public:
    int getSum(int a, int b) 
    {
        vector<int> forSize(2001,0);

        if(a > 0)
        {
            for(int i = 0; i < a; ++i)
                forSize.push_back(0);
        }
        else if(a == 0)
        {}
        else
        {
            for(int i = 0; i < abs(a); ++i)
                forSize.erase(forSize.begin());
        }

        if(b > 0)
        {
            for(int i = 0; i < b; ++i)
                forSize.push_back(0);
        }
        else if(b == 0)
        {}
        else
        {
            for(int i = 0; i < abs(b); ++i)
                forSize.erase(forSize.begin());
        }

        return forSize.size()-2001;


    }
};
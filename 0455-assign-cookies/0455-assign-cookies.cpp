class Solution 
{
public:
    int findContentChildren(vector<int>& g, vector<int>& s)  // g 먹고싶은 쿠키 개수.. s 한정된 쿠키 양
    {
        int returnInt = 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        int gg = 0;
        int ss = 0;

        while(true)
        {
            if(gg >= g.size() || ss >= s.size()) // 탈출 !!
                break;
                
            if(s[ss] >= g[gg])
            {
                ++returnInt;
                ++gg;
            }
            ++ss;
        }
        return returnInt;
    }
};


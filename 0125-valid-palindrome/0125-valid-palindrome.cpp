class Solution {
public:
    bool isPalindrome(string s) 
    {
        int iNowIdx = 0; // string의 현재 idx
        for(int i = 0; i < s.length(); ++i)
        {
            if(!(isdigit(s[iNowIdx]) || isalpha(s[iNowIdx])))
            {
                s.erase(iNowIdx,1);
                --i;
            }
            else // 지우면 안 됨.
            {
                ++iNowIdx;
            }
        }

        if(0 == s.length()) {return true;}

        int sCutLen = s.length()/2;
        
            for(int i = 0; i< s.length(); ++i)
            { 
                if(i == sCutLen) // 마지막 지점이면
                {
                    return true;
                }
                
               if(s[i] != s[s.length()-1-i])
               {
                    if(32 == abs((s[i] - s[s.length()-1-i])))
                    { 
                        if( isdigit(s[i]) || isdigit(s[s.length()-1-i])  ) 
                        {
                            return false;
                        }
                    }             
                    else
                    {
                        return false;
                    }
               }
            }
            return false;

            for(int i = 0; i<= sCutLen; ++i)
            {
                if(i == sCutLen) // 마지막 지점이면
                {
                    return true;
                }

                if(s[i] != s[s.length()-1-i]) // 글자가 다른 상황
                {
                    if(32 == abs((s[i] - s[s.length()-1-i]))) // 대소문자만 달랐던 상황
                    {
                        if( isdigit(s[i]) || isdigit(s[s.length()-1-i])  ) 
                        {
                            return false;
                        }
                    }
                    else // 아예 다른 문자였던.. 
                    {
                        return false;
                    }
                }
            }
            return false;
    }
};
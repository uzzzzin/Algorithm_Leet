class Solution 
{
public:
    bool isValid(string s) 
    {
      int i = 0;
    while(s[i] != '\0')
    {
      if(s[i] == '(' && s[i+1] == ')')
      {
        s.erase(i,2); // 쌍 지우고
        i = 0; // 다시 
      }
      else if(s[i] == '{'&& s[i+1] == '}')
      {
        s.erase(i,2);
        i = 0;
      }
      else if(s[i] == '[' && s[i+1] == ']')
      {
        s.erase(i,2);
        i = 0;
      }
      else
      {
        ++i;
      }
    }
      if(s.length() == 0)
        return true;
      else
        return false;
    }
};

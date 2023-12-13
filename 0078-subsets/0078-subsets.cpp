class Solution 
{
public:
    vector<vector<int>> returnVector;
    vector<int> numss;
    void Recursive(vector<int> _vec, int cursor)
    {
        returnVector.push_back(_vec); // 삽입조건
        if(_vec.size()==numss.size()) // 탈출조건
        {
            return;
        }

        for(int i = cursor; i < numss.size();i++)
        {
            _vec.push_back(numss[i]);
            Recursive(_vec, i+1);
            _vec.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) 
    {
        numss = nums;
        Recursive({},0);
        return returnVector;
    }
};
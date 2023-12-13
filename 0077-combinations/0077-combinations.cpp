class Solution 
{
public:

    vector<vector<int>> returnVector;

    int loopCount;
    int returnSize;

    void reCombi(vector<int> _vec, int curCursor)
    {
        if(_vec.size()== returnSize){
            returnVector.push_back(_vec);
            return;
        }

        for(int i = curCursor; i < loopCount; i++){
            _vec.push_back(i+1);
            reCombi(_vec, i+1);
            _vec.pop_back();
        }

        return;
    }


    vector<vector<int>> combine(int n, int k) 
    {
        loopCount = n;
        returnSize = k;
        reCombi({}, 0);

        return returnVector;
    }
};
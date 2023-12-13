class Solution 
{
public:
    vector<vector<int>> returnVector;
    set<vector<int>> returnSet;
    vector<int> candi;
    int targ;
    
    void Recursive(vector<int> _vec, int sum)
    {
        
        if(targ == sum)
        {
            sort(_vec.begin(), _vec.end());
            returnSet.insert(_vec);
            return;
        }
        if(targ < sum)
        {
            return;
        }

        for(int i =0; i<candi.size();i++)
        {
            int num = candi[i];

            sum += num;
            _vec.push_back(num);
            
            
            Recursive(_vec, sum);

            _vec.pop_back();
            sum -= num;

        }

    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        candi = candidates;
        targ = target;
        Recursive({}, 0);

        for(vector<int>v:returnSet)
        {
            returnVector.push_back(v);
        }
        return returnVector;
    }
};
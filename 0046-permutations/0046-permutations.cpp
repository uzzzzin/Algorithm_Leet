class Solution 
{
public:

    vector<vector<int>> returnVector; // 는 집에 있어
    vector<int> numsVector; // 커서 가리킬 놈
    vector<bool> numsSwitch; // 껐다 켰다 할 놈

    void rePermute(vector<int> _vec) // 벡터는 데이터 집어넣을 아이
    {
        if (_vec.size() == numsVector.size())
        {
            returnVector.push_back(_vec);
            return;
        }

        for(int i = 0; i < numsSwitch.size(); ++i)
        {
            if(!numsSwitch[i])
            {
                _vec.push_back(numsVector[i]);
                numsSwitch[i] = true;

                rePermute(_vec);

                numsSwitch[i] = false;
                _vec.pop_back();
            }
        }
        return;
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        numsVector = nums;
        numsSwitch.resize(nums.size()); // 기본 false
        rePermute({});
        return returnVector;
    }
};

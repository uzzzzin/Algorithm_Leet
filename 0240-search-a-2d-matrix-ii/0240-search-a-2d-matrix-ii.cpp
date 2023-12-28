class Solution 
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int n = matrix.size(); // 행
        int m = matrix[0].size(); // 열

        int RIdx = 0; // 행 
        int LIdx = m-1; // 열 

        while((RIdx < n) && (LIdx >= 0))
        {
            if(target == matrix[RIdx][LIdx])
                return true;
            
            if(matrix[RIdx][LIdx] > target)
                --LIdx;

            else // matrix[RIdx][LIdx] > target
                ++RIdx;
        }
        return false;
    }
};

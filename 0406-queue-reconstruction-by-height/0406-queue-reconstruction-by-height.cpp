class Solution 
{
public:
    static bool compare(vector<int>& a, vector<int>& b)
    {
        if(a[0] == b[0])
        {
            if(a[1] < b[1])
                return true;
            return false;
        }
        else // a[0] != b[0]
        {
            if(a[0]>b[0])
                return true;
            return false;
        }
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) 
    {
        sort(people.begin(),people.end(),compare); 
        // [[7,0],[7,1],[6,1],[5,0],[5,2],[4,4]]

        vector<vector<int>> returnVec;
        returnVec.push_back(people[0]);
        
        for(int i = 1; i < people.size(); ++i) // 삽입!!!
        {           
            returnVec.insert( returnVec.begin()+people[i][1], people[i] );
        }
        return returnVec;
    }
};
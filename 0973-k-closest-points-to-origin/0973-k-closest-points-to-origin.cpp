class Solution 
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
     {
        vector<vector<int>> returnVector;

        vector<int> dist;

        for(int i = 0; i < points.size(); ++i)
        {
            int x = points[i][0];
            int y = points[i][1];
            dist.push_back((x*x + y*y)); 
        }

        for(int i = 0; i < k; ++i)
        {
            int idx = min_element(dist.begin(), dist.end()) - dist.begin();
            dist[idx] = 10000*10000 + 1;
            returnVector.push_back(points[idx]);
        }
        return returnVector;

    }
};


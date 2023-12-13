class Solution 
{
public:
    int numIslands(vector<vector<char>>& grid) 
    {
        vector<vector<bool>> islandCheck;
        // m*n 을 알기 위함
        int m = grid.size();
        int n = grid[0].size();

        // vector<bool> tmp(n);
        // for(int i = 0; i< m ; i++)
        // {
        //     islandCheck.push_back(tmp);
        // }

        for(int i =0; i<grid.size();i++)
        {
            vector<bool> tmp;
            tmp.clear();
            for(int j = 0; j<grid[0].size();j++)
            {
                tmp.push_back(bool(grid[i][j] - '0'));
            }
            islandCheck.push_back(tmp);
        }

        // for(vector<bool> v:islandCheck){
        //     for(bool b:v){
        //         cout << b << " ";
        //     }
        //     cout << endl;
        // }

        queue<pair<int, int>> pos;
        int islandCnt = 0;
        for(int i = 0; i<islandCheck.size();i++)
        {
            for(int j =0; j<islandCheck[i].size();j++)
            {
                if(islandCheck[i][j]){
                    islandCheck[i][j] = false;
                    pos.push({i, j});

                    while(!pos.empty()){
                        pair<int, int> nowPos = pos.front();
                        pos.pop();
                        pair<int, int> up = {nowPos.first -1, nowPos.second };
                        pair<int, int> right = {nowPos.first, nowPos.second + 1};
                        pair<int, int> down = {nowPos.first + 1, nowPos.second};
                        pair<int, int> left = {nowPos.first, nowPos.second - 1};

                        // cout << islandCnt << " " << nowPos.first << " " << nowPos.second << endl;



                        if((0 <= up.first) && islandCheck[up.first][up.second]){
                            islandCheck[up.first][up.second] = false;
                            pos.push(up);
                        }
                        if((right.second < n) && islandCheck[right.first][right.second]){
                            islandCheck[right.first][right.second] = false;
                            pos.push(right);
                        }
                            
                        if((down.first < m) && islandCheck[down.first][down.second]){
                            islandCheck[down.first][down.second] = false;
                            pos.push(down);
                        }
                            
                        if((0 <= left.second) && islandCheck[left.first][left.second]){
                            islandCheck[left.first][left.second] = false;
                            pos.push(left);
                        }
                            
                            
                    }
                    islandCnt++;
                }
            }
        }

        

        if(0 == m || 0 == n)
            return 0;

        // 근데 내가 이걸 어케 푸는데
        return islandCnt;
    }
};
class Solution 
{
public:
    int climbStairs(int n) 
    {
        if(0 == n || n == 1)
            return 1;

        vector<int> vec;
        vec.resize(n+1);
        vec[0] = 1;
        vec[1] = 1;

        for(int i = 2; i < n+1; ++i)
        {
            vec[i] = vec[i-1] + vec[i-2];
        }

        return vec[n];
    }
};

// n=1 -> 1
// n=2 -> 2
// n=3 -> 3
// n=4 -> 5
// n=5 -> 8
// n=6 -> 13
// n=7 -> 21
// n=8 -> 34
// n=9 -> 55
// n=10 -> 89
// 그만...

// 찾은 규칙 .??? 
// f(n)-f(n-1) = f(n-2)
// f(n) = f(n-1) + f(n-2)

// 재귀? 안 돌고 반복문으로 될 것 같음
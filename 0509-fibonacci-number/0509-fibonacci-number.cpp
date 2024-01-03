class Solution 
{
public:
    int fib(int n) 
    {
        if(0 == n || 1 == n)
            return n;
        return fib(n-1) + fib(n-2);
    }
};
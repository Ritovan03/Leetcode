#include <vector>
using namespace std;

class Solution {
public:
int dp[101][101];
    int helper(int x,int y,int m,int n)
    {
        if(dp[x][y] != -1)
        {
            return dp[x][y];
        }
        if(x == (m-1) && y == (n-1))
        {
            return 1;
        }
        if(x >= m || y >= n)
        {
            return 0;
        }
        return dp[x][y] = helper(x+1,y,m,n) + helper(x,y+1,m,n);
    }

    int uniquePaths(int m, int n) {
        
        for(int i = 0;i<101;i++)
        {
            for(int j = 0;j<101;j++)
            {
                dp[i][j] = -1;
            }
        }
        return helper(0,0,m,n);
    }
};
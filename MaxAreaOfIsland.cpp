class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j,int row,int col)
    {
        if(i<0 || i>=row || j<0 || j>=col || grid[i][j] != 1)
        {
            return 0;
        }
        grid[i][j] = -1;
        return dfs(grid,i-1,j,row,col) + dfs(grid,i+1,j,row,col) + dfs(grid,i,j-1,row,col) + dfs(grid,i,j+1,row,col) + 1;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int maxCount = 0,count = 0;
        for(int i = 0;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(grid[i][j] == 1)
                {
                    count = dfs(grid,i,j,row,col);
                    maxCount = max(maxCount,count);
                }
            }
        }
        return maxCount;
    }
};
class Solution {
public:
    int m,n;
    vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
    void bfs(vector<vector<int>>& heights,vector<vector<bool>>& visited,queue<pair<int,int>>& q)
    {
        while(!q.empty())
        {
            
            int k = q.size();
            for(int i = 0;i<k;i++)
            {
                auto [x, y] = q.front();
                q.pop();
                for(auto& [dx,dy] : dir)
                {
                    int di = x+dx,dj = y+dy;
                    if(di<m && di>=0 && dj<n && dj>=0 && heights[di][dj]>=heights[x][y] && visited[di][dj] == false)
                    {
                        visited[di][dj] = true;
                        q.push({di,dj}); 
                    }
                }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size();
        n = heights[0].size();
        vector<vector<bool>> pacific(m, vector<bool>(n, false));
        vector<vector<bool>> atlantic(m, vector<bool>(n, false));
        queue<pair<int,int>> aocean,pocean;
        vector<vector<int>> soln;

        for(int i = 0;i<m;i++)
        {
            //pacific
            pocean.push({i,0});
            pacific[i][0] = true;
            //atlantic
            aocean.push({i,n-1});
            atlantic[i][n-1] = true;
        }

        for(int i = 0;i<n;i++)
        {
            //pacific
            pocean.push({0,i});
            pacific[0][i] = true;
            //atlantic
            aocean.push({m-1,i});
            atlantic[m-1][i] = true;
        }
        //atlantic bfs
        bfs(heights,atlantic,aocean);

        //pacific bfs
        bfs(heights,pacific,pocean);

        //checking for soln
        for(int i = 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    vector<int> patch;
                    patch.push_back(i);
                    patch.push_back(j);
                    soln.push_back(patch);
                }
            }
        }
        return soln;
    }
};
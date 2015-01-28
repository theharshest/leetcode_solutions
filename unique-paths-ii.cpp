class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        
        if(obstacleGrid[0][0]==1)
            return 0;
        
        if(m==1 && n==1)
            return 1;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(obstacleGrid[i][j]==1)
                    obstacleGrid[i][j]=-1;
            }
        }
        
        obstacleGrid[0][0]=1;

        for(int i=1; i<m; i++)
        {
            if(obstacleGrid[i][0]==-1)
                continue;

            if(obstacleGrid[i-1][0]==-1)
                obstacleGrid[i][0]=0;
            else
                obstacleGrid[i][0]=obstacleGrid[i-1][0];
        }

        for(int i=1; i<n; i++)
        {
            if(obstacleGrid[0][i]==-1)
                continue;

            if(obstacleGrid[0][i-1]==-1)
                obstacleGrid[0][i]=0;
            else
                obstacleGrid[0][i]=obstacleGrid[0][i-1];
        }

        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if(obstacleGrid[i][j]!=-1)
                {
                    int res=0;
                    if(obstacleGrid[i][j-1]!=-1)
                        res+=obstacleGrid[i][j-1];
                    if(obstacleGrid[i-1][j]!=-1)
                        res+=obstacleGrid[i-1][j];
                        
                    obstacleGrid[i][j]=res;
                }
            }
        }
        
        if(obstacleGrid[m-1][n-1]==-1)
            return 0;

        return obstacleGrid[m-1][n-1];
    }
};

class Solution {
public:
    int rec(int m , int n , vector<vector<int>>& v, vector<vector<int>>& grid){
        // Fixed base case: checks for obstacle at start
        if(m == 1 && n == 1){
           if(grid[m-1][n-1] == 0) return 1;
           else return 0;
        }
        
        if(v[m][n] != -1){
            return v[m][n];
        }
        
        int left = 0;
        int up = 0;
        
        if(grid[m-1][n-1] == 1){
            v[m][n] = 0;
            return 0;
        }
        
        if(m > 1)  left = rec(m-1 , n, v, grid);
        if(n > 1)  up = rec(m , n-1, v, grid);
        
        v[m][n] = left + up;
        return left + up;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        vector<vector<int>> v(m+1, vector<int>(n+1, -1));
        return rec(m, n, v, obstacleGrid);
    }
};
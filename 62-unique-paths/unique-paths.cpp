class Solution {
public:
    int rec(int m , int n , vector<vector<int>>& v){
        if(m == 1 && n ==1){
            return 1;
        }
        if(v[m][n]!=-1){
            return v[m][n];
        }
        int left = 0;
        int up = 0;
        if(m>1)  left = rec(m-1 , n,v);
        if(n>1)  up = rec(m , n-1,v);
        v[m][n] = left+ up;
        return left + up;
    }
    int uniquePaths(int m, int n) {
        vector <vector<int>> v(m+1 , vector<int>(n+1 , -1));
        return rec(m,n,v);
    }
};
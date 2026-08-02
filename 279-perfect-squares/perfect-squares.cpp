class Solution {
public:
    int rec(int n , vector<int> &dp){
        if(n == 1){
            return 1;
        }
        if(n <= 0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        int mini = INT_MAX;
        for(int i = 1 ; i<=sqrt(n) ; i++){
            mini = min(mini , 1+rec(n-(i*i) , dp));
        }
        dp[n] = mini;
        return mini;
        
    }
    int numSquares(int n) {
        vector<int> v(n+1 , -1);
      return rec( n , v); 

    }
};
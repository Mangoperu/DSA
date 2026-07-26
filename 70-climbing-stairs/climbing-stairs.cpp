class Solution {
public:
    int rec(int n , vector<int>& dp){
        if(n==0 || n==1){
            return 1;
        }
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n-1] = rec(n-1 , dp);
        if(n>1) dp[n-2] = rec(n-2 , dp);
        dp[n] = dp[n-1] + dp[n-2];
        return dp[n];
    }
    int climbStairs(int n) {
        vector<int> dp(n+1 , -1);
        return rec(n , dp);
    }
};
class Solution {
public:long long solve(int n , vector<long long>&dp){
        if(n == 0) return 0;
        if(n == 1) return  1;
        if(dp[n]!=-1){
            return dp[n];
        }
        dp[n] = solve(n-1 , dp) + solve(n-2 , dp);
        return dp[n];

    }
    int fib(int n) {
        vector<long long>dp(31 , -1);
       return solve(n , dp);
    }
};
class Solution {
public:
    int rec(string & c , vector<int>&t , char last , int ind , vector<vector<int>>& dp){
        if(ind == c.length()){
            return 0;
        }
        int lasti = (last == '0') ? 26 : (last - 'a');
        if(dp[ind][lasti] != -1){
            return dp[ind][lasti];
        }
        int pick = 1e9;
        if(last != c[ind]){
        pick = rec(c , t, c[ind] , ind+1 , dp);}
        int didnt =  t[ind] + rec(c, t , last , ind+1 , dp);
        dp[ind][lasti] = min(pick , didnt);
        return dp[ind][lasti];
    }
    int minCost(string colors, vector<int>& neededTime) {
        vector<vector<int>> dp(colors.length() , vector<int>(27 , -1));
        return  rec(colors , neededTime , '0' , 0 , dp);
    }
};
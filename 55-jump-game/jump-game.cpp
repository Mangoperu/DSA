class Solution {
public:
    bool rec(int ind , vector<int>& n , vector<int> &dp){
        if(ind+n[ind]>=n.size()-1){
            return true;
        }
        bool ans = 0;
        if(dp[ind]!=-1){
            return dp[ind];
        }
        for(int i = 1 ; i<=n[ind] ; i++){
            if(dp[ind+i]!=-1){
                ans |= dp[ind+i];
            }
            ans |= rec(ind+i , n , dp);
        }
        dp[ind] = ans;
        return ans;
        
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size() , -1);
        return rec(0,nums,dp);
    }
};
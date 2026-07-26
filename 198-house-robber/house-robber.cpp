class Solution {
public:
    int rec(int n , vector<int>& nums , vector<int>&dp){
        if(n == 0){
            return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       
         int left = nums[n] + rec(n-2 , nums , dp);
         int right = nums[n] + rec(n-3 , nums ,dp);
         dp[n] = max(left , right);
         return max(right , left);
    }
    int rob(vector<int>& nums) {
       int n = nums.size() - 1;
       vector<int> dp(n+1 , -1);
       return max(rec(n-1 , nums , dp) ,rec(n , nums , dp));
    }
};
class Solution {
public:
    bool rec(int i, int sum1, vector<int>& nums, int target, vector<vector<int>>& dp){
        if(sum1 == target) return true;
        if(sum1 > target || i >= nums.size()) return false;
        
        if(dp[i][sum1] != -1) {
            return dp[i][sum1];
        }
        
        bool took = rec(i + 1, sum1 + nums[i], nums, target, dp);
        bool dint = rec(i + 1, sum1, nums, target, dp);
        
        return dp[i][sum1] = (took || dint);
    }
    
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num : nums){
            sum += num;
        }
        
        if(sum % 2 != 0) return false;
        
        int target = sum / 2;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, -1));
        
        return rec(0, 0, nums, target, dp);
    }
};
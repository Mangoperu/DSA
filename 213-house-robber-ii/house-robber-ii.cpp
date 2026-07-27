class Solution {
public:
int rec(int n , vector<int>& nums , vector<int>&dp ){
        if(n == 0){
           return nums[0];
        }
        if(n<0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
       
         int left = nums[n] + rec(n-2 , nums , dp );
         int right = nums[n] + rec(n-3 , nums ,dp );
         dp[n] = max(left , right);
         return max(right , left);
    }
    int rob(vector<int>& nums) {
          int n = nums.size() - 1;
          if(n==0) return nums[0];
          vector<int> temp;
          for(int i = 1 ; i<=n ; i++){
            temp.push_back(nums[i]);
          }
       vector<int> dp1(n+1 , -1);
       vector<int> dp2(n+1 , -1);
       int max_first_half = max(rec(n - 1, nums, dp1), rec(n - 2, nums, dp1));
       int max_second_half = max(rec(n - 1, temp, dp2), rec(n - 2, temp, dp2));
       return max(max_first_half, max_second_half);
    }
};
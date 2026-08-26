class Solution {
public:
    bool rec(int ind , vector<int>& n , vector<int> &dp){
        if(ind+n[ind]>=n.size()-1){
            return true;
        }
        
        // 1. Check if we ALREADY solved for this index
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        bool ans = 0;
        for(int i = 1 ; i<=n[ind] ; i++){
            if(dp[ind+i]!=-1){
                ans |= dp[ind+i];
            } else {
                // 2. Only recurse if we haven't solved it yet
                ans |= rec(ind+i , n , dp);
            }
            
            // 3. Early exit: stop checking other jumps if we already found a path
            if(ans) break; 
        }
        
        // 4. Save the answer in the dp array before returning!
        return dp[ind] = ans; 
    }
    
    bool canJump(vector<int>& nums) {
        if(nums.size() <= 1) return true; // Safety check for arrays of size 1
        
        vector<int>dp(nums.size() , -1);
        return rec(0,nums,dp);
    }
};
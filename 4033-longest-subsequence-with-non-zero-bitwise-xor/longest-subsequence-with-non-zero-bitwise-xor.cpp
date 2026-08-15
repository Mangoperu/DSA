class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int zeros = 0;
        for(int i = 0 ;i<n ; i++){
            ans ^= nums[i];
            if(nums[i] == 0){
                zeros++;
            }
        }
        if(zeros == n){
            return 0;
        }
        if(ans==0){
            return n-1;
        }
        else{
            return n;
        }
    }
};
class Solution {
public:
    int rec(int i , int j , vector<int> &nums){
        if(i == j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        int take1 = nums[i] + min(rec( i+2 , j , nums) , rec(i+1 , j-1 , nums));
        int take2 = nums[j] + min(rec(i+1 , j-1 , nums) , rec(i , j-2 , nums));
        return max(take1 , take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int total  = accumulate(nums.begin() , nums.end() , 0);
        int p2 = total - rec(0,nums.size()-1 , nums);
        if(rec(0,nums.size()-1 , nums)>=p2){
            return true;
        }
        else{
            return false;
        }
    }
};
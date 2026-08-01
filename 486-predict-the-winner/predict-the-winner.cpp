class Solution {
public:
    int rec(int i , int j , vector<int> &nums, vector<vector<int>>&v){
        if(i == j){
            return nums[i];
        }
        if(i>j){
            return 0;
        }
        if(v[i][j] != -1){
            return v[i][j];
        }
        int take1 = nums[i] + min(rec( i+2 , j , nums,v) , rec(i+1 , j-1 , nums,v));
        int take2 = nums[j] + min(rec(i+1 , j-1 , nums,v) , rec(i , j-2 , nums,v));
        v[i][j] = max(take1 , take2);
        return max(take1 , take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        vector<vector<int>> v(21 , vector<int>(21 , -1));
        int total  = accumulate(nums.begin() , nums.end() , 0);
        int p2 = total - rec(0,nums.size()-1 , nums , v);
        
        if(rec(0,nums.size()-1 , nums , v)>=p2){
            return true;
        }
        else{
            return false;
        }
    }
};
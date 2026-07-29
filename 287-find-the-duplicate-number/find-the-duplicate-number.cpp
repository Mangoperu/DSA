class Solution {
public:
    int findDuplicate(vector<int>& nums) {
         int n = nums.size();
          map<int , int> m;
        for(int i = 0 ; i<n ; i++){
            m[nums[i]]++;
            if(m[nums[i]] == 2){
                return nums[i];
            }
        }
        return -1;
    }
};
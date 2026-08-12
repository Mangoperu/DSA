class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>pref;

        pref.push_back(nums[0]);
        for(int i = 1; i < n ; i++){
            pref.push_back(pref[i-1]+nums[i]);
        }
        unordered_map<int , int> m;
        m[0]++;
        int ans = 0;
        for(int i = 0; i<n ; i++){
            if(m.find(pref[i]-k) != m.end()){
                ans += m[pref[i]-k];
            }
            m[pref[i]]++;
        }
        return ans;
    }
};
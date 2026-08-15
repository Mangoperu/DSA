class Solution {
public:
    void rec(int ind, int target, vector<int>& candidates, vector<int>& ds, vector<vector<int>>& ans) {
        // Base case: If we've hit our target sum, add it to our answer list
        if (target == 0) {
            ans.push_back(ds);
            return;
        }
        
        for (int i = ind; i < candidates.size(); i++) {
            // Skip duplicates: If the current element is the same as the previous one
            // AND it's not the first element in this recursive level, skip it.
            if (i > ind && candidates[i] == candidates[i - 1]) {
                continue;
            }
            
            // Optimization: If the current number is greater than the remaining target,
            // we can stop checking further because the array is sorted.
            if (candidates[i] > target) {
                break;
            }
            
            // Pick the element
            ds.push_back(candidates[i]);
            
            // Recurse (i + 1 because we can't reuse the same element)
            rec(i + 1, target - candidates[i], candidates, ds, ans);
            
            // Backtrack
            ds.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // 1. Sort the array so identical numbers are next to each other
        sort(candidates.begin(), candidates.end());
        
        vector<int> ds;
        vector<vector<int>> ans;
        
        // 2. Start recursion
        rec(0, target, candidates, ds, ans);
        
        return ans;
    }
};
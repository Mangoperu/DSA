class Solution {
private:
    void markSuspicious(int current, const vector<vector<int>>& adjList, vector<bool>& isSuspicious) {
        isSuspicious[current] = true;
        for (int nextMethod : adjList[current]) {
            if (!isSuspicious[nextMethod]) {
                markSuspicious(nextMethod, adjList, isSuspicious);
            }
        }
    }

public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        // Build the adjacency list
        vector<vector<int>> adjList(n);
        for (const auto& invoke : invocations) {
            adjList[invoke[0]].push_back(invoke[1]);
        }
        
       
        vector<bool> isSuspicious(n, false);
        markSuspicious(k, adjList, isSuspicious);
        
       
        bool hasExternalCall = false;
        for (const auto& invoke : invocations) {
            int caller = invoke[0];
            int callee = invoke[1];
            
            if (!isSuspicious[caller] && isSuspicious[callee]) {
                hasExternalCall = true;
                break; // No need to check further
            }
        }
        
        
        vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (hasExternalCall || !isSuspicious[i]) {
                remaining.push_back(i);
            }
        }
        
        return remaining;
    }
};
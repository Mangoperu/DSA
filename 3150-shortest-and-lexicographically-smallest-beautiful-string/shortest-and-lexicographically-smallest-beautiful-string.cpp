class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
     int n = s.size();
        vector<int> onesIdx;
        for (int i = 0; i < n; i++)
            if (s[i] == '1') onesIdx.push_back(i);

        if ((int)onesIdx.size() < k) return "";

        int minLen = INT_MAX;
        for (int i = 0; i + k - 1 < (int)onesIdx.size(); i++) {
            int length = onesIdx[i + k - 1] - onesIdx[i] + 1;
            minLen = min(minLen, length);
        }
        string best = "";
        for (int i = 0; i + minLen <= n; i++) {
            string sub = s.substr(i, minLen);
            int cnt = count(sub.begin(), sub.end(), '1');
            if (cnt == k) {
                if (best.empty() || sub < best) {
                    best = sub;
                }
            }
        }

        return best;
    }
};
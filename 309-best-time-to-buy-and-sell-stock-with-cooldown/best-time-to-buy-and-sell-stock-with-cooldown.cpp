class Solution {
public:
    int rec(int i, int h, vector<int>& prices, vector<vector<int>>& v) {
        if (i >= (int)prices.size()) return 0;
        if (v[i][h] != -1) return v[i][h];

        if (h == 1) {
            int sell = prices[i] + rec(i + 2, 0, prices, v);
            int hold = rec(i + 1, 1, prices, v);
            v[i][h] = max(sell, hold);
        } else {
            int buy = -prices[i] + rec(i + 1, 1, prices, v);
            int hold = rec(i + 1, 0, prices, v);
            v[i][h] = max(buy, hold);
        }
        return v[i][h];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> v(n + 2, vector<int>(2, -1));
        return rec(0, 0, prices, v);
    }
};
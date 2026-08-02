class Solution {
public:
    int rec( vector<int> &piles , int a , int b , vector<vector<int>> &v ){
        if(a == b ){
            return piles[a];
        }
        if(a>b){
            return 0;
        }
        if(v[a][b] != -1){
            return v[a][b];
        }
        int left  = piles[a] + min(rec(piles , a+2 , b , v) , rec(piles , a+1 , b-1 , v));
        int right = piles[b] + min(rec(piles , a+1 , b-1 , v) , rec(piles , a , b-2 , v));
        v[a][b] = max(left , right);
        return v[a][b];
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int a  = 0;
        int b = n-1;
        vector<vector<int>> v(n+1 , vector<int>(n+1 , -1));
        int p1 = rec(piles , a , b , v);
        int sum = accumulate(piles.begin() , piles.end() , 0);
        int p2 = sum - p1;
        if(p2>p1){
            return false;
        }
        else{
            return true;
        }

    }
};
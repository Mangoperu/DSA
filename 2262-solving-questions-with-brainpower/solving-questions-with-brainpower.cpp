class Solution {
public:
    long long rec(long long a , vector<vector<int>>& q , vector<long long> &v){
        if( a >= q.size()){
            return 0;
        }
        if(v[a]!=-1){
            return v[a];
        }
        long long pick = q[a][0] + rec(a+q[a][1]+1 , q ,v);
        long long didnt =  rec(a+1 , q , v);
        v[a] = max(pick , didnt);
        return v[a];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> v(questions.size()+1 , -1);
        return rec(0 ,questions, v);
    }
};
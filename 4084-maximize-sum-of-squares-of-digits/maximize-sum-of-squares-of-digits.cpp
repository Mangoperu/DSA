class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string s;
        for(int i = 0 ; i<num ; i++){
            if(sum-9>=0){
                s.push_back('9');
                sum -= 9;
            }
            else if(num>0){
                s.push_back('0'+sum);
                sum = 0;
            }
            else{
                s.push_back('9');
            }
        }
        if(sum>0){
            return "";
        }
        return s;
    }
};
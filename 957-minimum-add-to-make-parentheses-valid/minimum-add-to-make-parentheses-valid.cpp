class Solution {
public:
    int minAddToMakeValid(string s) {
        int closed = 0;
        int hehe = 0;
        int n = s.length();
        for(int i = 0 ; i<n ; i++){
            if(s[i] == '('){
                hehe++;
            }
            else{
                if(hehe>0){
                    hehe--;
                }
                else{
                    closed++;
                }
            }
        }
        return hehe+closed;
    }
};
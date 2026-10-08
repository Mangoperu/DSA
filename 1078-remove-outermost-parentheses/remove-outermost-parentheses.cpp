class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        string ans;
        int len = 0;
        for(int i = 0 ; i<n ; i++){
            for(int j = i ; j<n ; j++){
                if(s[j] == '('){
                    len++;
                }
                else{
                    len--;
                }
                if(len == 0){
                    for(int k = i+1 ; k<j ; k++){
                        ans.push_back(s[k]);
                    }
                    i = j+1;
                }
            }
        
        }


                return ans;
    }
};
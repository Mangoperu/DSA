class Solution {
public:
    string digitSum(string s, int k) {
       
        bool formed = false;
        if(s.length()>k)formed = true;
        while(formed){
             string a;
            int sum = 0;
            for(int i = 0 ; i<s.length() ; i++){
                sum = sum+ (s[i]-'0');
                if((i+1)%k == 0 || i==s.length()-1){
                    a = a + to_string(sum);
                    sum = 0;
                }
            }
            s = a;
            if(s.length()<=k){
                return s;
            }
        }
        return s;
    }
};
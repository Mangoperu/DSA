class Solution {
public:
    int minimumPushes(string word) {
        vector<int>v(26 , 0);
        int n = word.length();
        int one = 0;
        int two = 0;
        int three = 0;
        long long ans= 0;
        for(int i = 0 ; i<n ; i++ ){
            if(v[word[i]-'a'] == 0 ){
                if(one<8){
                    v[word[i]-'a'] = 1;
                    one++;
                }
                 else if(two<8){
                    v[word[i]-'a'] = 2;
                    two++;
                }
                else if(three<8){
                    v[word[i]-'a'] = 3;
                    three ++;
                }
                else{
                    v[word[i]-'a'] = 4;
                }
            }
            ans = ans + v[word[i]-'a'];
        }
        return ans;
    }
};
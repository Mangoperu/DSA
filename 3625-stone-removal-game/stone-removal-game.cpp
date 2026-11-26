class Solution {
public:
    bool canAliceWin(int n) {
        int st = 10;
        while(n>=0){
            n-=st;
            st--;
        }
        if(st%2 != 0){
            return false;
        }
        else{
            return true;
        }
    }
};
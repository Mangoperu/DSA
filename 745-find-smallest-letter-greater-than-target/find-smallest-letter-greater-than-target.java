class Solution {
    public char nextGreatestLetter(char[] letters, char target) {
        int a = 0;
        int b = letters.length-1;
        int mid = a + (b-a)/2;
        char ans = letters[0];
        while(b>=a){
            if(target<letters[mid]){
                ans = letters[mid];
                b = mid-1;
            }
            else{
                a = mid+1;
            }
              mid = a + (b-a)/2;
        }
        return ans;

    }
}
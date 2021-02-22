/*
443. String Compression
https://leetcode.com/problems/string-compression/
By: Ashok Shrestha
*/
class Solution {
    public int compress(char[] chars) {
        int n = chars.length;        
        if(n<=1)
            return chars.length;
        
        int res = 0;
        int i=0,j=0;
        while(j<n){
            chars[res++] = chars[i];
            while(j<n && chars[i]==chars[j]){
                j++;
            }
            
            if(j-i>1){
                int diff = j -i;
                for(char c: Integer.toString(j-i).toCharArray()){
                    chars[res++] = c;
                }
            }
            i = j;
        }
        
        return res;
    }
}
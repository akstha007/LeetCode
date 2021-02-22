/*
 * 917. Reverse Only Letters
 * https://leetcode.com/problems/reverse-only-letters/
 * By: Ashok Shrestha
 */
class Solution {
    public String reverseOnlyLetters(String S) {
        int n = S.length();
        char[] res = new char[n];
        int i=0, j = n-1;
        while(i<=j){
            while(i<n && !Character.isLetter(S.charAt(i))){
                res[i] = S.charAt(i);
                i++;
            }
            while(j>=0 && !Character.isLetter(S.charAt(j))){
                res[j] = S.charAt(j);
                j--;
            }

            if(i<n)
                res[i] = S.charAt(j);

            if(j>=0)
                res[j] = S.charAt(i);

            i++;
            j--;
        }

        return String.valueOf(res);
    }
}

/*
 * 953. Verifying an Alien Dictionary
 * https://leetcode.com/problems/verifying-an-alien-dictionary/
 * By: Ashok Shrestha
 */
class Solution {
    public boolean isAlienSorted(String[] words, String order) {
        for(int i=0;i<words.length-1;i++){
            String word1 = words[i];
            String word2 = words[i+1];
            if(!compare(word1,word2, order)) return false;
        }

        return true;
    }

    public boolean compare(String word1, String word2, String order){
        int i=0;
        while(i<word1.length() && i<word2.length()){
            char c1 = word1.charAt(i);
            char c2 = word2.charAt(i);
            if(c1!=c2){
                int i1 = order.indexOf(c1);
                int i2 = order.indexOf(c2);
                if(i1>i2)
                    return false;
                else if (i1<i2)
                    return true;
            }
            i++;
        }

        return !(i < word1.length());

    }
}

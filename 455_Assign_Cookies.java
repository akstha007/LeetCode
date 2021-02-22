/*
 * 455. Assign Cookies
 * https://leetcode.com/problems/assign-cookies/
 * By: Ashok Shrestha
 */

class Solution {
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int gi = 0, si = 0;
        int res = 0;
        while(gi<g.length && si<s.length){
            if(g[gi]<=s[si]){
                res++;
                gi++;
                si++;
            } else {
                si++;
            }
        }

        return res;
    }
}


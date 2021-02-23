/*
 * 415. Add Strings
 * https://leetcode.com/problems/add-strings/
 * By: Ashok Shrestha
 */
class Solution {
    public String addStrings(String num1, String num2) {
        int n1 = num1.length(), n2 = num2.length();
        int i1 = n1-1, i2 = n2-1;
        StringBuilder res = new StringBuilder();
        int carry = 0;
        while(i1>=0 || i2>=0){
            int sum = carry;
            if(i1>=0){
                sum += num1.charAt(i1--) - '0';
            }
            if(i2>=0){
                sum += num2.charAt(i2--) - '0';
            }

            carry = sum / 10;
            res.append(sum%10);
        }

        if(carry>0)
            res.append(carry);

        return res.reverse().toString();
    }
}

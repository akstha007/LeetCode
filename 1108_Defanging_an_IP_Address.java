/*
1108. Defanging an IP Address
https://leetcode.com/problems/defanging-an-ip-address/
By: Ashok Shrestha
*/
class Solution {
    public String defangIPaddr(String address) {
        StringBuilder res = new StringBuilder();
        for(int i=0;i<address.length();i++){
            if(address.charAt(i)=='.')
                res.append("[.]");
            else
                res.append(address.charAt(i));
        }
        
        return res.toString();
    }
}

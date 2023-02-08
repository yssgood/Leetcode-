class Solution {
    public String longestPalindrome(String s) {
        int start = 0, end = 0, max_ = 0; 
        boolean[][] dp = new boolean[s.length()][s.length()]; 
        for(int i = 0; i < s.length(); i++){
            for(int j  = 0; j <= i; j++){
                if(s.charAt(i) == s.charAt(j) && (i - j <= 2 || dp[j+1][i-1])){
                    dp[j][i] = true; 
                }
                if(dp[j][i] && max_ < i - j + 1){
                    start = j; 
                    end = i; 
                    max_ = i - j + 1; 
                }
            }
        }
        return s.substring(start, end + 1); 
    }
}
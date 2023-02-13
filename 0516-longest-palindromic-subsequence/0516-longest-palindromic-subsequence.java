class Solution {
    public int longestPalindromeSubseq(String s) {
        int[][] dp = new int[s.length()][s.length()]; 
        // int answer = 1; 
        // for(int i = 0;  i < s.length(); i++){
        //     dp[i][i] = 1; 
        //     for(int j = 0; j < i; j++){
        //         if(s.charAt(i) == s.charAt(j)){
        //             dp[j][i] = dp[j+1][i-1] + 2; 
        //         }
        //         else{
        //             dp[j][i] = Math.max(dp[j+1][i], dp[j][i-1]); 
        //         }
        //         answer = Math.max(answer,dp[j][i]); 
        //     }
        // }
        for(int i = s.length()-1; i >= 0; i--){
            dp[i][i] = 1; 
            for(int j = i+1; j < s.length(); j++){
                if(s.charAt(i) == s.charAt(j)){
                    dp[i][j] = dp[i+1][j-1] + 2; 
                }
                else{
                    dp[i][j] = Math.max(dp[i+1][j], dp[i][j-1]); 
                }
            }
        }
        // for(int i = 0; i < s.length(); i++){
        //     for(int j = 0; j < s.length(); j++){
        //         System.out.print(dp[i][j]); 
        //         System.out.print(' '); 
        //     }
        //     System.out.println(); 
        // }
        return dp[0][s.length()-1]; 
    }
}
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        boolean[] dp = new boolean[s.length()+1]; 
        dp[0] = true; 
        Set<String> newSet = new HashSet<>(); 
        newSet.addAll(wordDict); 
        
        for(int i = 1; i <= s.length(); i++){
            for(String words : newSet){
                if(i < words.length()) continue; 
                if(dp[i - words.length()] && newSet.contains(s.substring(i - words.length(), i))){
                    dp[i] = true; 
                }
            }
        }
        
        
        return dp[s.length()]; 
    }
}


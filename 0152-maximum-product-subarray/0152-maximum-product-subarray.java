class Solution {
    public int maxProduct(int[] nums) {
        int[] dp = new int[nums.length]; 
        int[] min_dp = new int[nums.length]; 
        dp[0] = nums[0]; 
        min_dp[0] = nums[0]; 
        
        for(int i = 1; i < nums.length; i++){
            int tmp = dp[i-1]; 
            dp[i] = Math.max(nums[i],Math.max(dp[i-1] * nums[i],min_dp[i-1] * nums[i])); 
            min_dp[i] = Math.min(Math.min(tmp * nums[i], min_dp[i-1] * nums[i]), nums[i]);
        }

        return Collections.max(Arrays.stream(dp).boxed().toList());
    }
}
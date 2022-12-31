class Solution {
    public int maxSubArray(int[] nums) {
        int[] dp = new int[nums.length]; 
        dp[0] = nums[0]; 
        for(int i = 1; i < nums.length; i++){
            dp[i] = Math.max(nums[i],dp[i-1] + nums[i]); 
        }
        
        return Collections.max(Arrays.asList(Arrays.stream(dp).boxed().toArray(Integer[]::new))); 
    }
}
//더했을때 Max값 
//그냥 혼자서의 Max 값 
class Solution {
    public void dfs(List<List<Integer>> answer, List<Integer> container, int[] nums, int index){
        answer.add(new ArrayList(container)); 
        for(int i = index; i < nums.length; i++){
            container.add(nums[i]);
            dfs(answer, container, nums, i + 1);
            container.remove(container.size()-1); 
        }
    }
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> answer = new ArrayList(); 
        List<Integer> container = new ArrayList<>(); 
        dfs(answer, container, nums, 0); 
        return answer; 
    }
}
class Solution {
public:
    void dfs(vector<int>& nums, vector<vector<int>>& answer, vector<int>& container, int index){
        answer.push_back(container); 
        for(int i = index; i < nums.size(); i++){
            container.push_back(nums[i]); 
            dfs(nums,answer,container,i+1);
            container.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<int> container; 
        dfs(nums,answer,container,0); 
        return answer; 
    }
};
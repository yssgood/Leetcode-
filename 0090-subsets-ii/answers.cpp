class Solution {
public:
    void dfs(vector<int>& container, vector<vector<int>>& answer, vector<int>& nums, int index){
        answer.push_back(container); 
        for(int i = index; i < nums.size(); ++i){
            if(i>index && nums[i-1] == nums[i]) continue; 
            container.push_back(nums[i]); 
            dfs(container,answer,nums,i+1);
            container.pop_back(); 
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> container; 
        vector<vector<int>> answer; 
        sort(nums.begin(),nums.end()); 
        dfs(container,answer,nums,0);
        
        return answer; 
    }
};

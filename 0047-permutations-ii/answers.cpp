class Solution {
public:
    void dfs(vector<vector<int>>& answer, vector<bool>& visited, vector<int>& container, vector<int>& nums, int index){
        if(container.size() == nums.size()){
            answer.push_back(container);
            return; 
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(i > 0 && nums[i] == nums[i-1] && !visited[i-1]) continue; 
            else if(!visited[i]){
                visited[i] = true; 
                container.push_back(nums[i]); 
                dfs(answer,visited,container,nums,index);
                visited[i] = false; 
                container.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<bool> visited(nums.size(),false); 
        vector<int> container; 
        sort(nums.begin(),nums.end()); 
        dfs(answer,visited,container,nums,0); 
        
        return answer; 
    }
};

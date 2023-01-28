class Solution {
    void dfs(vector<vector<int>>& answer, vector<int>& container, vector<int>& nums, vector<bool>& visited, int depth){
        
        if(depth == nums.size()){
            answer.push_back(container);
            return; 
        }
        
        
        for(int i = 0; i < nums.size(); ++i){
            if(!visited[i]){
                visited[i] = true;
                container.push_back(nums[i]); 
                dfs(answer,container,nums,visited,depth+1); 
                visited[i] = false; 
                container.pop_back(); 
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answer; 
        vector<int> container; 
        vector<bool> visited(nums.size(),false); 
        
        dfs(answer,container,nums,visited,0); 
        
        
        return answer; 
    }
};

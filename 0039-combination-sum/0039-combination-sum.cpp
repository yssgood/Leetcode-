class Solution {
public:
    void dfs(vector<int>& container, vector<vector<int>>& answer, vector<int>& candidates, int target, int index){
        if(target <= 0){
            if(target == 0) answer.push_back(container); 
            return; 
        }

        for(int i = index; i < candidates.size(); i++){
            container.push_back(candidates[i]); 
            dfs(container, answer, candidates, target - candidates[i], i); 
            container.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer; 
        vector<int> container; 
        dfs(container, answer, candidates, target, 0); 

        return answer;       
    }
};
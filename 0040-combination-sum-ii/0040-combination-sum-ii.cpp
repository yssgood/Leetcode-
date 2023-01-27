class Solution {
// 1 1 2 5 6 7 10
public:
    void dfs(vector<int>& candidates, vector<vector<int>>& answer, int target, vector<int>& container, int index){
        if(target == 0){
            answer.push_back(container); 
            return; 
        }
        for(int i = index; i < candidates.size(); ++i){
            if(target < candidates[i]) return; 
            if(i && candidates[i] == candidates[i-1] && i > index) continue; 
            container.push_back(candidates[i]); 
            dfs(candidates,answer,target-candidates[i],container,i+1);
            container.pop_back(); 
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> container;
        vector<vector<int>> answer; 
        sort(candidates.begin(),candidates.end());
        
        dfs(candidates,answer,target,container,0); 
        
        return answer; 
    }
};

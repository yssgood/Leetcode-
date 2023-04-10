class Solution {
public:
    void dfs(vector<vector<int>>& adj, map<int,int>& hashMap, vector<int>& answer, int kill,vector<int>& pid){
        answer.push_back(kill); 
        for(int n : adj[hashMap[kill]]){ 
            dfs(adj,hashMap,answer,pid[n],pid); 
        }
    }
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        map<int,int> hashMap; 
        for(int i = 0; i < pid.size(); i++){
            hashMap[pid[i]] = i; 
        }
        vector<vector<int>> adj(pid.size()); 
        for(int i = 0; i < pid.size(); i++){
            if(hashMap.count(ppid[i])) adj[hashMap[ppid[i]]].push_back(hashMap[pid[i]]); 
        }
        vector<int> answer; 
        dfs(adj,hashMap,answer,kill,pid); 
        //for(int n : answer) cout << n << ' '; 
        return answer; 
    }
};

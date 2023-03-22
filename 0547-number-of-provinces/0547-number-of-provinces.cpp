class Solution {
public:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int node){
        visited[node] = true;
        for(int n : adj[node]){
            if(!visited[n]) dfs(adj,visited,n); 
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected.size(),vector<int>()); 
        vector<bool> visited(isConnected.size(),false); 
        int answer = 0; 
        for(int i = 0; i < isConnected.size(); i++){
            for(int j = 0; j < isConnected[i].size(); j++){
                if(i == j) continue;
                if(isConnected[i][j] == 1) adj[i].push_back(j); 
            }
        }
        
        for(int i = 0; i < isConnected.size(); i++){
            if(!visited[i]){
                answer++;
                dfs(adj,visited,i); 
            }
        }
        
        return answer; 
    }
};
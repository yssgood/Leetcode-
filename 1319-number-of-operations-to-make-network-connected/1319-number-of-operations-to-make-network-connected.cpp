class Solution {
    int answer = 0; 
public:
    void dfs(vector<vector<int>>& adj, vector<vector<int>>& connections, vector<bool>& visited, int index){
        visited[index] = true; 
        for(int& n: adj[index]){
            if(!visited[n]){
                visited[n] = true; 
                answer--; 
                dfs(adj,connections,visited,n); 
            }
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1; 
        vector<vector<int>> adj(n,vector<int>()); 
        answer = n-1; 
        for(vector<int>& v: connections){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]); 
        }
        vector<bool> visited(n,false); 
        for(int i = 0; i < n; i++){
            dfs(adj,connections,visited,i); 
        }
        return answer; 
    }
};
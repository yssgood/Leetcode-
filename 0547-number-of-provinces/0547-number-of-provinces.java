class Solution {
    public void dfs(List<Integer>[] adj, boolean[] visited, int node){
        visited[node] = true; 
        for(Integer n : adj[node]){
            if(!visited[n]) dfs(adj,visited,n); 
        }
    }
    public int findCircleNum(int[][] isConnected) {
        List<Integer>[] adj = new List[isConnected.length]; 
        boolean[] visited = new boolean[isConnected.length]; 
        int answer = 0; 
        for(int i = 0; i < isConnected.length; i++){
            adj[i] = new ArrayList<>(); 
        }
        
        for(int i = 0; i < isConnected.length; i++){
            for(int j = 0; j < isConnected[i].length; j++){
                if(i == j) continue; 
                if(isConnected[i][j] == 1) adj[i].add(j); 
            }
        }
        
        for(int i = 0; i < isConnected.length; i++){
            if(!visited[i]){
                answer++; 
                dfs(adj, visited, i); 
            }
        }
        
        return answer; 
    }
}
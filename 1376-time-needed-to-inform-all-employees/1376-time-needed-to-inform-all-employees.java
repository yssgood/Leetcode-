class Solution {
    int answer = 0; 

    public void dfs(int node, List<Integer>[] graph, int[] manager, int[] informTime, boolean[] visited, int cnt){
        cnt += informTime[node]; 
        answer = Math.max(answer,cnt); 
        for(int n : graph[node]){
            if(!visited[n]){
                visited[n] = true; 
                dfs(n,graph,manager,informTime,visited,cnt); 
            }
        }
    }
    public int numOfMinutes(int n, int headID, int[] manager, int[] informTime) {
        boolean[] visited = new boolean[n]; 
        List<Integer>[] graph = new List[n]; 
        for(int i = 0; i < n; i++) graph[i] = new ArrayList<>(); 
        for(int i = 0; i < manager.length; i++){
            if(manager[i] == -1) continue; 
            graph[i].add(manager[i]); 
            graph[manager[i]].add(i); 
        }
        visited[headID] = true; 
        //answer += informTime[headID]; 
        //int cnt = informTime[headID]; 
        dfs(headID,graph,manager,informTime,visited,0); 
        return answer; 
    }
}
class Solution {
public:
    void dfs(unordered_map<string,multiset<string>>& adj, vector<string>& answer, string s){
        while(adj[s].size()){
            string v = *(adj[s].begin());
            adj[s].erase(adj[s].begin()); 
            dfs(adj,answer,v); 
        }
        answer.push_back(s); 
        
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>> adj; 
        vector<string> answer; 
        for(vector<string>& t: tickets){
            adj[t[0]].insert(t[1]); 
        }
        dfs(adj,answer,"JFK"); 
        reverse(answer.begin(),answer.end()); 
        
        return answer; 
    }
};
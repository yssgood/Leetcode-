class Solution {

vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};  

public:
    void dfs(int i, int j, vector<vector<bool>>& visited, vector<vector<int>>& heights){
        if(i < 0 || j < 0 || i >= heights.size() || j >= heights[0].size() || visited[i][j]) return; 
        visited[i][j] = true; 
        for(pair<int,int>& p : dir){
            int nX = i + p.first;
            int nY = j + p.second; 
            if(nX >= 0 && nY >= 0 && nX < heights.size() && nY < heights[0].size() && heights[nX][nY] >= heights[i][j]){
                dfs(nX,nY,visited,heights); 
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> answer; 
        vector<vector<bool>> pVisited(heights.size(), vector<bool>(heights[0].size(),false)); 
        vector<vector<bool>> aVisited(heights.size(), vector<bool>(heights[0].size(),false)); 
        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[i].size(); j++){
                if(i == 0 || j == 0) dfs(i,j,pVisited,heights); 
                if(i == heights.size()-1 || j == heights[0].size()-1) dfs(i,j,aVisited,heights); 
            }
        }

        for(int i = 0; i < heights.size(); i++){
            for(int j = 0; j < heights[i].size(); j++){
                if(pVisited[i][j] && aVisited[i][j]) answer.push_back({i,j}); 
            }
        }

        return answer; 
    }
};
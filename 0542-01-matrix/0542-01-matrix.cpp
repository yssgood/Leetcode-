class Solution {

vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
struct Node{
    int x, y, dist; 
};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        vector<vector<int>> matrix(mat.size(), vector<int>(mat[0].size(),0)); 
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat[0].size(), false)); 

        queue<Node> q; 

        for(int i = 0; i < mat.size(); i++){
            for(int j = 0; j < mat[0].size(); j++){
                if(mat[i][j] == 0){
                    q.push({i,j,0}); 
                    visited[i][j] = true; 
                }
            }
        }

        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Node node = q.front();
                q.pop(); 
                
                int x = node.x, y = node.y, dist = node.dist; 

                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nY < 0 || nX >= mat.size() || nY >= mat[0].size() || visited[nX][nY]) continue; 

                    visited[nX][nY] = true; 
                    matrix[nX][nY] = dist + 1; 
                    q.push({nX,nY,dist+1}); 
                }
            }
        }

        return matrix; 

    }
};
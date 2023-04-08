class Solution {
    struct Node{
        int x, y, dist; 
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 

public:
    void bfs(int i, int j, vector<vector<int>>& rooms){
        queue<Node> q; 
        q.push({i,j,0}); 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Node node = q.front();
                q.pop(); 
                int x = node.x, y = node.y, dist = node.dist; 
                for(pair<int,int>& p : dir){
                    int nX = x + p.first;
                    int nY = y + p.second; 

                    if(nX < 0 || nX >= rooms.size() || nY < 0 || nY >= rooms[0].size() || rooms[nX][nY] == -1) continue; 

                    if(rooms[nX][nY] > dist + 1){
                        rooms[nX][nY] = dist + 1; 
                        q.push({nX,nY,dist+1}); 
                    }
                }
            }
        }
    }
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        for(int i = 0; i < rooms.size(); i++){
            for(int j = 0; j < rooms[i].size(); j++){
                if(rooms[i][j] == 0){
                    bfs(i,j,rooms); 
                }
            }
        }
    }
};

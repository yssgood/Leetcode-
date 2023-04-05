class Solution {
    struct Ball{
        int x,y;
    };
    vector<pair<int,int>> dir = {{0,1},{0,-1},{1,0},{-1,0}}; 
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        bool visited[maze.size()][maze[0].size()]; 
        memset(visited,false,sizeof(visited)); 
        queue<Ball> q; 
        q.push({start[0],start[1]}); 
        visited[start[0]][start[1]] = true; 
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                Ball first = q.front(); 
                q.pop(); 
                int x = first.x, y = first.y;
                if(x == destination[0] && y == destination[1]) return true; 
                for(pair<int,int>& p  : dir){
                    int nX = x, nY = y; 
                    while(nX  >= 0 && nX  < maze.size() && nY >= 0 && nY < maze[0].size() && maze[nX][nY] != 1){
                        nX += p.first;
                        nY += p.second; 
                    }
                    cout << nX << ' ' << nY << endl; 
                    nX -= p.first;
                    nY -= p.second; 
                    if(visited[nX][nY]) continue; 
                    visited[nX][nY] = true; 
                    q.push({nX,nY}); 
                }
            }
        }
        return false; 
    }
};



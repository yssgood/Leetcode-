class Solution {
public:
    void turnZero(int x, int y, map<pair<int,int>,int>& hashMap, vector<vector<int>>& matrix){
        
        for(int j = y; j < matrix[0].size(); j++){
            //if(y != j && hashMap.count({x,j})) break; 
            matrix[x][j] = 0; 
            hashMap[{x,j}]++; 
        }
        
        for(int j = y; j >= 0; j--){
            //if(y != j && hashMap.count({x,j})) break; 
            matrix[x][j] = 0; 
            hashMap[{x,j}]++; 
        }
        for(int i = x; i < matrix.size(); i++){
            //if(x != i && hashMap.count({i,y})) break; 
            matrix[i][y] = 0; 
            hashMap[{i,y}]++; 
        }
        for(int i = x; i >= 0; i--){
            //if(x != i && hashMap.count({i,y})) break; 
            matrix[i][y] = 0;
            hashMap[{i,y}]++; 
        }
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        map<pair<int,int>,int> hashMap; 
        vector<pair<int,int>> container; 
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0; j < matrix[i].size(); j++){
                if(matrix[i][j] == 0) container.push_back({i,j}); 
            }
        }
        
        for(pair<int,int>& p : container){
            turnZero(p.first,p.second,hashMap,matrix); 
        }
    }
};

// [[1,0,3,4],
//  [0,0,0,0],
//  [0,0,11,0],
//  [0,0,0,0]]
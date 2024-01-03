class Solution {
vector<pair<int,int>> vp; 
public: 
    void turnZero(vector<vector<int>>& matrix, int x, int y){
        int top = 0, left = 0, right = matrix[0].size()-1, bottom = matrix.size()-1; 

        for(int i = x; i >= top; i--){
            matrix[i][y] = 0; 
        }

        for(int i = x; i <= bottom; i++){
            matrix[i][y] = 0; 
        }

        for(int j = y; j <= right; j++){
            matrix[x][j] = 0; 
        }

        for(int j = y; j >= left; j--){
            matrix[x][j] = 0; 
        }
        
    }

public:
    void setZeroes(vector<vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); i++){
            for(int j = 0;j < matrix[i].size(); j++){
                if(matrix[i][j] == 0){
                    vp.push_back({i,j}); 
                }
            }
        }

        for(pair<int,int>& p : vp){
            turnZero(matrix,p.first,p.second); 
        }

    }
};
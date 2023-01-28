class Solution {
    map<string,vector<int>> dp; 
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> result; 
        
        for(int i = 0; i < expression.size(); i++){
            char exp = expression[i]; 
            
            if(exp == '*' || exp == '+' || exp == '-'){
                
                string findNum = expression.substr(0,i); 
                vector<int> left; 
                if(dp.count(findNum)){
                    cout << findNum << ' '; 
                    left = dp[findNum]; 
                }
                else
                    left = diffWaysToCompute(findNum); 
                
                string findNum2 = expression.substr(i+1); 
                vector<int> right; 
                if(dp.count(findNum2)) right = dp[findNum2];
                else
                    right = diffWaysToCompute(findNum2); 
                
                for(int& n1: left){
                    for(int& n2: right){
                        if(exp == '+') result.push_back(n1 + n2);
                        if(exp == '-') result.push_back(n1 - n2); 
                        if(exp == '*') result.push_back(n1 * n2); 
                    }
                }
            }
        }
        
        if(result.empty()) result.push_back(stoi(expression)); 
        dp[expression] = result; 
        //dp["2"] = {2}; 
        //dp[]
        return result; 
    }
};

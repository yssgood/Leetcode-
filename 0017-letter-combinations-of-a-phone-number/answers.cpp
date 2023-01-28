class Solution {
public:
    void dfs(string digits,vector<string>&answer, string add, int index,unordered_map<char,string>& hashMap){
        if(add.length() == digits.length()){
            answer.push_back(add);
            return; 
        }
        for(int i = 0; i < hashMap[digits[index]].length(); ++i){
            add += hashMap[digits[index]][i]; 
            dfs(digits,answer,add,index+1,hashMap);
            add.pop_back(); 
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> answer; 
        if(digits.length() < 1) return answer; 
        unordered_map<char,string> hashMap; 
        hashMap = {{'2',"abc"},{'3',"def"},{'4',"ghi"},{'5',"jkl"},{'6',"mno"},{'7',"pqrs"},{'8',"tuv"},{'9',"wxyz"},};
        string add = ""; 
        dfs(digits,answer,add,0,hashMap); 
        return answer; 
    }
};

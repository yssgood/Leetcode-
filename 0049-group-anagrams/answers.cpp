class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> container; 
        vector<vector<string>> answer; 
        unordered_map<string,vector<string>> hashmap; 
        vector<string> strCopy = strs; 
        for (auto& i: strCopy){
            sort(i.begin(),i.end());
        }
        for (int i = 0; i < strs.size(); ++i){
            hashmap[strCopy[i]].push_back(strs[i]);
        }
        
        for(auto vecs: hashmap){
            for (auto elem: vecs.second){
                container.push_back(elem);
            }
            answer.push_back(container);
            container.clear(); 
        }
        return answer; 
    }
};

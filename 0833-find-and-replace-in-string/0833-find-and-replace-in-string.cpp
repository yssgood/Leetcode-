class Solution {
public:
    bool match(const string& s, int num_s, int idx, const string& t, int num_t) {
        int i = idx;
        int j = 0;
        while(i < num_s && j < num_t && s[i] == t[j]) {
            i++;
            j++;
        }
        return j == num_t;
    } 
    string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {

        map<int, pair<int, string>> ids;
        int num_s = s.size();
        for (int i = 0; i < indices.size(); i++) {
            if (match(s, num_s, indices[i], sources[i], sources[i].size()))
                ids[indices[i]] = make_pair(sources[i].size(), targets[i]);
        }
        
        int i = 0;
        string result;
        while(i < num_s) {
          if (ids.find(i) != ids.end()) {
              result += ids[i].second;
              i += ids[i].first;
          } else {
              result.push_back(s[i]);
              i++;
          }
        }

        return result;
     }
};
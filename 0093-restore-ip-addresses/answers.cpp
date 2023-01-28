class Solution { //copy paste
public:
    vector<string> restoreIpAddresses(string s) {
        size = s.size();
        helper(s, 0, 0);
        return ret;
    }
private:
    int size;
    vector<string> ret;
    vector<string> path;
    void helper(string& s, int idx, int count) {
        if(idx == size && count == 4) {
            string tmp; for(auto& p : path) tmp += p + "."; tmp.pop_back();
            ret.push_back(tmp);
            return;
        }
        if(count > 4) return;
        for(int len = 1; len<=3 && len+idx-1<size; len++){
            string tmp = s.substr(idx, len);
            int val = stoi(tmp);
            if(val > 255 || (tmp.size()>1 && tmp[0] == '0')) continue;
            path.push_back(tmp);
            helper(s, len+idx, count+1);
            path.pop_back();
        }
    }
};

class Solution {
    struct Lock{
        string initial;
        int operations; 
    };
public:
    int openLock(vector<string>& deadends, string target) {
        queue<Lock> q; 
        map<string,int> hashMap; 
        for(string& s : deadends){
            if(s == "0000") return -1; 
            hashMap[s]++; 
        }
        q.push({"0000",0}); 
        hashMap["0000"] = 1; 
        //cout << (char)('0' + 1); 
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Lock first = q.front(); 
                q.pop(); 
                string init = first.initial; 
                int dist = first.operations; 
                if(init == target) return dist; 
                for(int j = 0; j < 4; j++){
                    string a = init, b = init; 
                    a[j] = (char)(a[j] - '0' + 1) % 10 + '0'; 
                    b[j] = (char)(b[j] - '0' - 1 + 10) % 10 + '0'; 
                    if(!hashMap.count(a)){
                        //cout << a << ' '; 
                        q.push({a,dist+1}); 
                        hashMap[a]++; 
                    }
                    if(!hashMap.count(b)){
                        //cout << b << endl; 
                        q.push({b,dist+1}); 
                        hashMap[b]++; 
                    }
                }
            }
        }
        return -1; 
    }
};

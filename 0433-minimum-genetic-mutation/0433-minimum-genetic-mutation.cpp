class Solution {
    struct Items{
        string gene; 
        int dist; 
    };
    
public:
    bool check(string&a , string& b){
        int cnt = 0; 
        for(int i = 0; i < b.length(); i++){
            if(a[i] != b[i]) ++cnt; 
            if(cnt > 1) return false; 
        }
        return true; 
    }
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        if(startGene == endGene) return 0; 
        map<string,int> hashMap; 
        queue<Items> q; 
        q.push({startGene,0}); 
        
        while(!q.empty()){
            int size = q.size(); 
            for(int i = 0; i < size; i++){
                Items first = q.front();
                q.pop(); 
                string gene = first.gene; 
                int dist = first.dist; 
                
                if(gene == endGene) return dist; 
                
                for(string& s : bank){
                    if(!hashMap.count(s) && check(gene,s)){
                        q.push({s,dist+1}); 
                        hashMap[s]++; 
                    }
                }
            }
        }
        return -1; 
    }
};
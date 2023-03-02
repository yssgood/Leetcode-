class Solution {
    HashMap<String,Integer> hashMap = new HashMap<>(); 
    int mx_ = 0; 
    public void dfs(int index, String s){
        if(index >= s.length()){
            mx_ = Math.max(mx_, hashMap.size()); 
        }
        
        for(int i = index; i < s.length(); i++){
            String ex = s.substring(index,i+1); 
            if(!hashMap.containsKey(ex)){
                hashMap.put(ex,1); 
                dfs(index + (ex.length()),s); 
                hashMap.remove(ex); 
            }
        }
    }
    public int maxUniqueSplit(String s) {
        dfs(0,s); 
        return mx_; 
    }
}
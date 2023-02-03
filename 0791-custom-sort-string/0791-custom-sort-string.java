class Solution {
    public String customSortString(String order, String s) {
        HashMap<Character,Integer> hashMap = new HashMap<Character,Integer>(); 
        for(int i = 0; i < order.length(); i++){
            hashMap.put(order.charAt(i),i); 
        }
        
        List<Character> lst = new LinkedList<>(); 
        for(char c : s.toCharArray()){
            if(hashMap.containsKey(c)) lst.add(c); 
        }
        
        Collections.sort(lst,(a,b)->{
            return hashMap.get(a) - hashMap.get(b);
        });
        
        StringBuilder sb = new StringBuilder(); 
        for(char c : lst){
            sb.append(c); 
        }
        
        for(char c : s.toCharArray()){
            if(!hashMap.containsKey(c)){
                sb.append(c); 
            }
        }
        
        return sb.toString(); 
    }
}
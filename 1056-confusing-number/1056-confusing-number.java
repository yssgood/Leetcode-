class Solution {
    public boolean confusingNumber(int n) {
        HashMap<Character, Character> hashMap = new HashMap<Character, Character>(){{
            put('0','0'); 
            put('1','1'); 
            put('6','9'); 
            put('8','8'); 
            put('9','6'); 
        }};
        StringBuilder sb = new StringBuilder(); 
        sb.append(n); 

        StringBuilder tmp = new StringBuilder(); 
        for(int k = sb.length()-1; k >= 0; k--){
            if(!hashMap.containsKey(sb.charAt(k))) return false; 
            Character newC = hashMap.get(sb.charAt(k)); 
            tmp.append(newC); 
        }

        int newN = Integer.valueOf(tmp.toString()); 
        return n != newN; 
    }
}
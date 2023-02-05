class Solution {
    public int strStr(String haystack, String needle) {
        for(int i = 0; i <= haystack.length() - needle.length(); i++){
            if(haystack.charAt(i) == needle.charAt(0)){
                 //haystack.substring(i,i + needle.length()) == haystack) return i; 
                //System.out.println(haystack.substring(i, i + needle.length())); 
                if(haystack.substring(i, i + needle.length()).equals(needle)) return i; 
            }
        }
        return -1; 
    }
}
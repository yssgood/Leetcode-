class Solution {
    public List<Integer> findAnagrams(String s, String p) {
        HashMap<Character,Integer> hashMap = new HashMap<>(); 
        HashMap<Character,Integer> hashMap2 = new HashMap<>(); 
        List<Integer> container = new ArrayList<>(); 
        for(int i = 0; i < p.length(); i++) hashMap.put(p.charAt(i),hashMap.getOrDefault(p.charAt(i),0)+1); 
        for(int i = 0; i < p.length() && i < s.length(); i++) hashMap2.put(s.charAt(i),hashMap2.getOrDefault(s.charAt(i),0)+1); 
        //System.out.print(hashMap.get('a'));
        //System.out.println(hashMap2.get('a'));
        if(hashMap.equals(hashMap2)) container.add(0); 
        for(int i = p.length(); i < s.length(); i++){
            hashMap2.put(s.charAt(i),hashMap2.getOrDefault(s.charAt(i),0)+1); 
            hashMap2.put(s.charAt(i - p.length()),hashMap2.getOrDefault(s.charAt(i - p.length()),0)-1); 
            if(hashMap2.get(s.charAt(i - p.length())) == 0)hashMap2.remove(s.charAt(i - p.length())); 
            //System.out.print(hashMap.get('a'));
            //System.out.println(hashMap2.get('a'));
            if(hashMap.equals(hashMap2)) container.add(i - p.length() +1); 
        }
        
        return container; 
    }
}
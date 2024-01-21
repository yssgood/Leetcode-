class Solution {
    public int longestConsecutive(int[] nums) {
        int answer = 0;
        Map<Integer, Integer> hashMap = new TreeMap<>();

        for (int n : nums) {
            if (!hashMap.containsKey(n)) {
                hashMap.put(n, 1);
            }
        }

        for (int key : hashMap.keySet()) {
            System.out.println(key);
            if (hashMap.containsKey(key - 1)) {
                //System.out.println(key);
                hashMap.put(key, hashMap.get(key) + hashMap.get(key - 1));
            }
        }

        for (int value : hashMap.values()) {
            answer = Math.max(answer, value);
        }

        return answer;
    }
}
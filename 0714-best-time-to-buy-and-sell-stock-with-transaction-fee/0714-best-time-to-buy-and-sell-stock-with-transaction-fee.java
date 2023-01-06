class Solution {
    public int maxProfit(int[] p, int fee) {
        int n = p.length;
        if (n < 2) return 0;
        int[] hold = new int[n];
        int[] sold = new int[n];
        hold[0] = -p[0];
        for (int i = 1; i < n; ++i) {
            hold[i] = Math.max(hold[i - 1], sold[i - 1] - p[i]);
            sold[i] = Math.max(sold[i - 1], hold[i - 1] + p[i] - fee);
        }

        return sold[n - 1];
    }
}
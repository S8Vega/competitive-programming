class Solution {
    private static final int N = 2010;
    private int n;
    private int []stones;
    Map<Integer, Boolean> dp[] = new HashMap[N];

    private void init() {
        for (int i = 0; i < N; i++) {
            dp[i] = new HashMap<>();
        }
    }

    private boolean f(int i, int j) {
        if (i == n - 1) return true;
        if (dp[i].containsKey(j)) return dp[i].get(j);
        boolean ans = false;
        for (int curr = i + 1;curr < n; curr++) {
            if (stones[i] + j + 1 < stones[curr]) {
                break;
            }
            if (stones[i] + j == stones[curr]) ans |= f(curr, stones[curr] - stones[i]);
            if (stones[i] + j  + 1 == stones[curr]) ans |= f(curr, stones[curr] - stones[i]);
            if (stones[i] + j  - 1 == stones[curr]) ans |= f(curr, stones[curr] - stones[i]);
        }
        dp[i].put(j, ans);
        return dp[i].get(j);
    }

    public boolean canCross(int[] stones) {
        init();
        this.stones = stones;
        this.n = stones.length;
        return f(0, 0);
    }
}
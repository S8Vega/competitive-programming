class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int ans = 0;
        int spaces = 0;
        char[] movesChar = moves.toCharArray();
        for (char c: movesChar) {
            if (c == '_') spaces++;
            else if (c == 'R') ans++;
            else ans--;
        }
        if (ans < 0) ans -= spaces;
        else ans += spaces;
        return Math.abs(ans);
    }
}
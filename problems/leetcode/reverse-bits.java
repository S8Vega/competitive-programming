public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        int[] bits = new int[32];
        for (int i = 0; i < 32; i++) {
            bits[i] = (n & (1 << i)) != 0 ? 1 : 0;
        }

        for (int i = 0; i < 16; i++) {
            int temp = bits[i];
            bits[i] = bits[31 - i];
            bits[31 - i] = temp;
        }

        int reversedNumber = 0;
        for (int i = 0; i < 32; i++) {
            reversedNumber += bits[i] << i;
        }

        return (reversedNumber);
    }
}
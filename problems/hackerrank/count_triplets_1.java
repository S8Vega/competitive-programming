import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class count_triplets_1 {

    static long n;
    static long k;
    static long[] arr;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        n = in.nextLong();
        k = in.nextLong();
        arr = new long[(int) n];
        for (int i = 0; i < n; i++) {
            arr[i] = in.nextLong();
        }
        long ans = 0;
        Map<Long, Long> l, r;
        l = new HashMap<>();
        r = new HashMap<>();
        for (int i = 0; i < n; i++) {
            r.put(arr[i], (r.containsKey(arr[i]) ? r.get(arr[i]) + 1 : 1));
        }
        long valL, valR;
        for (int i = 0; i < n; i++) {
            r.put(arr[i], r.get(arr[i]) - 1);
            if (arr[i] % k == 0L) {
                valL = l.containsKey(arr[i] / k) ? l.get(arr[i] / k): 0;
                valR = r.containsKey(arr[i] * k) ? r.get(arr[i] * k): 0;
                ans += valL * valR;
            }
            l.put(arr[i], (l.containsKey(arr[i]) ? l.get(arr[i]) + 1 : 1));
        }
        System.out.println(ans);
    }
}
